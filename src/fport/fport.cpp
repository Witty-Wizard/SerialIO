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
  while (_rxPort->available()) {
    _rxData[FPORT_MAX_PACKET_SIZE - 1] = _rxPort->read();
  }
  while (!(_rxData[0] == 0x7E && _rxData[FPORT_MAX_PACKET_SIZE - 1] == 0x7E)) {
    leftShift(_rxData, sizeof(_rxData));
  }
  memcpy(&_channelData, &_rxData[4], sizeof(_channelData));
  memset(_rxData, 0, sizeof(_rxData));
}

void fport::getChannel(rc_channels_t *channelData) {}