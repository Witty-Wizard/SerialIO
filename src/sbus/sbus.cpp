#include "sbus.h"

void sbus::begin() {
  _rxPort->begin(SBUS_BAUDRATE, SERIAL_8E2, _rxPin, _txPin, _inverted);
}

void sbus::processIncoming() {
  while (_rxPort->available()) {
    _prevBuffer = _buffer;
    _buffer = _rxPort->read();

    if (_headerDetected == true) {
      __rxData[_rxIndex] = _buffer;
      _rxIndex++;
      if (_rxIndex > 23) {
        _headerDetected = false;
      }
    } else {
      if (_prevBuffer == FOOTER_SBUS && _buffer == HEADER_SBUS) {
        _headerDetected = true;
        __rxData[0] = 0x0F;
        __rxData[24] = 0x00;
        _rxIndex = 1;
      }
    }

    if (_rxIndex == sizeof(__rxData) / sizeof(__rxData[0])) {
      _rxIndex = 0;
      _headerDetected = false;
    }
  }
}

void sbus::getChannel(crsf_channels_t *channelData) {
  memcpy(channelData, __rxData + 1, sizeof(*channelData));
}