/*!
 * @file serialIO.h
 *
 * @mainpage SerialIO
 * @section intro_sec Introduction
 * @brief A versatile Arduino library that provides support for decoding multiple RC
 * protocols.
 *
 * SerialIO is a common library designed to simplify the implementation of RC protocol
 * decoding in Arduino projects. It provides a modular and extensible architecture
 * that allows for easy integration of various RC protocols.
 *
 * @section author Author
 * Written by Witty Wizard
 * @section license License
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once
#ifndef SERIALIO_H
#define SERIALIO_H
#include "crsf/crsf_protocol.h"
#include <Arduino.h>

/**************************************************************************/
/*!
    @brief  Class that stores state and functions for initialising and decoding rc protocol
*/
/**************************************************************************/
class serialIO
{
public:
  /**
   * @brief Constructor for the serialIO class.
   *
   * Initializes the pins and sets up the serial port.
   *
   * @param rxPort Pointer to the hardware serial port to use.
   * @param rxPin The RX pin number.
   * @param txPin The TX pin number.
   * @param inverted Whether the serial signal is inverted (true) or not (false).
   */
  serialIO(HardwareSerial *rxPort, int rxPin, int txPin, bool inverted)
      : _rxPort(rxPort), _rxPin(rxPin), _txPin(txPin), _inverted(inverted){};

  virtual ~serialIO(){};

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
              A pointer to a crsf_channels_t struct where the decoded channel data will be stored.

  */
  /**************************************************************************/
  virtual void getChannel(crsf_channels_t *channelData);

protected:
  HardwareSerial *_rxPort; // Pointer to the hardware serial port used for communication.
  bool _inverted;          // Indicates whether the serial signal is inverted (true) or not (false).
  int _rxPin;              // The RX pin number.
  int _txPin;              // The TX pin number.
};
#endif
