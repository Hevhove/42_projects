# Popular, well maintained distro for base image
FROM debian:10.11

# Update
RUN apt-get update -yq

# Install necessary packages
RUN apt-get install mariadb-server -yq
RUN apt-get install vim -yq
RUN apt-get install -y procps
RUN apt-get install net-tools
RUN apt-get clean

# Set the date
RUN ln -sf /usr/share/zoneinfo/Europe/Lisbon /etc/localtime

# TEMPORARY
#ENV MYSQL_ROOT_PASSWORD=rootpw
#ENV MYSQL_USER=hvan-hov
#ENV MYSQL_USER_PASSWORD=userpw
#ENV MYSQL_DATABASE=wordpress_db
#ENV MYSQL_DB_HOST=mariadb
ENV MYSQL_PWD=""
# Copy the init script to location
COPY /tools/ /tmp/
RUN chmod +x /tmp/*

ENTRYPOINT ["/bin/sh", "/tmp/init.sh"]
