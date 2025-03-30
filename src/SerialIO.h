/**
 * @file SerialIO.h
 * @brief Header file for SerialIO class, providing serial input/output (IO) functionality.
 * 
 * @author WittyWizard
 */

#pragma once
#ifndef SerialIO_H
#define SerialIO_H

#include <Arduino.h>
#include <ibus/ibus_protocol.h>

#define PACKED __attribute__((packed))

/**
 * @brief Structure representing 16 RC channels using 11-bit values.
 */
typedef struct rc_channels_s
{
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
} PACKED rc_channels_t;

/**
 * @brief Class providing methods for initializing and decoding RC protocols.
 */
class SerialIO
{
public:
  /**
   * @brief Constructor to initialize the SerialIO class.
   *
   * @param rxPort Pointer to the hardware serial port to use.
   * @param rxPin RX pin number.
   * @param txPin TX pin number.
   * @param inverted Set to true if the serial signal is inverted.
   */
  SerialIO(Stream *rxPort, int rxPin, int txPin, bool inverted);

  /**
   * @brief Virtual destructor.
   */
  virtual ~SerialIO();

  /**
   * @brief Initialize pins and set up the serial port.
   */
  virtual void begin() = 0;

  /**
   * @brief Process incoming serial data and decode it.
   */
  virtual void processIncoming() = 0;

  /**
   * @brief Retrieve the current channel data.
   *
   * @param[out] channelData Pointer to an rc_channels_t structure to store the retrieved channel data.
   *
   * @note The structure contains 16 channels, each represented as an 11-bit unsigned integer with a maximum value of 2047.
   */
  virtual void getChannel(rc_channels_t *channelData) = 0;

  /**
   * @brief Retrieve the current channel data using ibus_channels_t.
   *
   * @param[out] channelData Pointer to an ibus_channels_t structure to store the channel data.
   */
  virtual void getChannel(ibus_channels_t *channelData);

protected:
  Stream *_rxPort; ///< Pointer to the hardware serial port used for communication.
  bool _inverted;  ///< Indicates whether the serial signal is inverted.
  int _rxPin;      ///< RX pin number.
  int _txPin;      ///< TX pin number.

  /**
   * @brief Perform a left shift operation on the given byte array.
   *
   * @param arr Pointer to the byte array.
   * @param size Size of the array.
   */
  void leftShift(uint8_t arr[], size_t size);

  /**
   * @brief Perform a right shift operation on the given byte array.
   *
   * @param arr Pointer to the byte array.
   * @param size Size of the array.
   */
  void rightShift(uint8_t arr[], size_t size);
};

#include "crsf/crsf.h"
#include "fport/fport.h"
#include "ibus/ibus.h"
#include "sbus/sbus.h"

#endif // SerialIO_H
