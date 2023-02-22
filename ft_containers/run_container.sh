#!/usr/bin/env bash

set -e

CONTAINER_NAME="ft_containers"

if [[ $(docker ps | grep tester) ]]; then
    docker kill $CONTAINER_NAME
fi

docker build -t ft_containers .
docker run -it --rm --name $CONTAINER_NAME ft_containers ./ft_containers
