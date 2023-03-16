# Popular, well maintained distro for base image
FROM debian:10.11

# Update
RUN apt-get update -yq

# Install necessary packages
RUN apt-get install nginx -yq
RUN apt-get install vim -yq
RUN apt-get install openssl -yq
RUN apt-get install -y procps
RUN apt-get install -y systemd
RUN apt-get install -y netcat

# Set the date
RUN ln -sf /usr/share/zoneinfo/Europe/Lisbon /etc/localtime

# Create SSL Key
RUN mkdir /etc/nginx/ssl
RUN chmod 700 /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 \
                -x509 \
                -sha256 \
                -days 3650 \
                -nodes \
                -out /etc/nginx/ssl/example.crt \
                -keyout /etc/nginx/ssl/example.key \
                -subj "/C=BE/ST=Brussels/L=Brussels/O=42Ecole/OU=42Ecole/CN=hvan-hov.42.fr"

# Copy the init script and nginx conf file to their location
COPY /tools/ /tmp/
COPY /conf/nginx.conf /etc/nginx/

ENTRYPOINT ["sh", "/tmp/init.sh"]
