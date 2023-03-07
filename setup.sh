#!/bin/sh

run_on_mac()
{
    echo "Setting up on Mac OS..."
    IP=$(ifconfig en0 | grep inet | awk '$1=="inet" {print $2}')
    export DISPLAY=$IP:0
    /usr/X11/bin/xhost + $IP
}

run_on_linux()
{
    echo "Setting up on Linux..."
    xhost +local:
}

OS=$(uname -s)

if [[ ${OS} == "Darwin" ]]; then
    run_on_mac
elif [[ ${OS} == "Linux" ]]; then
    run_on_linux
else
    echo "Unsupported Os ${OS}"
    exit 1
fi

docker run --rm -it --mount type=bind,src=${PWD},dst=/work --env DISPLAY=$DISPLAY \
        --volume /tmp/.X11-unix/:/tmp/.X11-unix:ro --network host pacman-ai-cpp:latest
