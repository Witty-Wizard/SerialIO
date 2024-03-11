#pragma once
#ifndef SERIALIO_H
#define SERIALIO_H
#include <Arduino.h>

class serialIO {
public:
  serialIO(HardwareSerial *rxPort, int rxPin, int txPin, bool inverted)
      : _rxPort(rxPort), _rxPin(rxPin), _txPin(txPin), _inverted(inverted){};
  virtual ~serialIO(){};
  virtual void begin();

protected:
  HardwareSerial *_rxPort;
  bool _inverted;
  int _rxPin;
  int _txPin;
};
#endif
