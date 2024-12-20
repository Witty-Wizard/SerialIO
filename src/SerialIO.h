/*!
 * @file SerialIO.h
 * @brief Header file for serial input/output (IO) functionality.
 */
#pragma once
#ifndef SerialIO_H
#define SerialIO_H
#include <Arduino.h>
#include <ibus/ibus_protocol.h>
#define PACKED __attribute__((packed))

typedef struct rc_channels_s {
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
  virtual void begin() = 0;
  /**************************************************************************/
  /*!
      @brief decode the incoming serial data.
  */
  /**************************************************************************/
  virtual void processIncoming() = 0;
  /**************************************************************************/
  /*!
      @brief Get the ChannelData.
  */
  /**************************************************************************/
  virtual void getChannel(rc_channels_t *channelData) = 0;

  /*!
      @brief Get the ChannelData.
  */
  /**************************************************************************/
  virtual void getChannel(ibus_channels_t *channelData);

protected:
  Stream
      *_rxPort;   // Pointer to the hardware serial port used for communication.
  bool _inverted; // Indicates whether the serial signal is inverted (true) or
                  // not (false).
  int _rxPin;     // The RX pin number.
  int _txPin;     // The TX pin number.
  void leftShift(uint8_t arr[], size_t size);
  void rightShift(uint8_t arr[], size_t size);
};
#include "crsf/crsf.h"
#include "fport/fport.h"
#include "ibus/ibus.h"
#include "sbus/sbus.h"

#endif
