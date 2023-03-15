# Popular, well maintained distro for base image
FROM debian:10.11

# Update
RUN apt-get update -yq

# Install necessary packages
RUN apt-get install vim -yq
RUN apt-get install curl -yq
RUN apt-get install wget -yq
RUN apt-get install php7.3-cli php7.3-fpm php7.3-mysql php7.3-json php7.3-opcache \
                    php7.3-mbstring php7.3-xml php7.3-cgi php-pear php7.3-zip \
                    php-net-socket php7.3-common php7.3-gd php7.3-curl \
                    php-xml-util php7.3-gettext php7.3-bcmath -yq

# Set the date
RUN ln -sf /usr/share/zoneinfo/Europe/Lisbon /etc/localtime

# Copy the init script
COPY /tools/ /tmp/
RUN chmod +x /tmp/*

# Wordpress set-up
RUN mkdir /var/www
RUN mkdir /var/www/html
WORKDIR /var/www/html
RUN wget https://wordpress.org/wordpress-6.1.1.tar.gz
RUN tar -xvzf wordpress-6.1.1.tar.gz
RUN rm wordpress-6.1.1.tar.gz
WORKDIR /var/www/html/wordpress
COPY /conf/wp-config.php .
RUN chown -R www-data:www-data /var/www/html/wordpress
COPY /conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

# Wordpress install
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	--output-document=/usr/local/bin/wp \
    && chmod +x /usr/local/bin/wp

#ENV MYSQL_DATABASE=wordpress_db
#ENV MYSQL_USER=hvan-hov
#ENV MYSQL_PASSWORD=password123
#ENV MYSQL_DB_HOST=mariadb

ENTRYPOINT ["sh","-c", "/bin/bash /tmp/init.sh;"]
