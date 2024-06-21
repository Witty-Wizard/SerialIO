/*!
 * @file sbus_basic.ino
 */
#include <SerialIO.h>

crsf_channels_t channelData;

SerialIO *receiver = nullptr;

void setup() { 
  receiver = new sbus(&Serial);
  receiver->begin();
}

void loop() {
  receiver->processIncoming();
  receiver->getChannel(&channelData);
}
