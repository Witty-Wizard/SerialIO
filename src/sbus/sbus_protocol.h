/*!
 * @file sbus_protocol.h
 * @brief Header file for the SBus protocol implementation.
 */
#pragma once

#ifndef SBUS_PROTOCOL_H
#define SBUS_PROTOCOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PACKED __attribute__((packed))
#define HEADER_SBUS 0x0F ///< SBus Header Byte
#define FOOTER_SBUS 0x00 ///< SBus Footer Byte
#define SBUS_BAUDRATE 100000 ///< SBus baudrate
#define SBUS_MAX_PACKET_SIZE 25 ///< SBus packet length

typedef struct sbus_channels_s {
  unsigned header : 8;
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
  unsigned failsafe : 1;
  unsigned framelost : 1;
  unsigned channel17 : 1;
  unsigned channel18 : 1;
  unsigned footer : 8;
} PACKED sbus_channels_t;
#ifdef __cplusplus
}
#endif

#endif