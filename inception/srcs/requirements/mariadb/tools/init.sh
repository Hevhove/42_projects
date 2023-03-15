# Add the port number
sed -ie 's/#port/port/g' /etc/mysql/mariadb.conf.d/50-server.cnf;
sed -ie 's/bind-address            = 127.0.0.1/bind-address            = 0.0.0.0/g' /etc/mysql/mariadb.conf.d/50-server.cnf

# Launch MySQL
service mysql start;

# Create databases
if test -d "/var/lib/mysql/${MYSQL_DATABASE}"; then 
    echo "Database $MYSQL_DATABASE has already been created!"
else
    echo "Setting up Database $MYSQL_DATABASE for the first time!"

    # Create the Database
    mysql -e "CREATE DATABASE ${MYSQL_DATABASE} /*\!40100 DEFAULT CHARACTER SET utf8 */;"
    sleep 1
    if [ $? -eq 0 ]; then
        echo "Database $MYSQL_DATABASE created!"
    else
        echo "Database $MYSQL_DATABASE failed to create!"
    fi

    # Create the User 
    mysql -e "CREATE USER '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';"
    sleep 1
    if [ $? -eq 0 ]; then
        echo "User $MYSQL_USER created!"
    else
        echo "User $MYQL_USER failed to create!"
    fi

    # Grant the user all privileges on the database tables
    mysql -e "GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'localhost';"
    mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_USER_PASSWORD}' WITH GRANT OPTION;"    
    sleep 1
    if [ $? -eq 0 ]; then
        echo "All privileges granted to user $MYSQL_USER !"
    else
        echo "Failed to extend privileges to user $MYSQL_USER"
    fi
    # Flush privileges
    mysql -e "FLUSH PRIVILEGES;"
    if [ $? -eq 0 ]; then
        echo "Priviliges Flushed!"
    else
        echo "Failed to flush privileges!"
    fi
    sleep 1
    # Change root password
    #mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
mysql --user=root <<EOF
UPDATE mysql.user SET Password=PASSWORD('$MYSQL_ROOT_PASSWORD') WHERE User='root';
UPDATE mysql.user SET plugin='mysql_native_password' WHERE user='root' AND host='localhost';
FLUSH PRIVILEGES;
EOF
    sleep 1
    #echo "executed"
    #tail -f /dev/null
    #echo "not executed"
    #echo "root changed"
fi

mysqladmin -u root -p${MYSQL_ROOT_PASSWORD} shutdown;
echo "shutdown completed"
sleep 1
echo "launching daemon"
mysqld;
