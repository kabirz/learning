cmake_minimum_required(VERSION 3.13)
project(pow)

find_package(PkgConfig REQUIRED)
# sudo apt install libgmp-dev
pkg_check_modules(GMP REQUIRED IMPORTED_TARGET gmpxx)

add_executable(pow_gmp pow_gmp.cpp)
target_link_libraries(pow_gmp PkgConfig::GMP)

add_executable(pow_char pow_char.c)
add_executable(pow_string pow_string.cpp)

# for ubuntu: sudo apt install libboost-all-dev
# for macos: sudo port install boost
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=gnu++17" COMPILER_SUPPORTS_GNU17)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)

if(COMPILER_SUPPORTS_GNU17 OR COMPILER_SUPPORTS_CXX17)
    find_package(Boost REQUIRED COMPONENTS headers)
    add_executable(pow_boost pow_boost.cpp)
    target_link_libraries(pow_boost Boost::headers)
    target_compile_features(pow_boost PRIVATE cxx_std_17)
else()
    message(WARNING "The compiler ${CMAKE_CXX_COMPILER} has no C++17 support. Please use a different C++ compiler.")
endif()

