#pragma once
#ifndef SBUS_PROTOCOL_H
#define SBUS_PROTOCOL_H

#define PACKED __attribute__((packed))

#define HEADER_SBUS 0X0F
#define FOOTER_SBUS 0X00
#define SBUS_BAUDRATE 100000

typedef struct sbuspacket_s {
  unsigned syncbyte : 8;
  unsigned channel1 : 11;
  unsigned channel2 : 11;
  unsigned channel3 : 11;
  unsigned channel4 : 11;
  unsigned channel5 : 11;
  unsigned channel6 : 11;
  unsigned channel7 : 11;
  unsigned channel8 : 11;
  unsigned channel9 : 11;
  unsigned channel10 : 11;
  unsigned channel11 : 11;
  unsigned channel12 : 11;
  unsigned channel13 : 11;
  unsigned channel14 : 11;
  unsigned channel15 : 11;
  unsigned channel16 : 11;
  unsigned dummy : 4;
  unsigned channel17 : 1;
  unsigned channel18 : 1;
  unsigned frame_lost : 1;
  unsigned failsafe : 1;
  unsigned footer : 8;
} PACKED sbuspacket_t;

#endif