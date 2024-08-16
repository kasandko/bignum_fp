cmake_minimum_required (VERSION 3.15.0)

project (
    bignum_fp_tests
    VERSION "0.0.1"
    DESCRIPTION "Tests for BignumFP."
    HOMEPAGE_URL "https://github.com/kasandko/bignum_fp"
    LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${PROJECT_SOURCE_DIR}/../include)	
add_executable (bignum_fp_tests ${PROJECT_SOURCE_DIR}/main.cpp)
