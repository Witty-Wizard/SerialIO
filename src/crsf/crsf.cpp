#include "crsf.h"

void crsf::begin() {
  _rxPort->begin(CRSF_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
}

void crsf::processIncoming() {
  while (_rxPort->available()) {
    uint8_t buffer = _rxPort->read();
    if (header_detected) {
      rx_data[rx_index] = buffer;
      rx_index++;
      if (rx_index > rx_data[1] + 2)

      {
        rx_index = 0;
        header_detected = false;
      }
    } else {
      if (buffer == CRSF_ADDRESS_FLIGHT_CONTROLLER ||
          buffer == CRSF_ADDRESS_CRSF_TRANSMITTER) {
        header_detected = true;
        rx_data[0] = buffer;
        rx_index = 1;
      }
    }

    if (rx_index == sizeof(rx_data) / sizeof(rx_data[0])) {
      rx_index = 0;
      header_detected = false;
    }
  }
}

void crsf::getChannel(crsf_channels_t *channelData) {
  memcpy(channelData, rx_data + 3, sizeof(*channelData));
}