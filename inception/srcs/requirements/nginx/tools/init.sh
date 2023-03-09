# Inside of conf/nginx.conf, we have some environment variables which are
# not yet set by default. In this script, we replace those with environment variables from the current shell session
# These environment variables have been set by the docker-compose.yml environment directive.j

# Temporary tests
SCHOOL_USERNAME=hvan-hov
NGINX_WORDPRESS_CONTAINER_NAME=wordpress
NGINX_WORDPRESS_PORT=9000

sed -i "s/__SCHOOL_USERNAME__/$SCHOOL_USERNAME/g" /etc/nginx/nginx.conf
sed -i "s/__NGINX_WORDPRESS_CONTAINER_NAME__/$NGINX_WORDPRESS_CONTAINER_NAME/g" /etc/nginx/nginx.conf
sed -i "s/__NGINX_WORDPRESS_PORT__/$NGINX_WORDPRESS_PORT/g" /etc/nginx/nginx.conf

# By default, nginx starts as a daemon in the background.
# This command moves the process to the foreground and shows output to the console.
# Other option is: $tail -f /dev/null
# The below option has a similar result as it calls the tail command as a child process of the script
nginx -g "daemon off;"
