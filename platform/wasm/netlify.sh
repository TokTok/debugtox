#!/bin/bash

set -eux -o pipefail

PROJECT=debugtox

if [ ! -f /opt/buildhome/bin/ccache ]; then
  mkdir -p /opt/buildhome/bin
  tar -C /opt/buildhome/bin --strip-components=1 -Jxf \
    <(curl -L https://github.com/ccache/ccache/releases/download/v4.10.2/ccache-4.10.2-linux-x86_64.tar.xz) \
    ccache-4.10.2-linux-x86_64/ccache
fi
if [ ! -d /opt/buildhome/emsdk ]; then
  tar -C /opt -zxf \
    <(curl -L https://github.com/TokTok/dockerfiles/releases/download/nightly/qtox-wasm-buildhome.tar.gz)
fi

. '/opt/buildhome/emsdk/emsdk_env.sh'
export PATH="/opt/buildhome/bin:$PATH"
export PKG_CONFIG_PATH='/opt/buildhome/lib/pkgconfig'

# Limit ccache to 100MB storage.
ccache -M 100M
ccache --show-stats
ccache --zero-stats

export CC='ccache emcc'
export CXX='ccache em++'

emcmake cmake \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCMAKE_FIND_ROOT_PATH='/opt/buildhome;/opt/buildhome/qt' \
  -B_build-wasm \
  -H.

cmake --build _build-wasm --parallel "$(nproc)"

ccache --show-stats

mkdir _site

cp \
  platform/wasm/_headers \
  _build-wasm/qtloader.js \
  _build-wasm/qtlogo.svg \
  "_build-wasm/$PROJECT.js" \
  "_build-wasm/$PROJECT.wasm" \
  _site
cp "_build-wasm/$PROJECT.html" \
  _site/index.html
