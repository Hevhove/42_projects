# Popular, well maintained distro for base image
FROM debian:10.11

# Update
RUN apt-get update -yq

# Install necessary packages
RUN apt-get install mariadb-server -yq
RUN apt-get install vim -yq
RUN apt-get install -y procps
RUN apt-get install -y systemd

# Set the date
RUN ln -sf /usr/share/zoneinfo/Europe/Lisbon /etc/localtime

# Copy the init script to location
COPY /tools/ /tmp/

ENTRYPOINT ["sh","-c", "/bin/bash /tmp/init.sh;"]
