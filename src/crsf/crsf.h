#pragma once
#ifndef CRSF_H
#define CRSF_H
#include "crsf_protocol.h"
#include <serialIO.h>

class crsf : public serialIO {
private:
  bool header_detected;
  uint8_t rx_index;
  uint8_t rx_data[CRSF_MAX_PACKET_SIZE];

public:
  explicit crsf(HardwareSerial &rxPort, int rxPin, int txPin,
                bool inverted = false)
      : serialIO(&rxPort, rxPin, txPin, inverted){};
  virtual ~crsf(){};

  void begin() override;
  void processIncoming() override;
  void getChannel(crsf_channels_t *channelData) override;
};

#endif