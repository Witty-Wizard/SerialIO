#include "crsf.h"

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
  while (_rxPort->available()) {
    _rxData[CRSF_MAX_PACKET_SIZE - 1] = _rxPort->read();
    if ((_rxData[0] == CRSF_ADDRESS_CRSF_TRANSMITTER ||
         _rxData[0] == CRSF_ADDRESS_CRSF_TRANSMITTER) &&
        (crc8(&_rxData[2], _rxData[1]) == 0)) {
      memcpy(&channelData, &_rxData[3], sizeof(channelData));
    }
    else{
      leftShift(_rxData,sizeof(_rxData));
    }
  }
}

void crsf::getChannel(void *channelData) {
  *static_cast<decltype(this->channelData) *>(channelData) = this->channelData;
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