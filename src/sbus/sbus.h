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
  uint32_t _lastPacketTime = 0;
  bool _connectionTimeout = false;

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
  void processIncoming() override;

  /**
   * @brief Gets the decoded RC channels from the SBUS data.
   * @param channelData Pointer to a crsf_channels_t struct where the decoded
   * channel data will be stored.
   */
  void getChannel(rc_channels_t *channelData) override;

  /**
   * @brief Gets the failsafe status from the SBUS data.
   * @param failsafeData Pointer to a failsafe_t struct where the failsafe
   * status will be stored.
   */
  void getFailsafe(failsafe_t *failsafeData);

    /**
   * @brief Gets the failsafe status from the SBUS data.
   * @return True if failsafe is active, false otherwise.
   */
  bool getFailsafe();

  /**
   * @brief Gets the frame lost status from the SBUS data.
   * @return True if frame lost is active, false otherwise.
   */
  bool getFramelost();

  /**
   * @brief Gets the channel 17 status from the SBUS data.
   * @return True if channel 17 is active, false otherwise.
   */
  bool getChannel17();

  /**
   * @brief Gets the channel 18 status from the SBUS data.
   * @return True if channel 18 is active, false otherwise.
   */
  bool getChannel18();

  /**
   * @brief Gets the serial connection status.
   * @return True if the connection is active, false if it has timed out.
   */
  bool getSerialConnectionStatus();
};

#endif