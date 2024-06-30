/*!
 * @file ibus.h
 * @brief Header file for the Ibus protocol implementation.
 */

#pragma once
#ifndef IBUS_H
#define IBUS_H

#include "../SerialIO.h" // Include header file for the serial IO class

#define IBUS_MAX_PACKET_SIZE 32 ///< Maximum packet size for the IBUS protocol
#define IBUS_BAUDRATE 115200    ///< Baud rate for IBUS communication
#define IBUS_HEADER1 0x20
#define IBUS_HEADER2 0x40

typedef struct ibus_channels_s {
  unsigned header : 16;
  unsigned channel1 : 16;
  unsigned channel2 : 16;
  unsigned channel3 : 16;
  unsigned channel4 : 16;
  unsigned channel5 : 16;
  unsigned channel6 : 16;
  unsigned channel7 : 16;
  unsigned channel8 : 16;
  unsigned channel9 : 16;
  unsigned channel10 : 16;
  unsigned channel11 : 16;
  unsigned channel12 : 16;
  unsigned channel13 : 16;
  unsigned channel14 : 16;
  unsigned checksum : 16;
} PACKED ibus_channels_t;

/**
 * @brief A class for handling IBUS protocol communication.
 */
class ibus : public SerialIO {
private:
  ibus_channels_t _channelData;
  uint8_t _rxData[IBUS_MAX_PACKET_SIZE]; ///< Buffer to store received IBUS data
  bool checkSum();

public:
  /**
   * @brief Constructor for the IBUS class.
   * @param rxPort Reference to the hardware serial port for RX communication.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not
   * (false).
   */
  explicit ibus(Stream *rxPort, int rxPin = -1, int txPin = -1,
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
  void getChannel(void *channelData) override;
};

#endif // IBUS_H
