#!/bin/bash
apt-get update -y
apt-get upgrade -y

# install a newer cmake version
wget https://cmake.org/files/v3.5/cmake-3.5.2-Linux-x86_64.tar.gz
mkdir ~/cmake
tar -zxvf cmake-3.5.2-Linux-x86_64.tar.gz -C ~/cmake --strip-components 1

# install gtest
apt-get install -y libgtest-dev
cd /usr/src/gtest
~/cmake/bin/cmake ./
make
cp *.a /usr/lib

# return
cd $CI_PREOJECT_DIR
