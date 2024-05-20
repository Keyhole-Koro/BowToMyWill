FROM ubuntu:latest

RUN sed -i 's@archive.ubuntu.com@ftp.jaist.ac.jp/pub/Linux@g' /etc/apt/sources.list

RUN apt-get update && apt-get install -y \
    make \
    cmake \
    clang \
    gcc \
    git \
    lld \
    nasm \
    gdb \
    tree && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*


#RUN git clone https://github.com/DaveGamble/cJSON.git /tmp/cJSON && \
#    cd /tmp/cJSON && \
#    mkdir build && \
#    cd build && \
#    cmake .. && \
#    make && \
#    make install

#sudo apt-get install libcjson-dev
