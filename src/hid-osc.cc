#include <iostream>

#include "ip/UdpSocket.h"
#include "ip/PacketListener.h"
#include "osc/OscReceivedElements.h"
#include "osc/OscPrintReceivedElements.h"

class OscDumpPacketListener : public PacketListener {
 public:
  virtual void ProcessPacket(const char* data,
                             int size,
                             const IpEndpointName& endpoint) {
    (void)endpoint;
    std::cout << osc::ReceivedPacket(data, size);
  }
};

int main(int argc, char* argv[]) {
  OscDumpPacketListener listener;
  UdpListeningReceiveSocket s(
      IpEndpointName(IpEndpointName::ANY_ADDRESS, 7000), &listener);

  s.RunUntilSigInt();

  return 0;
}

