# Inception Project Guide

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

Docker images are composed of layers and therefore they do not 

## MariaDB
Resource: https://mariadb.com/kb/en/beginner-mariadb-articles/

## NGINX

## WordPress