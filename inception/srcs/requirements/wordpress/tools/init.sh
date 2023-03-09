# Starting php7.3-fpm creates /run/php/php7.1-fpm.sock
# Now the php-fpm7.3 -F -R works, before doing service php7.3-fpm it wouldn't work
service php7.3-fpm start
service php7.3-fpm stop
php-fpm7.3 -F -R  
