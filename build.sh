#!/bin/bash
INSTALL_PREFIX=${INSTALL_PREFIX:=${PREFIX:=${CONDA_PREFIX}}}

rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=${INSTALL_PREFIX}
make -j install
