

# File sbus\_basic.ino

[**File List**](files.md) **>** [**examples**](dir_d28a4824dc47e487b107a5db32ef43c4.md) **>** [**sbus\_basic**](dir_55843c87c0f105b5d66edf3dd90084e2.md) **>** [**sbus\_basic.ino**](sbus__basic_8ino.md)

[Go to the documentation of this file](sbus__basic_8ino.md)


```C++
/*!
 * @file sbus_basic.ino
 */
#include <SerialIO.h>

crsf_channels_t channelData;

SerialIO *receiver = nullptr;

void setup() { 
  receiver = new sbus(Serial1, 16)
  receiver->begin();
}

void loop() {
  receiver->processIncoming();
  receiver->getChannel(&channelData);
}
```


