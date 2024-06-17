#include "ibus.h"

ibus::ibus(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : SerialIO(rxPort, rxPin, txPin, inverted) {}

void ibus::begin() {

// Initialize the serial port
#if defined(ARDUINO_ARCH_ESP32)
  HardwareSerial *serialPort = (HardwareSerial *)_rxPort;
  serialPort->begin(IBUS_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
#elif defined(ARDUINO_ARCH_RP2040)
  SerialUART *serialPort = (SerialUART *)_rxPort;
  serialPort->setPinout(_txPin, _rxPin);
  serialPort->begin(IBUS_BAUDRATE, SERIAL_8N1);
#else
#error                                                                         \
    "Unsupported hardware platform. This code supports ESP32 and RP2040 architectures only."
#endif
}

void ibus::processIncoming() {}

void ibus::getChannel(crsf_channels_t *channelData) {}