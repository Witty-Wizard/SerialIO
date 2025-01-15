/*!
 * @file msp_protocol.h
 * @brief Header file for the MultiWii Serial Protocol (MSP) implementation.
 */

#pragma once

#ifndef MSP_PROTOCOL_H
#define MSP_PROTOCOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Macro definitions
#define MSP_PREAMBLE        0x244D /*!< MSP preamble ('$M' in ASCII) */
#define MSP_DIRECTION_TO_FC 0x3C   /*!< Direction: '<' (to Flight Controller) */
#define MSP_DIRECTION_FROM_FC 0x3E /*!< Direction: '>' (from Flight Controller) */

// Enumeration for MSP commands and their message IDs
/*!
 * @enum MSPCommand
 * @brief List of MSP commands and their corresponding message IDs.
 */
enum MSPCommand {
    MSP_IDENT = 100,            /*!< MSP_IDENT command */
    MSP_VERSION = 101,          /*!< MSP_VERSION command */
    MSP_STATUS = 102,           /*!< MSP_STATUS command */
    MSP_RAW_IMU = 103,          /*!< MSP_RAW_IMU command */
    MSP_SERVO = 104,            /*!< MSP_SERVO command */
    MSP_MOTOR = 105,            /*!< MSP_MOTOR command */
    MSP_SET_MOTOR = 214,        /*!< MSP_SET_MOTOR command */
    MSP_RC = 105,               /*!< MSP_RC command */
    MSP_SET_RAW_RC = 200,       /*!< MSP_SET_RAW_RC command */
    MSP_RAW_GPS = 106,          /*!< MSP_RAW_GPS command */
    MSP_SET_RAW_GPS = 201,      /*!< MSP_SET_RAW_GPS command */
    MSP_COMP_GPS = 107,         /*!< MSP_COMP_GPS command */
    MSP_ATTITUDE = 108,         /*!< MSP_ATTITUDE command */
    MSP_ALTITUDE = 109,         /*!< MSP_ALTITUDE command */
    MSP_ANALOG = 110,           /*!< MSP_ANALOG command */
    MSP_RC_TUNING = 111,        /*!< MSP_RC_TUNING command */
    MSP_SET_RC_TUNING = 204,    /*!< MSP_SET_RC_TUNING command */
    MSP_PID = 112,              /*!< MSP_PID command */
    MSP_SET_PID = 202,          /*!< MSP_SET_PID command */
    MSP_BOX = 113,              /*!< MSP_BOX command */
    MSP_SET_BOX = 203,          /*!< MSP_SET_BOX command */
    MSP_MISC = 114,             /*!< MSP_MISC command */
    MSP_SET_MISC = 207,         /*!< MSP_SET_MISC command */
    MSP_MOTOR_PINS = 115,       /*!< MSP_MOTOR_PINS command */
    MSP_BOXNAMES = 116,         /*!< MSP_BOXNAMES command */
    MSP_PIDNAMES = 117,         /*!< MSP_PIDNAMES command */
    MSP_WP = 118,               /*!< MSP_WP command */
    MSP_SET_WP = 209,           /*!< MSP_SET_WP command */
    MSP_BOXIDS = 119,           /*!< MSP_BOXIDS command */
    MSP_SERVO_CONF = 120,       /*!< MSP_SERVO_CONF command */
    MSP_SET_SERVO_CONF = 212,   /*!< MSP_SET_SERVO_CONF command */
    MSP_ACC_CALIBRATION = 205,  /*!< MSP_ACC_CALIBRATION command */
    MSP_MAG_CALIBRATION = 206,  /*!< MSP_MAG_CALIBRATION command */
    MSP_RESET_CONF = 208,       /*!< MSP_RESET_CONF command */
    MSP_SELECT_SETTING = 210,   /*!< MSP_SELECT_SETTING command */
    MSP_SET_HEAD = 211,         /*!< MSP_SET_HEAD command */
    MSP_BIND = 240,             /*!< MSP_BIND command */
    MSP_EEPROM_WRITE = 250      /*!< MSP_EEPROM_WRITE command */
};

// Enumeration for sensor flags
/*!
 * @enum SensorFlag
 * @brief Sensor flags for the MSP protocol.
 */
enum SensorFlag {
    SENSOR_BARO = 1 << 1,  /*!< Barometer sensor */
    SENSOR_MAG = 1 << 2,   /*!< Magnetometer sensor */
    SENSOR_GPS = 1 << 3,   /*!< GPS sensor */
    SENSOR_SONAR = 1 << 4  /*!< Sonar sensor */
};

// Enumeration for capability flags
/*!
 * @enum CapabilityFlag
 * @brief Capability flags for the MSP protocol.
 */
enum CapabilityFlag {
    CAP_BIND_BUTTON = 1 << 0, /*!< Bind button capability */
    CAP_DYNBAL = 1 << 1,      /*!< Dynamic balancing capability */
    CAP_FLAP = 1 << 2         /*!< Flap control capability */
};

// Structure for an MSP packet
/*!
 * @struct MSPPacket
 * @brief Represents a MultiWii Serial Protocol (MSP) packet.
 */
struct MSPPacket {
    uint16_t preamble;       /*!< Preamble ('$M' in ASCII, 0x244D) */
    uint8_t direction;       /*!< Direction ('<' or '>') */
    uint8_t size;            /*!< Number of data bytes */
    uint8_t command;         /*!< Command ID */
    uint8_t data[255];       /*!< Data payload (maximum 255 bytes) */
    uint8_t crc;             /*!< CRC: XOR of size, command, and each data byte */
};

#ifdef __cplusplus
}
#endif

#endif // MSP_PROTOCOL_H
