/*!
 * @file crsf.h
 * @brief Header file for the CRSF protocol implementation.
 */

#pragma once
#ifndef CRSF_H
#define CRSF_H

#include "crsf_protocol.h" // Include header file for CRSF protocol
#include <serialIO.h>       // Include header file for the serial IO class

/**
 * @brief A class for handling CRSF protocol communication.
 */
class crsf : public serialIO {
private:
  bool header_detected; ///< Flag indicating whether the CRSF header has been detected
  uint8_t rx_index;     ///< Index for RX buffer
  uint8_t rx_data[CRSF_MAX_PACKET_SIZE]; ///< RX data buffer for CRSF communication

public:
  /**
   * @brief Constructor for the CRSF class.
   * @param rxPort Reference to the hardware serial port for RX communication.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not (false).
   */
  explicit crsf(HardwareSerial &rxPort, int rxPin, int txPin, bool inverted = false)
      : serialIO(&rxPort, rxPin, txPin, inverted){};

  virtual ~crsf(){};

  /**
   * @brief Initializes the CRSF communication.
   */
  void begin() override;

  /**
   * @brief Processes incoming CRSF data.
   */
  void processIncoming() override;

  /**
   * @brief Retrieves the decoded RC channels from the received CRSF data.
   * @param channelData Pointer to a crsf_channels_t struct where the decoded channel data will be stored.
   */
  void getChannel(crsf_channels_t *channelData) override;
};

#endif // CRSF_H
