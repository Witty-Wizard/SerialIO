/*!
 * @file fport.h
 * @brief Header file for the FPort Protocol definations
 * @author Witty-Wizard
 */

#pragma once
#ifndef FPORT_H
#define FPORT_H

#include "../SerialIO.h"

#define FPORT_BAUDRATE 115200    ///< F.Port baudrate
#define FPORT_MAX_PACKET_SIZE 29 ///< F.Port maximum packet length

typedef struct fport_channels_s {
  unsigned channel1 : 11;
  unsigned channel2 : 11;
  unsigned channel3 : 11;
  unsigned channel4 : 11;
  unsigned channel5 : 11;
  unsigned channel6 : 11;
  unsigned channel7 : 11;
  unsigned channel8 : 11;
  unsigned channel9 : 11;
  unsigned channel10 : 11;
  unsigned channel11 : 11;
  unsigned channel12 : 11;
  unsigned channel13 : 11;
  unsigned channel14 : 11;
  unsigned channel15 : 11;
  unsigned channel16 : 11;
} PACKED fport_channels_t;

class fport : public SerialIO {
private:
  uint8_t _rxData[FPORT_MAX_PACKET_SIZE];
  fport_channels_t _channelData;

public:
explicit fport(Stream *rxPort, int rxPin = -1, int txPin = -1,
                bool inverted = true);
  void begin() override;
  void processIncoming() override;
  void getChannel(rc_channels_t *channelData) override;
};
#endif