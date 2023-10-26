add_requires("boost", { configs = { headers = true } })
add_requires("gmp")

target("pow_boost", { kind = "binary", languages = "c++20", files = { "pow_boost.cpp" }, packages = { "boost" } })
target("pow_char", { kind = "binary", files = { "pow_char.c" } })
target("pow_string", { kind = "binary", files = { "pow_string.cpp" } })
target("pow_gmp", { kind = "binary", files = { "pow_gmp.cpp" }, packages = { "gmp" } })
