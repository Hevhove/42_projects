# Wait a bit for the mariadb container script to have finished
sleep 15

# Install wordpress binary
wp core install --url=${MYSQL_USER}.42.fr --title=42Inception --admin_user=${MYSQL_USER} --admin_password=${MYSQL_USER_PASSWORD} --admin_email=${MYSQL_USER}@student.42lisboa.com --allow-root

# Launch Wordpress
# Starting php7.3-fpm creates /run/php/php7.1-fpm.sock
# Now the php-fpm7.3 -F -R works, before doing service php7.3-fpm it wouldn't work
echo "wordpress launched!"
service php7.3-fpm start
service php7.3-fpm stop
php-fpm7.3 -F -R  
