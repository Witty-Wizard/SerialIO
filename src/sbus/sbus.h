#pragma once
#ifndef SBUS_H
#define SBUS_H

#include "../crsf/crsf_protocol.h"
#include <serialIO.h>

#define HEADER_SBUS 0X0F
#define FOOTER_SBUS 0X00
#define SBUS_BAUDRATE 100000
#define SBUS_MAX_PACKET_SIZE 25

class sbus : public serialIO {
private:
  bool header_detected_sbus = false;
  int prev_buffer_sbus;
  int buffer_sbus;
  int rx_index;
  uint8_t data_rx[SBUS_MAX_PACKET_SIZE];

public:
  explicit sbus(HardwareSerial &rxPort, int rxPin, int txPin,
                bool inverted = true)
      : serialIO(&rxPort, rxPin, txPin, inverted){};
  virtual ~sbus(){};

  void begin() override;
  void processIncoming() override;
  void getChannel(crsf_channels_t *channelData) override;
};

#endif