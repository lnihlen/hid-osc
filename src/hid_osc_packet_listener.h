#ifndef SRC_HID_OSC_PACKET_LISTENER_
#define SRC_HID_OSC_PACKET_LISTENER_

#include "osc/OscPacketListener.h"
#include "osc/OscReceivedElements.h"

class HidOscPacketListener : public osc::OscPacketListener {
 protected:
  virtual void ProcessMessage(const osc::RecievedMessage&,
      const osc::IpEndpointName&);
};

#endif  // SRC_HID_OSC_PACKET_LISTENER_
