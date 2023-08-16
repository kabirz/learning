cmake_minimum_required(VERSION 3.0)
project(YourProject)

find_package(PkgConfig REQUIRED)
# sudo apt install libgmp-dev
pkg_check_modules(GMP REQUIRED IMPORTED_TARGET gmpxx)

add_executable(pow_gmp pow_gmp.cpp)
target_link_libraries(pow_gmp PkgConfig::GMP)

add_executable(pow_char pow_char.c)
add_executable(pow_string pow_string.cpp)

#  sudo apt install libboost-all-dev
add_executable(pow_boost pow_boost.cpp)
