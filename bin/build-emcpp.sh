#!/bin/sh

#EMCC_DEBUG=1 

mkdir -p build && 
cd build && 
emconfigure cmake .. && 
emmake cmake --build . -j `nproc` && 
emmake make . -j `nproc`
