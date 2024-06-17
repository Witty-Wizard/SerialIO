/*!
 * @file ibus.h
 * @brief Header file for the Ibus protocol implementation.
 */

#pragma once
#ifndef IBUS_H
#define IBUS_H

#include "SerialIO.h" // Include header file for the serial IO class

#define IBUS_MAX_PACKET_SIZE 32 ///< Maximum packet size for the IBUS protocol
#define IBUS_BAUDRATE 115200    ///< Baud rate for IBUS communication

/**
 * @brief A class for handling IBUS protocol communication.
 */
class ibus : public SerialIO {
private:
  uint8_t _rxData[IBUS_MAX_PACKET_SIZE]; ///< Buffer to store received IBUS data

public:
  /**
   * @brief Constructor for the IBUS class.
   * @param rxPort Reference to the hardware serial port for RX communication.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not
   * (false).
   */
  explicit ibus(Stream *rxPort, int rxPin, int txPin = -1,
                bool inverted = false);

  /**
   * @brief Initializes the IBUS communication.
   */
  void begin() override;

  /**
   * @brief Processes incoming IBUS data.
   */
  void processIncoming() override;

  /**
   * @brief Gets the decoded RC channels from the IBUS data.
   * @param channelData Pointer to a crsf_channels_t struct where the decoded
   * channel data will be stored.
   */
  void getChannel(crsf_channels_t *channelData) override;
};

#endif // IBUS_H
