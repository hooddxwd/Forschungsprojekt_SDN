FROM ubuntu:16.04
MAINTAINER Xin Ding "279543965@qq.com"
ENV REFRESHED_AT 2017-09-05


RUN apt-get update -yqq && apt-get -yqq install redis-server redis-tools

EXPOSE 6379
ENTRYPOINT [ "/usr/bin/redis-server" ]
CMD []s
