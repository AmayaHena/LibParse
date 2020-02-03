#!/bin/bash

stty -raw
stty echo
stty onlcr

if [ ! -d "./build" ]; then
    mkdir build
fi
cd build && cmake .. -G "Unix Makefiles" && cmake --build . && mv libNyx.so ..