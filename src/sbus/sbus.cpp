#include "sbus.h"

void sbus::begin() {
  _rxPort->begin(SBUS_BAUDRATE, SERIAL_8E2, _rxPin, _txPin, _inverted);
}