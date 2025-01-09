/*!
 * @file sbus.cpp
 * @brief Source file for the SBus implementations
 * @author Witty-Wizard
 */
#include "sbus.h"

sbus::sbus(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : SerialIO(rxPort, rxPin, txPin, inverted, false) {}

sbus::sbus(SoftwareSerial *rxPort)
    : SerialIO(rxPort,
               -1,    // don't pass any rx pin as already defined in Software
                      // Serial object
               -1,    // don't pass any tx pin as already defined in Software
                      // Serial object
               false, // don't pass any inverted logic as already defined in
                      // Software Serial object
               true   // tell the object to use software serial when calling the
                      // begin funciton
      ) {}

void sbus::begin() {

// Initialize the serial ports
#if defined(ARDUINO_ARCH_ESP32)
  if (_softSerial) {
    SoftwareSerial *serialPort =
        (SoftwareSerial *)_rxPort; // upcast the pointer to SoftwareSerial class
                                   // so that it can be initialized
    serialPort->begin(SBUS_BAUDRATE,
                      SERIAL_8E2); // initialize the serial peripheral
  } else {
    HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
    serialPort->begin(SBUS_BAUDRATE, SERIAL_8E2, _rxPin, _txPin, _inverted);
  }

#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->setPinout(_txPin, _rxPin);
  serialPort->setInvertRX(_inverted);
  serialPort->setInvertTX(_inverted);
  serialPort->begin(SBUS_BAUDRATE, SERIAL_8E2);
#else
  if (_softSerial) {
    SoftwareSerial *serialPort = (SoftwareSerial *)_rxPort;
    serialPort->begin(SBUS_BAUDRATE, SERIAL_8E2);
  }
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
  }
}

void sbus::getChannel(rc_channels_t *channelData) {
  memcpy(channelData, (uint8_t *)&_channelData + 1, sizeof(rc_channels_t));
}