#include "crsf.h"

explicit crsf::crsf(HardwareSerial &rxPort, int rxPin, int txPin,
                    bool inverted = true)
    : serialIO(&rxPort, rxPin, txPin, inverted) {
  _rxData = new uint8_t[CRSF_MAX_PACKET_SIZE];
}

void crsf::begin() {
  _rxPort->begin(CRSF_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
}

void crsf::processIncoming() {
  while (_rxPort->available()) {
    _buffer = _rxPort->read();
    if (_headerDetected) {
      _rxData[_rxIndex] = _buffer;
      _rxIndex++;
      if (_rxIndex > _rxData[1] + 2)

      {
        _rxIndex = 0;
        _headerDetected = false;
      }
    } else {
      if (_buffer == CRSF_ADDRESS_FLIGHT_CONTROLLER ||
          _buffer == CRSF_ADDRESS_CRSF_TRANSMITTER) {
        _headerDetected = true;
        _rxData[0] = _buffer;
        _rxIndex = 1;
      }
    }

    if (_rxIndex == sizeof(_rxData) / sizeof(_rxData[0])) {
      _rxIndex = 0;
      _headerDetected = false;
    }
  }
}

void crsf::getChannel(crsf_channels_t *channelData) {
  memcpy(channelData, _rxData + 3, sizeof(*channelData));
}