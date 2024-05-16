

# File SerialIO.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**SerialIO.h**](SerialIO_8h.md)

[Go to the documentation of this file](SerialIO_8h.md)


```C++

#pragma once
#ifndef SerialIO_H
#define SerialIO_H
#include "crsf_protocol.h"
#include <Arduino.h>

/**************************************************************************/
/**************************************************************************/
class SerialIO {
public:
  SerialIO(HardwareSerial *rxPort, int rxPin, int txPin, bool inverted)
      : _rxPort(rxPort), _rxPin(rxPin), _txPin(txPin), _inverted(inverted){};

  virtual ~SerialIO(){};

  /**************************************************************************/
  /**************************************************************************/
  virtual void begin();
  /**************************************************************************/
  /**************************************************************************/
  virtual void processIncoming();
  /**************************************************************************/
  /**************************************************************************/
  virtual void getChannel(crsf_channels_t *channelData);

protected:
  HardwareSerial
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
#include "sbus.h"
#include "crsf.h"
#endif
```


