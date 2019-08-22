cmake_minimum_required(VERSION 3.8)
project(SIMD_MWE)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0")
SET(CMAKE_C_FLAGS_DEBUG "-O0")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

list(APPEND Mwe_INCLUDE_DIRS PUBLIC ${PROJECT_SOURCE_DIR}/3rdparty/version2/)
include_directories(${Mwe_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -march=native -fno-vectorize -fno-tree-vectorize -fno-slp-vectorize")

add_executable(simd_mwe src/main.cpp ${GEN_ARCH_FILES})
#set_target_properties(simd_mwe PROPERTIES COMPILE_FLAGS "-msse2")
