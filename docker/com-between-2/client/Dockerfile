FROM ubuntu:trusty
MAINTAINER Xin Ding "279543965@qq.com"
ENV REFRESHED_AT 2017-09-06
RUN apt-get -yqq update && apt-get install -yqq iputils-ping 
RUN echo 'I am client'
COPY client /usr/src/
CMD ["usr/src/client"]
EXPOSE 8888/udp
