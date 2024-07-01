/*!
 * @file sbus.h
 * @brief Header file for the SBUS protocol implementation.
 */

#pragma once
#ifndef SBUS_H
#define SBUS_H

#include "../SerialIO.h" // Include header file for the serial IO class
#include "sbus_protocol.h"

/**
 * @brief A class for handling SBUS protocol communication.
 */
class sbus : public SerialIO {
private:
  sbus_channels_t _channelData;
  uint8_t _rxData[SBUS_MAX_PACKET_SIZE];

public:
  /**
   * @brief Constructor for the SBUS class.
   * @param rxPort Reference to the hardware serial port for RX communication.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not
   * (false).
   */
  explicit sbus(Stream *rxPort, int rxPin = -1, int txPin = -1,
                bool inverted = true);

  /**
   * @brief Initializes the SBUS communication.
   */
  void begin() override;

  /**
   * @brief Processes incoming SBUS data.
   */
  void processIncoming() override;

  /**
   * @brief Gets the decoded RC channels from the SBUS data.
   * @param channelData Pointer to a crsf_channels_t struct where the decoded
   * channel data will be stored.
   */
  void getChannel(rc_channels_t *channelData) override;
};

#endif // SBUS_H
