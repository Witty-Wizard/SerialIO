/*!
 * @file crsf_basic.ino
 */
#include <SerialIO.h>

rc_channels_t channelData;

crsf receiver(&Serial);

void setup() { 
  receiver.begin();
}

void loop() {
  // setup crsf receiver
  receiver.processIncoming();
  receiver.getChannel(&channelData);

  // `channelData` now contains the latest RC channel values
  // You can use them by accessing the channelData e.g. channelData.channel1 to channelData.channel16
}

