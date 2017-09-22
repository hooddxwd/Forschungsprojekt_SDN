FROM ubuntu:trusty
MAINTAINER Xin Ding "279543965@qq.com"
ENV REFRESHED_AT 2017-09-06
RUN apt-get -yqq update && apt-get install -yqq iputils-ping
COPY server /usr/src/
EXPOSE 8888/udp
