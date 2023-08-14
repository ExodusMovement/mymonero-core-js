#!/usr/bin/env bash

set -e # Exit on any error

rm -rf build && mkdir build
rm -f monero_utils/MyMoneroCoreCpp_*

# Build boost emscripten - docker image is built locally in previous step
echo "Building boost emscripten..."
docker run -it -v $(pwd):/app local-registry.exodus.com/emscripten:latest ./bin/build-boost-emscripten.sh

# Build MyMonero emscripten
docker run -it -v $(pwd):/app local-registry.exodus.com/emscripten:latest ./bin/archive-emcpp.sh
