/*!
 * @file crsf.h
 * @brief Header file for the CRSF protocol implementation.
 */

#pragma once
#ifndef CRSF_H
#define CRSF_H
#include "crsf_protocol.h"
#include <serialIO.h>

#include "SerialIO.h"      // Include header file for the serial IO class
#include "crsf_protocol.h" // Include header file for CRSF protocol

#define CRC8_POLY_D5 0xD5

/**
 * @brief A class for handling CRSF protocol communication.
 */
class crsf : public SerialIO {
private:
  uint8_t _rxData[CRSF_MAX_PACKET_SIZE];

public:
  /**
   * @brief Constructor for the CRSF class.
   * @param rxPort Reference to the hardware serial port for RX communication.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not
   * (false).
   */
  explicit crsf(Stream *rxPort, int rxPin, int txPin = -1,
                bool inverted = false);

  virtual ~crsf(){};

  void begin() override;
  void processIncoming() override;

  /**
   * @brief Retrieves the decoded RC channels from the received CRSF data.
   * @param channelData Pointer to a crsf_channels_t struct where the decoded
   * channel data will be stored.
   */
  void getChannel(crsf_channels_t *channelData) override;

  uint8_t crc8(uint8_t *data, uint8_t len);
};

#endif