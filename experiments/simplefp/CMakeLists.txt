cmake_minimum_required(VERSION 3.16)

project(simplefp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(simplefp STATIC
  SimpleFP.hpp
)

target_compile_definitions(simplefp PRIVATE SIMPLEFP_LIBRARY)
