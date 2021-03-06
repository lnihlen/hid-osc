#include <stdio.h>
#include <stdlib.h>

#include "gflags/gflags.h"
#include "hidapi.h"

#include "hid_osc_packet_listener.h"

DEFINE_int32(udp_port_number, 4636,
  "UDP port to bind for incoming OSC requests.");

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // Initialize hidapi library.
  int res = hid_init();
  if (res != 0) {
    fprintf(stderr, "error initializing hidapi library\n");
  }

  hid_device_info* device_list = hid_enumerate(0, 0);

  hid_device_info* device = device_list;
  while (device != nullptr) {
    printf("---- Device\n");
    printf("  Vendor Id: %d\n", device->vendor_id);
    printf("  Product Id: %d\n", device->product_id);
    wprintf(L"  Serial Number: %s\n", device->serial_number);
    printf("  Release Number: %d\n", device->release_number);
    wprintf(L"  Manufacturer String: %s\n", device->manufacturer_string);
    wprintf(L"  Product String: %s\n", device->product_string);
    device = device->next;
  }

  hid_free_enumeration(device_list);
  hid_exit();

  return 0;
}

