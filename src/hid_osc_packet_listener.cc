#include "hid_osc_packet_listener.h"

#include <cstring>

void HidOscPacketListener::ProcessMessage(const osc::ReceivedMessage& message,
    const osc::IpEndpointName& ip_endpoint) {

  if (std::strcmp(message.AddressPattern(), "/list") == 0) {

  } else {
  }
}
