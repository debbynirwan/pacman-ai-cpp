FROM ubuntu:20.04
LABEL maintainer="Debby Nirwan"
ENV DEBIAN_FRONTEND noninteractive
ENV TZ "Asia/Singapore"
ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8

# install dependencies via apt
ENV DEBCONF_NOWARNINGS yes
RUN set -x && \
  apt update -y -qq && \
  apt upgrade -y -qq --no-install-recommends && \
  : "basic dependencies" && \
  apt install -y -qq \
    build-essential \
    wget \
    tar \
    clang-format \
    clang-tidy \
    cmake && \
  : "Qt5 dependencies" && \
  apt install -y -qq \
    qt5-default && \
  : "Google test dependencies" && \
  apt install -y -qq \
    libgtest-dev && \
  : "spdlog test dependencies" && \
  apt install -y -qq \
    libspdlog-dev && \
  : "remove cache" && \
  apt autoremove -y -qq && \
  rm -rf /var/lib/apt/lists/*

ARG CMAKE_INSTALL_PREFIX=/usr/local
ARG NUM_THREADS=1

ENV CPATH=${CMAKE_INSTALL_PREFIX}/include:${CPATH}
ENV C_INCLUDE_PATH=${CMAKE_INSTALL_PREFIX}/include:${C_INCLUDE_PATH}
ENV CPLUS_INCLUDE_PATH=${CMAKE_INSTALL_PREFIX}/include:${CPLUS_INCLUDE_PATH}
ENV LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${LIBRARY_PATH}
ENV LD_LIBRARY_PATH=${CMAKE_INSTALL_PREFIX}/lib:${LD_LIBRARY_PATH}

# yaml-cpp
ARG YAML_CPP_VERSION=0.7.0
WORKDIR /tmp
RUN set -x && \
  wget -q https://github.com/jbeder/yaml-cpp/archive/refs/tags/yaml-cpp-${YAML_CPP_VERSION}.tar.gz && \
  tar xf yaml-cpp-${YAML_CPP_VERSION}.tar.gz && \
  rm -rf yaml-cpp-${YAML_CPP_VERSION}.tar.gz && \
  cd yaml-cpp-yaml-cpp-${YAML_CPP_VERSION} && \
  mkdir -p build && \
  cd build && \
  cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} \
    .. && \
  make -j${NUM_THREADS} && \
  make install && \
  cd /tmp && \
  rm -rf *

WORKDIR /work
ENTRYPOINT ["/bin/bash"]
