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
  serialPort->setInvertRX(_inverted);
  serialPort->setInvertTX(_inverted);
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
    }
    leftShift(_rxData, sizeof(_rxData));

    _lastPacketTime = millis();
    _connectionTimeout = false;
  }

  if (millis() - _lastPacketTime > SBUS_TIMEOUT) {
    _connectionTimeout = true;
  }
}

void sbus::getChannel(rc_channels_t *channelData) {
  memcpy(channelData, (uint8_t *)&_channelData + 1, sizeof(rc_channels_t));
}

bool sbus::getFailsafe() {
  return _channelData.failsafe;
}

bool sbus::getFramelost() {
  return _channelData.framelost;
}

bool sbus::getChannel17() {
  return _channelData.channel17;
}

bool sbus::getChannel18() {
  return _channelData.channel18;
}

bool sbus::getSerialConnectionStatus() {
  return !_connectionTimeout;
}