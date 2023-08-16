# pow

## cmake  use pkgconfig

```cmake
find_package(PkgConfig REQUIRED)
pkg_check_modules(GMP REQUIRED IMPORTED_TARGET gmpxx)
target_link_libraries(pow_gmp PkgConfig::GMP)
```

is same with:

```cmake
find_package(PkgConfig REQUIRED)
pkg_check_modules(GMP REQUIRED gmpxx)
include_directories(${GMP_INCLUDE_DIRS})
link_directories(${GMP_LIBRARY_DIRS})
target_link_libraries(pow_gmp ${GMP_LIBRARIES})
```
