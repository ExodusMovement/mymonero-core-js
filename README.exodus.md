## Build

### 1. Install Docker

For macOS, download it at https://hub.docker.com/editions/community/docker-ce-desktop-mac

### 2. Update and prepare the repo

```shell
git pull
./prepare.sh
```

### 3. Build emscripten

```shell

# Clean up old build files
rm -rf build && mkdir build
rm monero_utils/MyMoneroCoreCpp_*

# Build boost emscripten
docker run -it -v $(pwd):/app quay.io/exodusmovement/emscripten:1.38.48 ./bin/build-boost-emscripten.sh

# Build MyMonero emscripten
docker run -it -v $(pwd):/app quay.io/exodusmovement/emscripten:1.38.48 ./bin/archive-emcpp.sh

# If you get '#error Including <emscripten/bind.h> requires building with -std=c++11 or newer!' error, re-run:

docker run -it -v $(pwd):/app quay.io/exodusmovement/emscripten:1.38.48 ./bin/archive-emcpp.sh
```

# Other Notes

The `quay.io/exodusmovement/emscripten` image was built by Quay.io
See instructions at https://github.com/ExodusMovement/docker-emscripten
