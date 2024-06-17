#include "SerialIO.h"

SerialIO::SerialIO(Stream *rxPort, int rxPin, int txPin, bool inverted)
    : _rxPort(rxPort), _rxPin(rxPin), _txPin(txPin), _inverted(inverted) {
    // Constructor implementation
}

SerialIO::~SerialIO() {
  // End serial communication
  _rxPort->end();
}

void SerialIO::begin() {
    // Initialize pins and setup serial port
}

void SerialIO::processIncoming() {
    // Decode the incoming serial data
    // This function can be empty if actual decoding is implemented in subclasses
}

void SerialIO::getChannel(crsf_channels_t *channelData) {
    // Get the decoded RC channels
    // This function can be empty if actual decoding is implemented in subclasses
}
