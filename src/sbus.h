/*!
 * @file sbus.h
 * @brief Header file for the SBUS protocol implementation.
 */

#pragma once
#ifndef SBUS_H
#define SBUS_H

#include "SerialIO.h" // Include header file for the serial IO class

#define HEADER_SBUS 0x0F        ///< SBUS Header Byte
#define FOOTER_SBUS 0x00        ///< SBUS Footer Byte
#define SBUS_BAUDRATE 100000    ///< SBUS baudrate
#define SBUS_MAX_PACKET_SIZE 25 ///< SBUS packet length

typedef struct sbus_channels_s {
  unsigned header : 8;
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
  unsigned dummy : 4;
  unsigned failsafe : 1;
  unsigned framelost : 1;
  unsigned channel17 : 1;
  unsigned channel18 : 1;
  unsigned footer : 8;
} PACKED sbus_channels_t;

/**
 * @brief A class for handling SBUS protocol communication.
 */
class sbus : public SerialIO {
private:
  sbus_channels_t channelData;
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
  void getChannel(void *channelData) override;
};

#endif // SBUS_H
