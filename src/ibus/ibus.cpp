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
  serialPort->setInvertRX(_inverted);
  serialPort->setInvertTX(_inverted);
  serialPort->begin(IBUS_BAUDRATE, SERIAL_8N1);
#else
#warning #warning "Unsupported hardware platform."
#endif
}

void ibus::processIncoming() {
  while (_rxPort->available()) {
    _rxData[IBUS_MAX_PACKET_SIZE - 1] = _rxPort->read();
    if (_rxData[0] == IBUS_HEADER1 && _rxData[1] == IBUS_HEADER2) {
      if (checkSum()) {
        _channelData.header = (_rxData[2] << 8) | _rxData[0];
        _channelData.channel1 = (_rxData[3] << 8) | _rxData[2];
        _channelData.channel2 = (_rxData[5] << 8) | _rxData[4];
        _channelData.channel3 = (_rxData[7] << 8) | _rxData[6];
        _channelData.channel4 = (_rxData[9] << 8) | _rxData[8];
        _channelData.channel5 = (_rxData[11] << 8) | _rxData[10];
        _channelData.channel6 = (_rxData[13] << 8) | _rxData[12];
        _channelData.channel7 = (_rxData[15] << 8) | _rxData[14];
        _channelData.channel8 = (_rxData[17] << 8) | _rxData[16];
        _channelData.channel9 = (_rxData[19] << 8) | _rxData[18];
        _channelData.channel10 = (_rxData[21] << 8) | _rxData[20];
        _channelData.channel11 = (_rxData[23] << 8) | _rxData[22];
        _channelData.channel12 = (_rxData[25] << 8) | _rxData[24];
        _channelData.channel13 = (_rxData[27] << 8) | _rxData[26];
        _channelData.channel14 = (_rxData[29] << 8) | _rxData[28];
        _channelData.checksum = (_rxData[31] << 8) | _rxData[30];
      }
    }
    leftShift(_rxData, sizeof(_rxData));
  }
}

void ibus::getChannel(rc_channels_t *channelData) {
  channelData->channel1=_channelData.channel1;
  channelData->channel2=_channelData.channel2;
  channelData->channel3=_channelData.channel3;
  channelData->channel4=_channelData.channel4;
  channelData->channel5=_channelData.channel5;
  channelData->channel6=_channelData.channel6;
  channelData->channel7=_channelData.channel7;
  channelData->channel8=_channelData.channel8;
  channelData->channel9=_channelData.channel9;
  channelData->channel10=_channelData.channel10;
  channelData->channel11=_channelData.channel11;
  channelData->channel12=_channelData.channel12;
  channelData->channel13=_channelData.channel13;
  channelData->channel14=_channelData.channel14;
}

bool ibus::checkSum() {
  // Sum all the elements of _rxData except the last two bytes
  uint16_t sum = 0;
  for (size_t i = 0; i < sizeof(_rxData) - 2; ++i) {
    sum += _rxData[i];
  }

  // Transform the last two bytes into a little-endian uint16_t
  uint16_t checkSum =
      (_rxData[sizeof(_rxData) - 1] << 8) | _rxData[sizeof(_rxData) - 2];

  // Add the last two bytes to the sum
  sum += checkSum;

  // Check if the sum matches the expected CRC
  return (sum == 0xFFFF); // Assuming IBUS CRC is 0xFFFF when correct
}