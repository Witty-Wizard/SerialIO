#include "sbus.h"

void sbus::begin() {
  _rxPort->begin(SBUS_BAUDRATE, SERIAL_8E2, _rxPin, _txPin, _inverted);
}

void sbus::processIncoming() {
  while (_rxPort->available()) {
    prev_buffer_sbus = buffer_sbus;
    buffer_sbus = _rxPort->read();

    if (header_detected_sbus == true) {
      data_rx[rx_index] = buffer_sbus;
      rx_index++;
      if (rx_index > 23) {
        header_detected_sbus = false;
      }
    } else {
      if (prev_buffer_sbus == FOOTER_SBUS && buffer_sbus == HEADER_SBUS) {
        header_detected_sbus = true;
        data_rx[0] = 0x0F;
        data_rx[24] = 0x00;
        rx_index = 1;
      }
    }

    if (rx_index == sizeof(data_rx) / sizeof(data_rx[0])) {
      rx_index = 0;
      header_detected_sbus = false;
    }
  }
}

void sbus::getChannel(crsf_channels_t *channelData) {
  memcpy(channelData, data_rx + 1, sizeof(*channelData));
}