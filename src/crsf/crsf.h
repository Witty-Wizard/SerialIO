#pragma once
#ifndef CRSF_H
#define CRSF_H
#include "crsf_protocol.h"
#include <serialIO.h>

class crsf : public serialIO {
public:
  explicit crsf(HardwareSerial &rxPort, int rxPin, int txPin,
                bool inverted = false)
      : serialIO(&rxPort, rxPin, txPin, inverted){};
  virtual ~crsf(){};

  void begin() override;
};

#endif