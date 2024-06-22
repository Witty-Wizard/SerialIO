/*!
 * @file ibus_basic.ino
 */
#include <SerialIO.h>

crsf_channels_t channelData;

ibus receiver(&Serial);

void setup() { 
  receiver.begin();
}

void loop() {
  receiver.processIncoming();
  receiver.getChannel(&channelData);
}

