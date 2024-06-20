/*!
 * @file ibus_basic.ino
 */
#include <SerialIO.h>

crsf_channels_t channelData;

SerialIO *receiver = nullptr;

void setup() { 
  receiver = new ibus(&Serial1, 16);
  receiver->begin();
}

void loop() {
  receiver->processIncoming();
  receiver->getChannel(&channelData);
}
