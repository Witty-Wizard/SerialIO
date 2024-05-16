

# File crsf.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**crsf.h**](crsf_8h.md)

[Go to the documentation of this file](crsf_8h.md)


```C++

#pragma once
#ifndef CRSF_H
#define CRSF_H

#include "crsf_protocol.h" // Include header file for CRSF protocol
#include "SerialIO.h"      // Include header file for the serial IO class

#define CRC8_POLY_D5 0xD5

class crsf : public SerialIO {
private:
  uint8_t _rxData[CRSF_MAX_PACKET_SIZE];

public:
  explicit crsf(HardwareSerial &rxPort, int rxPin, int txPin = -1,
                bool inverted = false)
      : SerialIO(&rxPort, rxPin, txPin, inverted){};

  virtual ~crsf(){};

  void begin() override;

  void processIncoming() override;

  void getChannel(crsf_channels_t *channelData) override;

  uint8_t crc8(uint8_t *data, uint8_t len);
};

#endif // CRSF_H
```


