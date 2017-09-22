# Version 0.0.1
FROM ubuntu:16.04
MAINTAINER Xin Ding "279543965@qq.com"
RUN apt-get update && apt-get install -y nginx
RUN echo 'Hi, I am in your container'\
	>/usr/share/nginx/html/index.html
EXPOSE 80
