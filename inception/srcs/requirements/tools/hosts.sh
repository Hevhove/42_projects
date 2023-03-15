# Script that edits the hosts file of the VM on which the containers are running
# The hosts file is used to make local redirections such as 127.0.0.1 -> localhost
# We will provide our own redirections as described in the subject here

if [ $1 == "add" ]; then
    echo -n `docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' nginx` > nginx.txt 

    NGINX_IP=$(head -n 1 nginx.txt)
    echo "Nginx IPAddress: $NGINX_IP"

    rm nginx.txt

    # Removing lines if already in the file
    sudo sed -i '/42.fr/d' /etc/hosts

    # Adding new line
    sudo sed -i '1i'$NGINX_IP' '${SUDO_USER}'.42.fr' /etc/hosts
    sudo sed -i '1i'$NGINX_IP' www.'${SUDO_USER}'.42.fr' /etc/hosts
    sudo sed -i '1i'$NGINX_IP' https://www.'${SUDO_USER}'.42.fr' /etc/hosts
fi

if [ $1 == "delete" ]; then
        sudo sed -i '/42.fr/d' /etc/hosts

fi
