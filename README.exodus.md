## Build

### 1. Install Docker

For macOS, download it at https://hub.docker.com/editions/community/docker-ce-desktop-mac

### 2. Update and prepare the repo

```shell
git pull
./prepare.sh # Should finish with "All done! We are prepared for the build now."
```

### 3. Build emscripten

```shell
./build.sh
```

# Other Notes

Emscripten is built in docker from https://github.com/ExodusMovement/docker-emscripten, but we build it locally as part of the build process in prepare.sh
