#include "crsf.h"

void crsf::begin() {
  HardwareSerial* serialPort = static_cast<HardwareSerial*>(_rxPort);

  // Initialize the serial port
  serialPort->begin(CRSF_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
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
  if(crc8(&_rxData[2],_rxData[1]) == 0)
    memcpy(channelData, &_rxData[3], sizeof(*channelData));
}

uint8_t crsf::crc8(uint8_t *data, uint8_t len) {
    uint8_t crc = 0;
    for (uint8_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ CRC8_POLY_D5;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}