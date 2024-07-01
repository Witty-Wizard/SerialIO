/*!
 * @file fport.cpp
 * @brief Source file for the F.Port implementations
 * @author Witty-Wizard
 */

#include "fport.h"

fport::fport(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : SerialIO(rxPort, rxPin, txPin, inverted) {}

void fport::begin() {

// Initialize the serial port
#if defined(ARDUINO_ARCH_ESP32)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->begin(FPORT_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->setPinout(_txPin, _rxPin);
  serialPort->begin(FPORT_BAUDRATE, SERIAL_8N1);
#else
#warning "Unsupported hardware platform."
#endif
}

void fport::processIncoming() {
  uint8_t size = FPORT_MAX_PACKET_SIZE;
  while (_rxPort->available()) {
    _rxData[FPORT_MAX_PACKET_SIZE - 1] = _rxPort->read();
    if (_rxData[FPORT_MAX_PACKET_SIZE - size - 4] == FPORT_END_BYTES &&
        _rxData[FPORT_MAX_PACKET_SIZE - 1] == FPORT_END_BYTES) {
      if (_rxData[FPORT_MAX_PACKET_SIZE - size - 2] ==
          FPORT_FRAMETYPE_RC_CHANNELS_PACKED) {
        memcpy(&_channelData, &_rxData[FPORT_MAX_PACKET_SIZE - size - 1],
               sizeof(_channelData));
      }
    }
    if (_rxData[FPORT_MAX_PACKET_SIZE - 2] == FPORT_END_BYTES) {
      size = _rxData[FPORT_MAX_PACKET_SIZE - 1];
    } 
      leftShift(_rxData, sizeof(_rxData));
  }
}

void fport::getChannel(rc_channels_t *channelData) {
  memcpy(channelData, &_channelData, sizeof(rc_channels_t));
}

void fport::crc() {}