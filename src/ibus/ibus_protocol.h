/*!
 * @file ibus_protocol.h
 * @brief Header file for the iBus protocol implementation.
 */
#pragma once

#ifndef IBUS_PROTOCOL_H
#define IBUS_PROTOCOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PACKED __attribute__((packed))
#define IBUS_MAX_PACKET_SIZE 32 ///< Maximum packet size for the IBUS protocol
#define IBUS_BAUDRATE 115200 ///< Baud rate for IBUS communication
#define IBUS_HEADER1 0x20
#define IBUS_HEADER2 0x40

typedef struct ibus_channels_s {
  unsigned header : 16;
  unsigned channel1 : 16;
  unsigned channel2 : 16;
  unsigned channel3 : 16;
  unsigned channel4 : 16;
  unsigned channel5 : 16;
  unsigned channel6 : 16;
  unsigned channel7 : 16;
  unsigned channel8 : 16;
  unsigned channel9 : 16;
  unsigned channel10 : 16;
  unsigned channel11 : 16;
  unsigned channel12 : 16;
  unsigned channel13 : 16;
  unsigned channel14 : 16;
  unsigned checksum : 16;
} PACKED ibus_channels_t;

#ifdef __cplusplus
}
#endif

#endif