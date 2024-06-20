/*!
 * @file SerialIO.h
 * @brief Header file for serial input/output (IO) functionality.
 */
#pragma once
#ifndef SerialIO_H
#define SerialIO_H
#include "crsf_protocol.h"
#include <Arduino.h>

/**************************************************************************/
/*!
    @brief  Class that stores state and functions for initialising and decoding
   rc protocol
*/
/**************************************************************************/
class SerialIO {
public:
  /**
   * @brief Constructor for the SerialIO class.
   *
   * Initializes the pins and sets up the serial port.
   *
   * @param rxPort Pointer to the hardware serial port to use.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not
   * (false).
   */
  SerialIO(Stream *rxPort, int rxPin, int txPin, bool inverted);

  virtual ~SerialIO();

  /**************************************************************************/
  /*!
      @brief Initialises the pins and setup serial port.
  */
  /**************************************************************************/
  virtual void begin();
  /**************************************************************************/
  /*!
      @brief decode the incoming serial data.
  */
  /**************************************************************************/
  virtual void processIncoming();
  /**************************************************************************/
  /*!
      @brief Gives the decoded rc channels
      @param  channelData
              A pointer to a crsf_channels_t struct where the decoded channel
     data will be stored.

  */
  /**************************************************************************/
  virtual void getChannel(crsf_channels_t *channelData) = 0;

  virtual void writeChannel(crsf_channels_t channelData);

protected:
  Stream
      *_rxPort; // Pointer to the hardware serial port used for communication.
  bool _headerDetected; // Flag indicating whether a header has been detected
                        // in the incoming data.
  bool _inverted;   // Indicates whether the serial signal is inverted (true) or
                    // not (false).
  uint8_t _rxIndex; // Index for the receive_buffer.
  int _rxPin;       // The RX pin number.
  int _txPin;       // The TX pin number.
  uint8_t _buffer;
  uint8_t _prevBuffer;
};
#include "crsf.h"
#include "ibus.h"
#include "sbus.h"

#endif
