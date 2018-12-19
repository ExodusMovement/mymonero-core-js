> In order to create an deterministic build, we're using docker.

### 1. Install Docker

For macOS, download it at https://hub.docker.com/editions/community/docker-ce-desktop-mac

### 2. Prepare repo

```shell
# Clone repo and submodules
git clone git@github.com:ExodusMovement/mymonero-core-js.git --recursive
cd mymonero-core-js

# Remove the existing files, we'll build them in the next section
rm monero_utils/MyMoneroCoreCpp_*

# Prepare boost source code
curl -LO https://dl.bintray.com/boostorg/release/1.69.0/source/boost_1_69_0.tar.gz
mkdir -p contrib/boost-sdk
tar zxf boost_1_69_0.tar.gz -C contrib/boost-sdk --strip-components=1
```

### 3. Build emscripten

```shell
# Build boost emscripten
docker run -it -v $(pwd):/app quay.io/exodusmovement/emscripten ./bin/build-boost-emscripten.sh

# Build MyMonero emscripten
docker run -it -v $(pwd):/app quay.io/exodusmovement/emscripten ./bin/archive-emcpp.sh

# If you get '#error Including <emscripten/bind.h> requires building with -std=c++11 or newer!' error, re-run:

docker run -it -v $(pwd):/app quay.io/exodusmovement/emscripten ./bin/archive-emcpp.sh

# Create monero_utils/MyMoneroCoreCpp_* files, they should be same as the ones in repo.
```

# Other Notes

The `quay.io/exodusmovement/emscripten` image was built by Quay.io
See instructions at https://github.com/ExodusMovement/docker-emscripten