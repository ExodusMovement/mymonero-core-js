#!/bin/sh

#EMCC_DEBUG=1

mkdir -p build &&
cd build &&
emconfigure cmake .. &&
emmake make -j `nproc`
