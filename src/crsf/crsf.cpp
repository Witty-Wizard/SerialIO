#include "crsf.h"

void crsf::begin() {
  _rxPort->begin(CRSF_BAUDRATE, SERIAL_8N1, _rxPin, _txPin, _inverted);
}