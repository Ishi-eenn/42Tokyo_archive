FROM debian:bullseye

RUN apt update && apt upgrade && apt install -y mariadb-server

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY init.sql /etc/mysql/init.sql
COPY docker-entrypoint.sh .

RUN mkdir /run/mysqld && chmod +x docker-entrypoint.sh

CMD ["./docker-entrypoint.sh"]
