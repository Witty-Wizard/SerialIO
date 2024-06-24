/*!
 * @file sbus_basic.ino
 */
#include <SerialIO.h>
#define RX_PIN 16

sbus_channels_t channelData;

sbus receiver(&Serial1,RX_PIN);

void setup() { 
  receiver.begin();
  Serial.begin(9600);
}

void loop() {
  receiver.processIncoming();
  receiver.getChannel(&channelData);

  Serial.print("Channel 1: ");
  Serial.print(channelData.channel1);
  Serial.print(" Channel 2: ");
  Serial.print(channelData.channel2);
  Serial.print(" Channel 3: ");
  Serial.print(channelData.channel3);
  Serial.print(" Channel 4: ");
  Serial.println(channelData.channel4);

}
