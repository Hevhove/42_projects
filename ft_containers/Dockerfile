FROM ubuntu:20.04

WORKDIR /app
COPY . . 
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && apt-get install build-essential -y
USER root
RUN make re
CMD ["./containers"]
EXPOSE 3490
