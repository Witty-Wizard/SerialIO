

# File sbus.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**sbus.h**](sbus_8h.md)

[Go to the documentation of this file](sbus_8h.md)


```C++

#pragma once
#ifndef SBUS_H
#define SBUS_H

#include "crsf_protocol.h" // Include header file for CRSF protocol
#include "SerialIO.h"      // Include header file for the serial IO class

#define HEADER_SBUS 0X0F        
#define FOOTER_SBUS 0X00        
#define SBUS_BAUDRATE 100000    
#define SBUS_MAX_PACKET_SIZE 25 

class sbus : public SerialIO {
private:
  uint8_t _rxData[SBUS_MAX_PACKET_SIZE];

public:
  explicit sbus(HardwareSerial &rxPort, int rxPin, int txPin = -1,
                bool inverted = true)
      : SerialIO(&rxPort, rxPin, txPin, inverted){};

  virtual ~sbus(){};

  void begin() override;

  void processIncoming() override;

  void getChannel(crsf_channels_t *channelData) override;
};

#endif // SBUS_H
```


