cmake_minimum_required (VERSION 3.15.0)

project (
    bignum_fp
    VERSION "0.0.1"
    DESCRIPTION "Fixed point based on some arbitrary-precision integer."
    HOMEPAGE_URL "https://github.com/kasandko/bignum_fp"
    LANGUAGES CXX
    )

add_library (bignum_fp INTERFACE)
target_sources (bignum_fp INTERFACE
    ${PROJECT_SOURCE_DIR}/include/bfp/fixed.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/integral_type_trait.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/limits.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/literal.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/math.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/numbers.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/numeric_limits.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/stream.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/string_cvt.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/type_defs.hpp
    ${PROJECT_SOURCE_DIR}/include/bfp/internal/fixed.inl
    ${PROJECT_SOURCE_DIR}/include/bfp/internal/literal.inl
    ${PROJECT_SOURCE_DIR}/include/bfp/internal/math.inl
    )

target_compile_features (bignum_fp INTERFACE cxx_std_17)
target_include_directories (bignum_fp INTERFACE ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(tests)
