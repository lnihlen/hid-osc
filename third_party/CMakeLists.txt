# oscpack
include_directories(oscpack_1_1_0)
add_library(oscpack STATIC EXCLUDE_FROM_ALL "oscpack_build.cc")
target_include_directories(oscpack INTERFACE oscpack_1_1_0)

