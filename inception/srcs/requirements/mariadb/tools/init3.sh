#!/bin/bash

# Start MariaDB server
service mysql start

# Check if database already exists
if [ -z "$(mysql -u root -p$MYSQL_PASSWORD -se "SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME='$MYSQL_DATABASE'")" ]; then
  # Create the database
  mysql -u root -p$MYSQL_PASSWORD -e "CREATE DATABASE $MYSQL_DATABASE"
  echo "Database $MYSQL_DATABASE created."
else
  echo "Database $MYSQL_DATABASE already exists."
fi

# Create user and grant privileges
mysql -u root -p"$MYSQL_PASSWORD" -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'"
mysql -u root -p"$MYSQL_PASSWORD" -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'"
echo "User $MYSQL_USER created and granted all privileges on $MYSQL_DATABASE."

# Apply changes
mysql -u root -p"$MYSQL_PASSWORD" -e "FLUSH PRIVILEGES"

# Set root password
#mysql -u root -p"$MYSQL_PASSWORD" -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_PASSWORD'"

# Keep the container running
tail -f /dev/null
