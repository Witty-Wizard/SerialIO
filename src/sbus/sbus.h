#pragma once
#ifndef SBUS_H
#define SBUS_H
#include "sbus_protocol.h"
#include <serialIO.h>

class sbus : public serialIO {
public:
  explicit sbus(HardwareSerial &rxPort, int rxPin, int txPin,
                bool inverted = false)
      : serialIO(&rxPort, rxPin, txPin, inverted){};
  virtual ~sbus(){};

  void begin() override;
};

#endif