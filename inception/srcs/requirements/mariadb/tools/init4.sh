#!/bin/bash

# Allow remote connections and set port
sed -ie 's/bind-address/#bind-address/g' /etc/mysql/mariadb.conf.d/50-server.cnf
sed -ie 's/#port/port/g' /etc/mysql/mariadb.conf.d/50-server.cnf

# Check if database `mysql` has already been created
if [ ! -d "var/lib/mysql/mysql" ]; then
    # Initializes the MySQL database tables and creates the necessary files in the
    # specified data directory with the specified MySQL user and based directory.
    echo "Install mariadb for the first time"
    mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
fi

# Check if the database $WORDPRESS_DB_NAME has already been created
if [ ! -d /var/lib/mysql/$MYSQL_DATABASE ]
then
service mysql start

# Perform the mysql secure installation
mysql -u root << EOF
UPDATE mysql.user SET Password=PASSWORD('$MYSQL_ROOT_PASSWORD') WHERE User='root';
UPDATE mysql.user SET plugin='mysql_native_password' WHERE user='root' AND host='localhost';
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
FLUSH PRIVILEGES;
EOF

sleep 2
echo "user is set to: $MYSQL_USER"
echo userpw is set to: $MYSQL_USER_PASSWORD
echo db is set to: $MYSQL_DATABASE 
echo rootpw is set to: $MYSQL_ROOT_PASSWORD

echo "executed"
tail -f /dev/null
echo "not executed"

# Creates the project database if it doesn't exist
# and grants privileges to root and the project user
mysql -u root -p$MYSQL_ROOT_PASSWORD << EOF
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

service mysql stop
fi

mysqld_safe
