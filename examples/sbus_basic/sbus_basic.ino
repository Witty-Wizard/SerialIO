/*!
 * @file sbus_basic.ino
 */
#include <serialIO.h>

crsf_channels_t channelData;

serialIO *receiver = nullptr;

void setup() { 
  receiver = new sbus(Serial1, 16)
  receiver->begin();
}

void loop() {
  receiver->processIncoming();
  receiver->getChannel(&channelData);
}
