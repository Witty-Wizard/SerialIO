#include "crsf.h"
#include <iostream>

crsf::crsf(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : SerialIO(rxPort, rxPin, txPin, inverted){};

void crsf::begin() {

// Initialize the serial port
#if defined(ARDUINO_ARCH_ESP32)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->begin(CRSF_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->setPinout(_txPin, _rxPin);
  serialPort->begin(CRSF_BAUDRATE, SERIAL_8N1);
#else
#warning #warning "Unsupported hardware platform."
#endif
}

void crsf::processIncoming() {
  uint8_t size = CRSF_MAX_PACKET_SIZE;
  while (_rxPort->available()) {
    _rxData[CRSF_MAX_PACKET_SIZE - 1] = _rxPort->read();
    if (crc8(&_rxData[CRSF_MAX_PACKET_SIZE - size],
             _rxData[CRSF_MAX_PACKET_SIZE - size - 1]) == 0) {
      if ((_rxData[CRSF_MAX_PACKET_SIZE - size - 2] ==
           CRSF_ADDRESS_FLIGHT_CONTROLLER) ||
          (_rxData[CRSF_MAX_PACKET_SIZE - size - 2] ==
           CRSF_ADDRESS_CRSF_TRANSMITTER)) {
        if (_rxData[CRSF_MAX_PACKET_SIZE - size] ==
            CRSF_FRAMETYPE_RC_CHANNELS_PACKED) {
          memcpy(&_channelData, &_rxData[CRSF_MAX_PACKET_SIZE - size + 1],
                 sizeof(_channelData));
        }
      }
    }

    if (_rxData[CRSF_MAX_PACKET_SIZE - 1] == CRSF_ADDRESS_CRSF_TRANSMITTER ||
        _rxData[CRSF_MAX_PACKET_SIZE - 1] == CRSF_ADDRESS_FLIGHT_CONTROLLER) {
      leftShift(_rxData, sizeof(_rxData));
    } else if (_rxData[CRSF_MAX_PACKET_SIZE - 2] ==
                   CRSF_ADDRESS_CRSF_TRANSMITTER ||
               _rxData[CRSF_MAX_PACKET_SIZE - 2] ==
                   CRSF_ADDRESS_FLIGHT_CONTROLLER) {
      size = _rxData[CRSF_MAX_PACKET_SIZE - 1];
      leftShift(_rxData, sizeof(_rxData));
    } else {
      leftShift(_rxData, sizeof(_rxData));
    }
  }
}

void crsf::getChannel(rc_channels_t *channelData) {
  memcpy(channelData, &_channelData, sizeof(rc_channels_t));
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