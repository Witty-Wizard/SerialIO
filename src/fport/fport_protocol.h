/*!
 * @file fport_protocol.h
 * @brief Header file for the F.Port protocol implementation.
 */
#pragma once

#ifndef FPORT_PROTOCOL_H
#define FPORT_PROTOCOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PACKED __attribute__((packed))
#define FPORT_BAUDRATE 115200 ///< F.Port baudrate
#define FPORT_MAX_PACKET_SIZE 29 ///< F.Port maximum packet length
#define FPORT_END_BYTES 0x7E

typedef enum {
  FPORT_FRAMETYPE_RC_CHANNELS_PACKED = 0x00,
  FPORT_FRAMETYPE_DOWNLINK = 0x01,
  FPORT_FRAMETYPE_UPLINK = 0x81,
} fport_frame_type_e;

typedef struct fport_channels_s {
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
} PACKED fport_channels_t;

#ifdef __cplusplus
}
#endif

#endif