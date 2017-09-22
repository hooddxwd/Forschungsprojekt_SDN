FROM ubuntu:16.04
MAINTAINER Xin Ding "279543965@qq.com"
ENV REFRESHED_AT 2017-09-05


RUN apt-get update -yqq && apt-get -yqq install ruby ruby-dev build-essential redis-tools

RUN ruby -v
RUN gem install --no-rdoc --no-ri sinatra json redis


RUN mkdir -p /opt/webapp


EXPOSE 4567


CMD ["/opt/webapp/bin/webapp"]
