# Inception Project Guide
Hello fellow 42 student! Welcome to my inception guide! Before diving into specifics, below I touch on some basics of Docker/MariaDB/NginX/Wordpress. For this, I used the following sources:
- [Docker Tutorial](https://www.youtube.com/watch?v=fqMOX6JJhGo&ab_channel=freeCodeCamp.org)
- [MariaDB Beginner Articles](https://mariadb.com/kb/en/beginner-mariadb-articles/)
- [NginX]()
- [WordPress]()

## Docker
### What is Docker?
Docker is an open platform for developers to build, ship and run applications through containerization.

Docker creates containers, which similarly to Virtual Machines, have their own set of resources, processes, packages, environment variables installed. These containers run their own libraries, dependencies, on top of which they run one or more applications. The general idea is providing a clean environment for applications with all of their requirements satisfied. This helps developers enormously, as they can skip complicated configurations and setups on their personal machines, which run different environments and OSes. Once the main task of the container is completed, the container stops running.

VMs run their own OS while Docker uses the kernel of the host machine.The benefit of using Docker versus a VM is less CPU-usage, less disk usage and starter boot times. VMs allow to run applications built for different OSes, while in Docker we can only containerize applications that are built for the same OS! Docker Desktop for Mac and Windows actually do run a Linux VM under the hood to work with Linux applications.

### Container vs Image
An image is a package or a template (similar to a class in OOP), of which we can instantiate many running containers. Once an image has been built, different containers can be ran, which then can diverge from the base 'template' called the image.

Images can either be pulled from online repositories such as DockerHub, or we can build our own images.

Pulling from DockerHub is very straightforward. A simple `docker pull <image-name>` will pull the images into the folder `/var/lib/docker`. We can list all available local images with the command `docker images`. Much more packages are available on Dockerhub.com. We could pull images for operating systems, web server components and more.

The image can also be built ourselves using the `docker build Dockerfile` command. The command uses a Dockerfile, which is a file that contains different instructions on how to build an image. More on this later!

### Docker Run
We can launch containers from an image using the command `docker run <image-name>`. Not that this takes over the current terminal window, which we can prevent by launching in detached mode with the flag -d: `docker run -d <image-name>`. Containers stop running after they have executed their commands. If we run an OS such as Ubuntu, it would stop running immediately because there is no command to be executed. However, if we would launch a webserver that would keep listening continuously for incoming connections, the container would keep running. We can check if a container is running with the command `docker ps`. Add the flag `-a` to also show containers that have exited.

#### Docker Run: Ports
We can also specify ports when running such as `docker run -p 8000:5000`. In this example, the host will be able to communicate via port 8000, while the container via  port 5000. If we're running multiple containers, we cannot map different containers to the same port on the host.

#### Docker Run: Volumes
Like ports, we can also map volumes. With volumes, we can store data on the host machine, so it does not dissapear after a container exits. For example, with `docker run -v /opt/datadir:/var/lib/mysql`, when docker is launched, it will mount the external directory to a folder inside the docker container. This way, all our data is stored in /opt/datadir and this will remain even if we delete the container.

#### Docker Run: Info
If we need information about the above settings, use the `docker inspect <container-name>` command. We can also investigate logs with `docker logs <container-name>`

#### Docker Run: Environment
We can set environment variables directly in the container while running using the `-e` flag. Example: `docker run -e APP_COLOR=blue -e ROOT_SQL_PASSWD=passwd123 <image-name>`.

### Creating our own images
To create our own images, we can use a Dockerfile. This file contains Instructions and Arguments.
Instructions:
- `FROM` defines the base OS from which the containers starts
- `RUN` are commands that install dependencies and libraries for the image
- `COPY` copies source code from a directory into the container
- `ENTRYPOINT` is a command run immediately after container startup.
- `CMD` is a command run immediately after container startup.

The difference between ENTRYPOINT and CMD is that CMD commands will be ignored when there are parameters stated within the docker run command, while for ENTRYPOINT, the parameters are appended as arguments of the command defined within ENTRYPOINT.

Docker images are composed of layers and therefore they do not need to rebuild all of those layers when making changes to an image build. For example, if we change some of the dependencies under `RUN`, docker is smart enough not to rebuild the base OS under `FROM`.

An example Dockerfile:
```
FROM Ubuntu

RUN apt-get update && apt-get -y install python

RUN pip install flask flask-mysql

COPY . /opt/source-code

ENTRYPOINT FLASK_APP=/opt/source-code/app.py flask run
```

Once the Dockerfile has been written we can build the image: `docker build Dockerfile -t username/my-custom/app` where -t adds a tag to the built docker image.

### Networking
When you install Docker, it creates 3 networks automatically:
1. Bridge
2. Null
3. Host

Bridge is the default network a container gets attached to. We can attach a container to a network as such: `docker run ubuntu --network=none`. If we don't indicate anything for the network variable, the network is Bridge.

The bridge network is a private internal network created by docker on the host. All containters attached to this network get an internal IP address in the range 172.17.x.x . The containers can access each other using this internal IP. To access our containers for the outside world, map the ports of the containers to ports on the Docker host.

Another way to do this, is associating the container to the host network: `docker run ubuntu --network=host`. This takes out network isolation between the docker host and docker container. Meaning if we have a web server running on port 5000, it is automatically accessible on the same port on the host. The container then uses the host network. But this means we are not able to run multiple web containers on the same host on the same port, as the ports are now common to all containers in the host network.

With the `none` network, the containers are not attached to any network and isolated from every external network.

By default, docker only creates one internal bridge network. We could create our own internal network using the command `docker network create` command. We need to specify the driver which is bridge and the subnet for the network, followed by a network name: `docker network create --drive bridge --subnet 182.18.0.0/16` custom-isolated-network. To see all networks run the cmd: `docket network ls`.

Networks can also be inspected: `docker inspect <container_name>`, and check out the section under "Network". Containers can reach each other using their names. How could we get a container running a web server and a container running a database communicating? We could us the internal IP address, but if the system reboots, the IP could change. The right way is using the container name. There is an embedded DNS inside of Docker that helps containers find each other in the network. The DNS server runs at address `127.0.0.11`.

### Storage
When you install docker on a system, it creates the following folder: `/var/lib/docker`. The following directories are present here:
1. aufs
2. containers
3. image
4. volumes

The layers of an image after building is read-only information. When you run a container based off of an image with `docker run`, it creates a new writeable layer on top of the image layer, that stores data created by the container such as log files, tmp files or any file modified by the user. The life of this layer is only for the duration of the container. Once the container is destroyed, the data is gone.

To make data persistent, we need to create a volume: `docker volume create data_volume`, which creates a folder under the (4) volumes folder inside `/var/lib/docker/volumes/data_volume`. When the docker container is then run with `docker run -v data_volume:/var/lib/mysql mysql` where `/var/lib/mysql` is the default location where MySQL stores data. So all data written by the database into its folder, is in fact written to the host.

If you have not created a volume before using it in `docker run`, docker will itself create a volume for you. This process is called volume mounting. If you already have data which you want a new docker container to use, you can also give the docker run the full path to the data.

For all of these copy/writing/moving files, the storage driver is responsible. Some examples are AUFS/ZFS/BTRFS/.... The choice depends on the OS. On Ubuntu it is AUFS. Docker will choose the best storage driver for you based on your OS.

### Docker Compose
If we needed to set up a complex application with multiple services, writing many docker run commands is a bit tedious. A better way to do it would be to use `docker compose`. For this we need to create a configuration file called `docker-compose.yml`.

An example docker-compose.yml file:
```
services
	web:
		build: ./vote
		ports:
			- 5000:80
		links:
			- redis

	database:
		image: "postgres:9.4"

	messaging:
		image: "redis"

	orchestration:
		image: "ansi"
		links:
			- redis
			- database
```

To bring up the entire application stack, we can just launch `docker-compose up`.

If we want to make our own images, we need to replace the `image` line with a `build` instruction with the location of a folder with the application code.

Note that there are 3 different versions of the `.yml` files. To indicate the version we are using we can pre-pend the file with a specification `version: 2`. In version 2, docker compose automatically creates a dedicated bridge network, which all containers can use to communicate together using their service name. So we don't need to use `links: ` in version 2. Version 2 also introduces `depends_on`, so that certain images are built before others.

Version 3 introduces support for Docker Swarm, which I won't go into here.
## MariaDB

Resource: https://mariadb.com/kb/en/beginner-mariadb-articles/

## NGINX

## WordPress

## Project Guide
Let's go ahead now and dive into what needs to be done to get this project completed!

### Virtual Machine Set-up


### Set-up
Resource: https://www.digitalocean.com/community/tutorials/how-to-install-wordpress-with-lemp-nginx-mariadb-and-php-on-debian-10