#include "sbus.h"

void sbus::begin() {
  HardwareSerial* serialPort = static_cast<HardwareSerial*>(_rxPort);

  // Initialize the serial port
  serialPort->begin(SBUS_BAUDRATE, SERIAL_8E2, _rxPin, _txPin, _inverted);
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
}

void sbus::getChannel(crsf_channels_t *channelData) {
  memcpy(channelData, _rxData + 1, sizeof(*channelData));
}