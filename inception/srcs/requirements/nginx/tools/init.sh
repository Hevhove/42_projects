# Inside of conf/nginx.conf, we have some environment variables which are
# not yet set by default. In this script, we replace those with environment variables from the current shell session
# These environment variables have been set by the docker-compose.yml environment directive.j

# Wait for Wordpress to be available on port 9000 before launching this script
while ! nc -z wordpress 9000; do
  sleep 1
done

sed -i "s/__SCHOOL_USERNAME__/$SCHOOL_USERNAME/g" /etc/nginx/nginx.conf
sed -i "s/__NGINX_WORDPRESS_CONTAINER_NAME__/$NGINX_WORDPRESS_CONTAINER_NAME/g" /etc/nginx/nginx.conf
sed -i "s/__NGINX_WORDPRESS_PORT__/$NGINX_WORDPRESS_PORT/g" /etc/nginx/nginx.conf

# By default, nginx starts as a daemon in the background.
# This command moves the process to the foreground and shows output to the console.
echo "Launching nginx daemon!"
nginx -g "daemon off;"
