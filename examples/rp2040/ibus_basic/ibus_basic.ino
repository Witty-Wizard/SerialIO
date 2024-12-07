/*!
 * @file ibus_basic.ino
 */
/*

# Sample platformio.ini file:
# ---------------------------
[platformio]
default_envs = ws-rp2040-zero

[env:ws-rp2040-zero]
platform = https://github.com/maxgerhardt/platform-raspberrypi.git
board = waveshare_rp2040_pizero
framework = arduino
board_build.core = earlephilhower
monitor_speed = 115200

lib_deps =
  https://github.com/Witty-Wizard/SerialIO
*/

#include <SerialIO.h>

#define SBUS_TX_PIN 0
#define SBUS_RX_PIN 1

rc_channels_t rcdata;
ibus receiver(&Serial1, SBUS_RX_PIN, SBUS_TX_PIN,
              true); // RP2040 requires the TX_PIN so to not hang up the mcu

void setup() {
  // setup sbus receiver
  receiver.begin();

  Serial.begin(115200);
}

void loop() {
  static unsigned long last_millis = millis();

  receiver.processIncoming();
  receiver.getChannel(&rcdata);

  if (millis() > last_millis + 100) {
    Serial.printf("RC: %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d",
                  rcdata.channel1, rcdata.channel2, rcdata.channel3,
                  rcdata.channel4, rcdata.channel5, rcdata.channel6,
                  rcdata.channel7, rcdata.channel8, rcdata.channel9,
                  rcdata.channel10, rcdata.channel11, rcdata.channel12,
                  rcdata.channel13, rcdata.channel14);
    Serial.println();
    last_millis = millis();
  }
}
