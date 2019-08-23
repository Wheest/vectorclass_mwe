[![Build Status](https://travis-ci.org/Wheest/vectorclass_mwe.svg?branch=master)](https://travis-ci.org/Wheest/vectorclass_mwe)

# SIMD MWE

A minimum2 working example using the [Vector class](https://github.com/vectorclass/version2) SIMD library, and the [CMake build system](https://cmake.org/).

This repository uses git submodules, thus to build the repo, and run the example:

```
git clone --recurse-submodules https://github.com/Wheest/vectorclass_mwe
mkdir -p vectorclass_mwe/_build
cd vectorclass_mwe/_build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./simd_mwe
```
