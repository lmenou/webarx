FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --no-cache dpkg
RUN apk add --no-cache clang-dev alpine-sdk lld
RUN apk add --no-cache cmake ccache
RUN apk add --no-cache boost-dev openssl-dev

RUN ln -sf /usr/bin/clang /usr/bin/cc
RUN ln -sf /usr/bin/clang++ /usr/bin/c++

RUN update-alternatives --install /usr/bin/cc cc /usr/bin/clang 10
RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 10
RUN update-alternatives --install /usr/bin/ld ld /usr/bin/lld 10

RUN update-alternatives --auto cc
RUN update-alternatives --auto c++
RUN update-alternatives --auto ld

RUN update-alternatives --display cc
RUN update-alternatives --display c++
RUN update-alternatives --display ld

RUN ls -l /usr/bin/cc /usr/bin/c++

RUN cc --version
RUN c++ --version
