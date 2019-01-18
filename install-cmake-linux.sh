#!/usr/bin/env bash

# Install CMake for Linux

set -ex

CMAKE_URL="https://github.com/Kitware/CMake/releases/download/v3.13.3/cmake-3.13.3-Linux-x86_64.sh"
wget -q "${CMAKE_URL}" -O ./cmake.sh
chmod +x ./cmake.sh
./cmake.sh --skip-license --exclude-subdir --prefix="$HOME/.local/"
