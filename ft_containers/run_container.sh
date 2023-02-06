#!/usr/bin/env bash

set -e 

CONTAINER_NAME="containers"

if [[ $(docker ps | grep tester) ]]; then
    docker kill $CONTAINER_NAME
fi

docker build -t containers .
docker run --name $CONTAINER_NAME containers
