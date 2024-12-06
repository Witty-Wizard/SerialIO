#include "SerialIO.h"

SerialIO::SerialIO(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : _rxPort(rxPort), _rxPin(rxPin), _txPin(txPin), _inverted(inverted) {
  // Constructor implementation
}

SerialIO::~SerialIO() {
// End serial communication
#if defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_ARCH_AVR)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->end();
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->end();
#else
#warning "Unsupported hardware platform."
#endif
}

void SerialIO::leftShift(uint8_t arr[], size_t size) {
  memmove(arr, arr + 1, (size - 1));
  arr[size - 1] = 0xFF;
}

void SerialIO::rightShift(uint8_t arr[], size_t size) {
  memmove(arr + 1, arr, size - 1);
  arr[0] = 0xFF;
}

void SerialIO::getChannel(ibus_channels_t *channelData) {}