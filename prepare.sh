#!/usr/bin/env bash

set -e # Exit on any error

# Dependencies

## These should be audited!
mymonero_core_cpp_url='https://github.com/ExodusMovement/mymonero-core-cpp'
mymonero_core_cpp_hash='332e193a1d158b2acdc22d84857a4cbddcddeca9'
monero_core_custom_url='https://github.com/ExodusMovement/monero-core-custom'
monero_core_custom_hash='19b00d33e1c82dd4b972cfe801dbbfca7040569f'

## Boost, hash should match upstream documented
boost_url='https://boostorg.jfrog.io/artifactory/main/release/1.69.0/source/boost_1_69_0.tar.gz'
boost_sha256='9a2c2819310839ea373f42d69e733c339b4e9a19deab6bfec448281554aa4dbb' # per https://www.boost.org/users/history/version_1_69_0.html

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
if [[ ! -f "boost_1_69_0.tar.gz" ]]; then
  curl -LO "${boost_url}"
fi
if [ "$(shasum -a 256 'boost_1_69_0.tar.gz' | sed s/' .*'//)" != "${boost_sha256}" ]; then
  echo "Invalid boost shasum!"
  exit 1
fi

echo "Extracting boost..."
rm -rf 'contrib/boost-sdk' && mkdir -p 'contrib/boost-sdk'
tar zxf 'boost_1_69_0.tar.gz' -C 'contrib/boost-sdk' --strip-components=1

# Prepare for build

echo "Clearing the build dir..."
rm -rf build && mkdir build

# Finished

echo "All done! We are prepared for the build now."
