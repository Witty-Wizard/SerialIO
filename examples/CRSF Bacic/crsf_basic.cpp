#include <Arduino.h>
#include <crsf/crsf.h>
#include <sbus/sbus.h>
#include <serialIO.h>

crsf_channels_t channelData;

serialIO *receiver = new crsf(Serial1, 16, 17);

void setup() { receiver->begin(); }

void loop() {
  receiver->processIncoming();
  receiver->getChannel(&channelData);
}
