/*!
 * @file sbus.h
 * @brief Header file for the SBUS protocol implementation.
 */

#pragma once
#ifndef SBUS_H
#define SBUS_H

#include "crsf_protocol.h" // Include header file for CRSF protocol
#include "serialIO.h"      // Include header file for the serial IO class

#define HEADER_SBUS 0X0F        ///< SBUS Header Byte
#define FOOTER_SBUS 0X00        ///< SBUS Footer Byte
#define SBUS_BAUDRATE 100000    ///< SBUS baudrate
#define SBUS_MAX_PACKET_SIZE 25 ///< SBUS packet length

/**
 * @brief A class for handling SBUS protocol communication.
 */
class sbus : public serialIO {

public:
  /**
   * @brief Constructor for the SBUS class.
   * @param rxPort Reference to the hardware serial port for RX communication.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not
   * (false).
   */
  explicit sbus(HardwareSerial &rxPort, int rxPin, int txPin,
                bool inverted = true)
      : serialIO(&rxPort, rxPin, txPin, inverted){};

  virtual ~sbus(){};

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
  void getChannel(crsf_channels_t *channelData) override;
};

#endif // SBUS_H
