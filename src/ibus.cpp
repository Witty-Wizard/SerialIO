#include "ibus.h"

ibus::ibus(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : SerialIO(rxPort, rxPin, txPin, inverted) {}

void ibus::begin() {

// Initialize the serial port
#if defined(ARDUINO_ARCH_ESP32)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->begin(IBUS_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
#elif defined(ARDUINO_ARCH_AVR)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->begin(IBUS_BAUDRATE);
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->setPinout(_txPin, _rxPin);
  serialPort->begin(IBUS_BAUDRATE, SERIAL_8N1);
#else
#warning #warning "Unsupported hardware platform."
#endif
}

void ibus::processIncoming() {
  while (_rxPort->available()) {
    _prevBuffer = _buffer;
    _buffer = _rxPort->read();
    if (_headerDetected) {
      _rxData[_rxIndex++] = _buffer;

    } else {
      if (_prevBuffer == IBUS_HEADER1 && _buffer == IBUS_HEADER2) {
        _headerDetected = true;
        _rxIndex = 0;
        _rxData[_rxIndex++] = IBUS_HEADER1;
        _rxData[_rxIndex++] = IBUS_HEADER2;
      }
    }

    if (_rxIndex == sizeof(_rxData) / sizeof(_rxData[0])) {
      _rxIndex = 0;
      _headerDetected = false;
    }
  }

  if (checkSum()) {
    channelData.header = (_rxData[2] << 8) | _rxData[0];
    channelData.channel1 = (_rxData[3] << 8) | _rxData[2];
    channelData.channel2 = (_rxData[5] << 8) | _rxData[4];
    channelData.channel3 = (_rxData[7] << 8) | _rxData[6];
    channelData.channel4 = (_rxData[9] << 8) | _rxData[8];
    channelData.channel5 = (_rxData[11] << 8) | _rxData[10];
    channelData.channel6 = (_rxData[13] << 8) | _rxData[12];
    channelData.channel7 = (_rxData[15] << 8) | _rxData[14];
    channelData.channel8 = (_rxData[17] << 8) | _rxData[16];
    channelData.channel9 = (_rxData[19] << 8) | _rxData[18];
    channelData.channel10 = (_rxData[21] << 8) | _rxData[20];
    channelData.channel11 = (_rxData[23] << 8) | _rxData[22];
    channelData.channel12 = (_rxData[25] << 8) | _rxData[24];
    channelData.channel13 = (_rxData[27] << 8) | _rxData[26];
    channelData.channel14 = (_rxData[29] << 8) | _rxData[28];
    channelData.checksum = (_rxData[31] << 8) | _rxData[30];
  }
}

void ibus::getChannel(void *channelData) { *channelData = this->channelData; }

bool ibus::checkSum() {
  // Sum all the elements of _rxData except the last two bytes
  uint16_t sum = 0;
  for (size_t i = 0; i < sizeof(_rxData) - 2; ++i) {
    sum += _rxData[i];
  }

  // Transform the last two bytes into a little-endian uint16_t
  uint16_t crc =
      (_rxData[sizeof(_rxData) - 1] << 8) | _rxData[sizeof(_rxData) - 2];

  // Add the last two bytes to the sum
  sum += crc;

  // Check if the sum matches the expected CRC
  return (sum == 0xFFFF); // Assuming IBUS CRC is 0xFFFF when correct
}
