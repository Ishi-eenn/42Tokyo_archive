#!/bin/bash

set -eo pipefail
shopt -s nullglob

_is_sourced() {
  [ "${#FUNCNAME[@]}" -ge 2 ] \
    && [ "${FUNCNAME[0]}" = '_is_sourced' ] \
    && [ "${FUNCNAME[1]}" = 'source' ]
}

# ====== ここで環境変数のデフォルトを定義（.env や compose で上書き可）======
: "${DB_HOST:=inception_mariadb}"
: "${DB_NAME:=wordpress}"
: "${DB_USER:=wpuser}"
: "${WP_TITLE:=inception}"
: "${WP_ADMIN:=admin}"
: "${WP_ADMIN_EMAIL:=admin@admin.com}"
: "${WP_USER:=editor}"
: "${WP_USER_EMAIL:=editor@example.com}"
: "${WP_URL:=https://tsishika.42.fr}"   # ← 必要に応じて .env で上書き
: "${WP_LOCALE:=ja}"
: "${WP_TABLE_PREFIX:=wp_}"

change_directory() {
  if [ ! -d "/var/www/html" ]; then
    echo "Creating /var/www/html directory..."
    mkdir -p /var/www/html
  fi
  cd /var/www/html
  chown -R www-data:www-data /var/www/html
}

input_env() {
  # secrets で上書き
  if [ -f /run/secrets/db_user_password ]; then
    DB_USER_PASS="$(cat /run/secrets/db_user_password)"
  fi
  if [ -f /run/secrets/wp_admin_password ]; then
    WP_ADMIN_PASS="$(cat /run/secrets/wp_admin_password)"
  fi
  if [ -f /run/secrets/wp_user_password ]; then
    WP_USER_PASS="$(cat /run/secrets/wp_user_password)"
  fi

  # 必須チェック
  : "${DB_USER_PASS:?DB_USER_PASS not set (use secret db_user_password or env)}"
  : "${WP_ADMIN_PASS:?WP_ADMIN_PASS not set (use secret wp_admin_password or env)}"
  : "${WP_USER_PASS:?WP_USER_PASS not set (use secret wp_user_password or env)}"
}

install_wp_cli() {
  if [ ! -x ./wp-cli.phar ]; then
    echo "Installing WP-CLI..."
    curl -fsSL -o wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
  fi
}

wait_for_db() {
  echo "Waiting for database at ${DB_HOST}..."
  for i in {1..60}; do
    if mysqladmin ping -h"${DB_HOST}" -u"${DB_USER}" -p"${DB_USER_PASS}" --silent >/dev/null 2>&1; then
      echo "Database is ready."
      return 0
    fi
    sleep 1
  done
  echo "ERROR: Database not reachable."
  exit 1
}

initialize_wordpress() {
  # 1) コア配置（冪等）
  if [ ! -f wp-includes/version.php ]; then
    echo "Downloading WordPress core..."
    sudo -u www-data ./wp-cli.phar core download --locale="${WP_LOCALE}" --allow-root
  fi

  # 2) wp-config（冪等）
  if [ ! -f wp-config.php ]; then
    echo "Creating wp-config.php..."
    sudo -u www-data ./wp-cli.phar config create \
      --dbname="${DB_NAME}" \
      --dbuser="${DB_USER}" \
      --dbpass="${DB_USER_PASS}" \
      --dbhost="${DB_HOST}" \
      --dbprefix="${WP_TABLE_PREFIX}" \
      --locale="${WP_LOCALE}" \
      --skip-check \
      --allow-root
    # 便利定数
    sudo -u www-data ./wp-cli.phar config set WP_HOME    "${WP_URL}" --type=constant --allow-root
    sudo -u www-data ./wp-cli.phar config set WP_SITEURL "${WP_URL}" --type=constant --allow-root
    sudo -u www-data ./wp-cli.phar config set WP_DEBUG false --type=constant --raw --allow-root
    sudo -u www-data ./wp-cli.phar config set FS_METHOD direct --type=constant --allow-root
  fi

  # 3) 初回インストール or 既存のURL更新
  if ! sudo -u www-data ./wp-cli.phar core is-installed --allow-root >/dev/null 2>&1; then
    echo "Installing WordPress..."
    sudo -u www-data ./wp-cli.phar core install \
      --url="${WP_URL}" \
      --title="${WP_TITLE}" \
      --admin_user="${WP_ADMIN}" \
      --admin_password="${WP_ADMIN_PASS}" \
      --admin_email="${WP_ADMIN_EMAIL}" \
      --skip-email \
      --allow-root
    sudo -u www-data ./wp-cli.phar option update timezone_string "Asia/Tokyo" --allow-root
    sudo -u www-data ./wp-cli.phar rewrite structure '/%postname%/' --hard --allow-root
  else
    CURRENT_URL="$(sudo -u www-data ./wp-cli.phar option get siteurl --allow-root || true)"
    if [ -n "${CURRENT_URL}" ] && [ "${CURRENT_URL}" != "${WP_URL}" ]; then
      echo "Updating site URL: ${CURRENT_URL} -> ${WP_URL}"
      sudo -u www-data ./wp-cli.phar option update siteurl "${WP_URL}" --allow-root
      sudo -u www-data ./wp-cli.phar option update home    "${WP_URL}" --allow-root
      # 既存コンテンツのURL置換（guid は除外）
      sudo -u www-data ./wp-cli.phar search-replace "${CURRENT_URL}" "${WP_URL}" --all-tables --skip-columns=guid --allow-root || true
    fi
  fi

  # 4) エディタユーザー作成（存在チェックしてから）
  if ! sudo -u www-data ./wp-cli.phar user get "${WP_USER}" --field=ID --allow-root >/dev/null 2>&1; then
    echo "Creating editor user: ${WP_USER}"
    sudo -u www-data ./wp-cli.phar user create "${WP_USER}" "${WP_USER_EMAIL}" \
      --role=editor \
      --user_pass="${WP_USER_PASS}" \
      --allow-root
  fi

  chown -R www-data:www-data /var/www/html
}

_main() {
  change_directory
  input_env
  install_wp_cli
  # ここを“並行実行”にする：DB待機→WP初期化はバックグラウンド
  ( wait_for_db && initialize_wordpress ) &
  # 先に FPM を前面起動（Nginx から 9000 に繋げるようにする）
  exec php-fpm7.4 -F
}


if ! _is_sourced; then
  _main
fi
