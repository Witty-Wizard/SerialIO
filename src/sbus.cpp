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
#warning #warning "Unsupported hardware platform."
#endif
}

void sbus::processIncoming() {
  while (_rxPort->available()) {
    _prevBuffer = _buffer;
    _buffer = _rxPort->read();

    if (_headerDetected == true) {
      _rxData[_rxIndex] = _buffer;
      _rxIndex++;
      if (_rxIndex > 23) {
        _headerDetected = false;
      }
    } else {
      if (_prevBuffer == FOOTER_SBUS && _buffer == HEADER_SBUS) {
        _headerDetected = true;
        _rxData[0] = 0x0F;
        _rxData[24] = 0x00;
        _rxIndex = 1;
      }
    }

    if (_rxIndex == sizeof(_rxData) / sizeof(_rxData[0])) {
      _rxIndex = 0;
      _headerDetected = false;
    }
  }
  memcpy(&channelData, _rxData + 1, sizeof(channelData));
}

void sbus::getChannel(crsf_channels_t *channelData) {
  *channelData = this->channelData;
}