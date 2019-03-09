# oscpack
include_directories(oscpack_1_1_0)
add_library(oscpack STATIC "oscpack_build.cc")
target_include_directories(oscpack INTERFACE oscpack_1_1_0)

# hidapi
# For Linux, manual build configuration with embedded library, hidraw mode.
include_directories(hidapi/hidapi)
set(hidapi_files
  hidapi/linux/hid.c
  hidapi/hidtest/hidtest.cpp
)
add_library(hidapi STATIC ${hidapi_files})
target_link_libraries(hidapi udev)
target_include_directories(hidapi INTERFACE hidapi/hidapi)
