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
    _rx_buffer[FPORT_MAX_PACKET_SIZE - 1] = _rxPort->read();
    if (_rx_buffer[0] == 0x7E &&
        _rx_buffer[FPORT_MAX_PACKET_SIZE - 1] == 0x7E) {
      memcpy(&_channelData, &_rx_buffer[4], sizeof(_channelData));
    } else {
      leftShift(_rx_buffer, sizeof(_rx_buffer));
    }
  }
}

void fport::getChannel(void *channelData) {}

void fport::leftShift(uint8_t arr[], size_t size) {
  memmove(arr, arr + 1, (size - 1));
  arr[size - 1] = 0xFF;
}