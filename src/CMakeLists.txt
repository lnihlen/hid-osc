set(hid_osc_files
  hid-osc.cc
)

add_executable(hid-osc ${hid_osc_files})
target_link_libraries(hid-osc
  gflags::gflags
  hidapi
  oscpack
)

