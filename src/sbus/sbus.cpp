/*!
 * @file sbus.cpp
 * @brief Source file for the SBus implementations
 * @author Witty-Wizard
 */
#include "sbus.h"

sbus::sbus(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : SerialIO(rxPort, rxPin, txPin, inverted) {}

void sbus::begin() {

// Initialize the serial port
#if defined(ARDUINO_ARCH_ESP32)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->begin(SBUS_BAUDRATE, SERIAL_8E2, _rxPin, _txPin, _inverted);
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->setPinout(_txPin, _rxPin);
  serialPort->begin(SBUS_BAUDRATE, SERIAL_8E2);
#else
#warning "Unsupported hardware platform."
#endif
}

void sbus::processIncoming() {
  while (_rxPort->available()) {
    _rxData[SBUS_MAX_PACKET_SIZE - 1] = _rxPort->read();
    if (_rxData[0] == HEADER_SBUS &&
        _rxData[SBUS_MAX_PACKET_SIZE - 1] == FOOTER_SBUS) {
      memcpy(&_channelData, _rxData, sizeof(_channelData));
    } else {
      leftShift(_rxData, sizeof(_rxData));
    }
  }
}

void sbus::getChannel(void *channelData) {
  *static_cast<decltype(_channelData) *>(channelData) = _channelData;
}

void sbus::leftShift(uint8_t arr[], size_t size) {
  memmove(arr, arr + 1, (size - 1));
  arr[size - 1] = 0xFF;
}