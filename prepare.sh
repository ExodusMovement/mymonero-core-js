#!/usr/bin/env bash

set -e # Exit on any error

# Dependencies

## These should be audited!
mymonero_core_cpp_url='https://github.com/ExodusMovement/mymonero-core-cpp'
mymonero_core_cpp_hash='69408962a900c64483311c42768fa876381d3d57'
monero_core_custom_url='https://github.com/ExodusMovement/monero-core-custom'
monero_core_custom_hash='c601fdc3a7aa0c449a3e2c99df230f503fb67e3c'

## Boost, hash should match upstream documented
boost_url='https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.gz'
boost_sha256='273f1be93238a068aba4f9735a4a2b003019af067b9c183ed227780b8f36062c' # per https://www.boost.org/users/history/version_1_69_0.html

if [ "$(basename "$(pwd)")" != "mymonero-core-js" ]; then
  echo "Should be ran from the repo dir!"
  exit 1
fi

function clonerepo { # source, target, commit
  rm -rf "$2"
  oldpwd="$(pwd)"

  git clone "${1}" "${2}" || exit 1
  cd "$2"
  git reset --hard "$3" || exit 1
  if [ "$(git rev-parse HEAD)" != "$3" ]; then
    echo "Wrong HEAD!"
    exit 1
  fi

  cd "$oldpwd"
}

# Clone dependencies

echo "Cloning dependencies..."
rm -rf 'src/submodules' && mkdir -p 'src/submodules'
clonerepo "${mymonero_core_cpp_url}" 'src/submodules/mymonero-core-cpp' "${mymonero_core_cpp_hash}"
clonerepo "${monero_core_custom_url}" 'src/submodules/mymonero-core-cpp/contrib/monero-core-custom' "${monero_core_custom_hash}"

# Prepare boost source code

echo "Downloading and validating boost..."
if [[ ! -f "boost_1_79_0.tar.gz" ]]; then
  curl -LO "${boost_url}"
fi
if [ "$(shasum -a 256 'boost_1_79_0.tar.gz' | sed s/' .*'//)" != "${boost_sha256}" ]; then
  echo "Invalid boost shasum!"
  exit 1
fi

echo "Extracting boost..."
rm -rf 'contrib/boost-sdk' && mkdir -p 'contrib/boost-sdk'
tar zxf 'boost_1_79_0.tar.gz' -C 'contrib/boost-sdk' --strip-components=1

# Prepare for build

echo "Clearing the build dir..."
rm -rf build && mkdir build

# Finished

echo "All done! We are prepared for the build now."
