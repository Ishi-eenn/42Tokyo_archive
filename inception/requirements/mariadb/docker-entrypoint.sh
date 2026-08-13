#!/bin/bash
set -euo pipefail

input_env() {
  # Docker secrets → 環境変数へ
  [[ -f /run/secrets/db_admin_password ]] && DB_ADMIN_PASS="$(cat /run/secrets/db_admin_password)"
  [[ -f /run/secrets/db_user_password  ]] && DB_USER_PASS="$(cat /run/secrets/db_user_password)"
}

require_env() {
  : "${DB_NAME:?DB_NAME is required}"
  : "${DB_USER:?DB_USER is required}"
  : "${DB_ADMIN:?DB_ADMIN is required}"
  : "${DB_USER_PASS:?DB_USER_PASS is required}"
  : "${DB_ADMIN_PASS:?DB_ADMIN_PASS is required}"
}

prepare_runtime() {
  # ソケット置き場を用意
  mkdir -p /run/mysqld
  chown -R mysql:mysql /run/mysqld
  chmod 775 /run/mysqld
}

initialize_db() {
  if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mysqld --initialize-insecure --user=mysql --datadir=/var/lib/mysql
    chown -R mysql:mysql /var/lib/mysql
  fi
}

start_mysqld_socket_only() {
  echo "Starting temporary mysqld (socket only, no networking)..."
  mysqld \
    --skip-networking \
    --socket=/run/mysqld/mysqld.sock \
    --datadir=/var/lib/mysql \
    --user=mysql &
  # 起動待ち
  for i in {1..30}; do
    if mysqladmin ping --protocol=SOCKET --socket=/run/mysqld/mysqld.sock --silent; then
      return 0
    fi
    sleep 1
  done
  echo "mysqld did not become ready in time"; exit 1
}

create_db_users() {
  echo "Creating database and users..."
  mysql --protocol=SOCKET --socket=/run/mysqld/mysqld.sock <<EOF
CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;

CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USER_PASS}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';

CREATE USER IF NOT EXISTS '${DB_ADMIN}'@'%' IDENTIFIED BY '${DB_ADMIN_PASS}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_ADMIN}'@'%';

FLUSH PRIVILEGES;
EOF
}

stop_temp_mysql() {
  echo "Shutting down temporary mysqld..."
  mysqladmin --protocol=SOCKET --socket=/run/mysqld/mysqld.sock shutdown
  # 念のため待機
  wait || true
}

start_mysqld_foreground() {
  echo "Starting mysqld in foreground..."
  # ここから先は PID1 を mysqld に置き換える
  exec mysqld --user=mysql --datadir=/var/lib/mysql --socket=/run/mysqld/mysqld.sock
  # 以降の行には到達しない
}

main() {
  input_env
  require_env
  prepare_runtime
  initialize_db
  start_mysqld_socket_only
  create_db_users
  stop_temp_mysql
  start_mysqld_foreground
}

main "$@"
