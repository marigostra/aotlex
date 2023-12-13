
FROM ubuntu:latest
WORKDIR /app
COPY build-aot /app/

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -q -y \
openjdk-11-jre git g++ cmake curl bison flex locales locales-all

ENV LC_ALL ru_RU.UTF-8
ENV LANG ru_RU.UTF-8
ENV LANGUAGE ru_RU.UTF-8

RUN git clone https://github.com/sokirko74/aot
RUN /app/build-aot
