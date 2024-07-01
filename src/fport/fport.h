/*!
 * @file fport.h
 * @brief Header file for the FPort Protocol definations
 * @author Witty-Wizard
 */

#pragma once
#ifndef FPORT_H
#define FPORT_H

#include "../SerialIO.h"
#include "fport_protocol.h"

class fport : public SerialIO {
private:
  uint8_t _rxData[FPORT_MAX_PACKET_SIZE] = {0};
  fport_channels_t _channelData;

public:
  explicit fport(Stream *rxPort, int rxPin = -1, int txPin = -1,
                 bool inverted = true);
  void begin() override;
  void processIncoming() override;
  void getChannel(rc_channels_t *channelData) override;
  void crc();
};
#endif