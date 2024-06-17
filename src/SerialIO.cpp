#include "SerialIO.h"

SerialIO::SerialIO(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : _rxPort(rxPort), _rxPin(rxPin), _txPin(txPin), _inverted(inverted) {
  // Constructor implementation
}

SerialIO::~SerialIO() {
// End serial communication
#if defined(ARDUINO_ARCH_ESP32)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->end();
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->end();
#else
#error                                                                         \
    "Unsupported hardware platform. This Sbus is supported on ESP32 and RP2040 architectures only."
#endif
}

void SerialIO::begin() {
  // Initialize pins and setup serial port
}

void SerialIO::processIncoming() {
  // Decode the incoming serial data
  // This function can be empty if actual decoding is implemented in subclasses
}

void SerialIO::getChannel(crsf_channels_t *channelData) {
  // Get the decoded RC channels
  // This function can be empty if actual decoding is implemented in subclasses
}

void SerialIO::writeChannel(crsf_channels_t channelData) {
#if defined(ARDUINO_ARCH_ESP32)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
#else
#error                                                                         \
    "Unsupported hardware platform. This Sbus is supported on ESP32 and RP2040 architectures only."
#endif
  serialPort->write((uint8_t *)&channelData, sizeof(channelData));
}