

# File crsf\_basic.ino

[**File List**](files.md) **>** [**crsf\_basic**](dir_e1cdda853dfed1aec62f8d7bad60d1ed.md) **>** [**crsf\_basic.ino**](crsf__basic_8ino.md)

[Go to the documentation of this file](crsf__basic_8ino.md)


```C++
/*!
 * @file crsf_basic.ino
 */
#include <SerialIO.h>

crsf_channels_t channelData;

SerialIO *receiver = nullptr;

void setup() { 
  receiver = new crsf(Serial1, 16);
  receiver->begin();
}

void loop() {
  receiver->processIncoming();
  receiver->getChannel(&channelData);
}
```


