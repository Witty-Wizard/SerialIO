

# File crsf\_protocol.h



[**FileList**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**crsf\_protocol.h**](crsf__protocol_8h.md)

[Go to the source code of this file](crsf__protocol_8h_source.md)

_Header file for the CRSF protocol implementation._ 

* `#include <stdint.h>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**crsfPayloadLinkstatistics\_s**](structcrsfPayloadLinkstatistics__s.md) <br> |
| struct | [**crsf\_channels\_s**](structcrsf__channels__s.md) <br> |
| struct | [**crsf\_header\_s**](structcrsf__header__s.md) <br> |
| struct | [**crsf\_sensor\_battery\_s**](structcrsf__sensor__battery__s.md) <br> |
| struct | [**crsf\_sensor\_gps\_s**](structcrsf__sensor__gps__s.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**@0**](#enum-@0)  <br> |
| enum  | [**@1**](#enum-@1)  <br> |
| typedef struct [**crsfPayloadLinkstatistics\_s**](structcrsfPayloadLinkstatistics__s.md) | [**crsfLinkStatistics\_t**](#typedef-crsflinkstatistics_t)  <br> |
| enum  | [**crsf\_addr\_e**](#enum-crsf_addr_e)  <br> |
| typedef struct [**crsf\_channels\_s**](structcrsf__channels__s.md) | [**crsf\_channels\_t**](#typedef-crsf_channels_t)  <br> |
| enum  | [**crsf\_frame\_type\_e**](#enum-crsf_frame_type_e)  <br> |
| typedef struct [**crsf\_header\_s**](structcrsf__header__s.md) | [**crsf\_header\_t**](#typedef-crsf_header_t)  <br> |
| typedef struct [**crsf\_sensor\_battery\_s**](structcrsf__sensor__battery__s.md) | [**crsf\_sensor\_battery\_t**](#typedef-crsf_sensor_battery_t)  <br> |
| typedef struct [**crsf\_sensor\_gps\_s**](structcrsf__sensor__gps__s.md) | [**crsf\_sensor\_gps\_t**](#typedef-crsf_sensor_gps_t)  <br> |






















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  uint16\_t | [**be16toh**](#function-be16toh) (uint16\_t val) <br> |
|  uint32\_t | [**be32toh**](#function-be32toh) (uint32\_t val) <br> |
|  uint16\_t | [**htobe16**](#function-htobe16) (uint16\_t val) <br> |
|  uint32\_t | [**htobe32**](#function-htobe32) (uint32\_t val) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**CRSF\_BAUDRATE**](crsf__protocol_8h.md#define-crsf_baudrate)  420000<br>_CRSF default baud rate._  |
| define  | [**CRSF\_CHANNEL\_VALUE\_1000**](crsf__protocol_8h.md#define-crsf_channel_value_1000)  191<br> |
| define  | [**CRSF\_CHANNEL\_VALUE\_2000**](crsf__protocol_8h.md#define-crsf_channel_value_2000)  1792<br> |
| define  | [**CRSF\_CHANNEL\_VALUE\_MAX**](crsf__protocol_8h.md#define-crsf_channel_value_max)    1811<br>_2012us - actual CRSF max is 1984 with E.Limits on_  |
| define  | [**CRSF\_CHANNEL\_VALUE\_MID**](crsf__protocol_8h.md#define-crsf_channel_value_mid)  992<br>_mid value of channel_  |
| define  | [**CRSF\_CHANNEL\_VALUE\_MIN**](crsf__protocol_8h.md#define-crsf_channel_value_min)    172<br>_987us - actual CRSF min is 0 with E.Limits on_  |
| define  | [**CRSF\_CHANNEL\_VALUE\_SPAN**](crsf__protocol_8h.md#define-crsf_channel_value_span)    ([**CRSF\_CHANNEL\_VALUE\_MAX**](crsf__protocol_8h.md#define-crsf_channel_value_max) - [**CRSF\_CHANNEL\_VALUE\_MIN**](crsf__protocol_8h.md#define-crsf_channel_value_min))<br> |
| define  | [**CRSF\_MAX\_PACKET\_SIZE**](crsf__protocol_8h.md#define-crsf_max_packet_size)    64<br>_max declared len is 62+DEST+LEN on top of that = 64_  |
| define  | [**CRSF\_MAX\_PAYLOAD\_LEN**](crsf__protocol_8h.md#define-crsf_max_payload_len)  <br>_Max size of payload in [dest] [len] [type] [payload] [crc8]._  |
| define  | [**CRSF\_NUM\_CHANNELS**](crsf__protocol_8h.md#define-crsf_num_channels)  16<br>_CRSF number of channels._  |
| define  | [**PACKED**](crsf__protocol_8h.md#define-packed)  \_\_attribute\_\_((packed))<br> |

## Public Types Documentation




### enum @0 


```C++
enum @0 {
    CRSF_FRAME_LENGTH_ADDRESS = 1,
    CRSF_FRAME_LENGTH_FRAMELENGTH = 1,
    CRSF_FRAME_LENGTH_TYPE = 1,
    CRSF_FRAME_LENGTH_CRC = 1,
    CRSF_FRAME_LENGTH_TYPE_CRC = 2,
    CRSF_FRAME_LENGTH_EXT_TYPE_CRC =
      4,
    CRSF_FRAME_LENGTH_NON_PAYLOAD =
      4
};
```



Length of different CRSF frame 


        

<hr>



### enum @1 


```C++
enum @1 {
    CRSF_FRAME_GPS_PAYLOAD_SIZE = 15,
    CRSF_FRAME_BATTERY_SENSOR_PAYLOAD_SIZE = 8,
    CRSF_FRAME_LINK_STATISTICS_PAYLOAD_SIZE = 10,
    CRSF_FRAME_RC_CHANNELS_PAYLOAD_SIZE =
      22,
    CRSF_FRAME_ATTITUDE_PAYLOAD_SIZE = 6
};
```



Length of CRSF frames 


        

<hr>



### typedef crsfLinkStatistics\_t 


```C++
typedef struct crsfPayloadLinkstatistics_s crsfLinkStatistics_t;
```



Payload Statics 


        

<hr>



### enum crsf\_addr\_e 


```C++
enum crsf_addr_e {
    CRSF_ADDRESS_BROADCAST = 0x00,
    CRSF_ADDRESS_USB = 0x10,
    CRSF_ADDRESS_TBS_CORE_PNP_PRO = 0x80,
    CRSF_ADDRESS_RESERVED1 = 0x8A,
    CRSF_ADDRESS_CURRENT_SENSOR = 0xC0,
    CRSF_ADDRESS_GPS = 0xC2,
    CRSF_ADDRESS_TBS_BLACKBOX = 0xC4,
    CRSF_ADDRESS_FLIGHT_CONTROLLER = 0xC8,
    CRSF_ADDRESS_RESERVED2 = 0xCA,
    CRSF_ADDRESS_RACE_TAG = 0xCC,
    CRSF_ADDRESS_RADIO_TRANSMITTER = 0xEA,
    CRSF_ADDRESS_CRSF_RECEIVER = 0xEC,
    CRSF_ADDRESS_CRSF_TRANSMITTER = 0xEE
};
```



CRSF sensor address 


        

<hr>



### typedef crsf\_channels\_t 


```C++
typedef struct crsf_channels_s crsf_channels_t;
```



RC Packet Frame 


        

<hr>



### enum crsf\_frame\_type\_e 


```C++
enum crsf_frame_type_e {
    CRSF_FRAMETYPE_GPS = 0x02,
    CRSF_FRAMETYPE_BATTERY_SENSOR = 0x08,
    CRSF_FRAMETYPE_LINK_STATISTICS = 0x14,
    CRSF_FRAMETYPE_OPENTX_SYNC = 0x10,
    CRSF_FRAMETYPE_RADIO_ID = 0x3A,
    CRSF_FRAMETYPE_RC_CHANNELS_PACKED = 0x16,
    CRSF_FRAMETYPE_ATTITUDE = 0x1E,
    CRSF_FRAMETYPE_FLIGHT_MODE = 0x21,
    CRSF_FRAMETYPE_DEVICE_PING = 0x28,
    CRSF_FRAMETYPE_DEVICE_INFO = 0x29,
    CRSF_FRAMETYPE_PARAMETER_SETTINGS_ENTRY = 0x2B,
    CRSF_FRAMETYPE_PARAMETER_READ = 0x2C,
    CRSF_FRAMETYPE_PARAMETER_WRITE = 0x2D,
    CRSF_FRAMETYPE_COMMAND = 0x32,
    CRSF_FRAMETYPE_MSP_REQ =
      0x7A,
    CRSF_FRAMETYPE_MSP_RESP = 0x7B,
    CRSF_FRAMETYPE_MSP_WRITE = 0x7C
};
```



CRSF Sensor frame type 


        

<hr>



### typedef crsf\_header\_t 


```C++
typedef struct crsf_header_s crsf_header_t;
```



Heder of CRSF Packet 


        

<hr>



### typedef crsf\_sensor\_battery\_t 


```C++
typedef struct crsf_sensor_battery_s crsf_sensor_battery_t;
```



Battery Voltage parameters 


        

<hr>



### typedef crsf\_sensor\_gps\_t 


```C++
typedef struct crsf_sensor_gps_s crsf_sensor_gps_t;
```



GPS parameters 


        

<hr>
## Public Static Functions Documentation




### function be16toh 

```C++
static inline uint16_t be16toh (
    uint16_t val
) 
```




<hr>



### function be32toh 

```C++
static inline uint32_t be32toh (
    uint32_t val
) 
```




<hr>



### function htobe16 

```C++
static inline uint16_t htobe16 (
    uint16_t val
) 
```




<hr>



### function htobe32 

```C++
static inline uint32_t htobe32 (
    uint32_t val
) 
```




<hr>
## Macro Definition Documentation





### define CRSF\_BAUDRATE 

```C++
#define CRSF_BAUDRATE 420000
```




<hr>



### define CRSF\_CHANNEL\_VALUE\_1000 

```C++
#define CRSF_CHANNEL_VALUE_1000 191
```




<hr>



### define CRSF\_CHANNEL\_VALUE\_2000 

```C++
#define CRSF_CHANNEL_VALUE_2000 1792
```




<hr>



### define CRSF\_CHANNEL\_VALUE\_MAX 

```C++
#define CRSF_CHANNEL_VALUE_MAX 1811
```




<hr>



### define CRSF\_CHANNEL\_VALUE\_MID 

```C++
#define CRSF_CHANNEL_VALUE_MID 992
```




<hr>



### define CRSF\_CHANNEL\_VALUE\_MIN 

```C++
#define CRSF_CHANNEL_VALUE_MIN 172
```




<hr>



### define CRSF\_CHANNEL\_VALUE\_SPAN 

```C++
#define CRSF_CHANNEL_VALUE_SPAN ( CRSF_CHANNEL_VALUE_MAX - CRSF_CHANNEL_VALUE_MIN )
```




<hr>



### define CRSF\_MAX\_PACKET\_SIZE 

```C++
#define CRSF_MAX_PACKET_SIZE 64
```




<hr>



### define CRSF\_MAX\_PAYLOAD\_LEN 

```C++
#define CRSF_MAX_PAYLOAD_LEN ( CRSF_MAX_PACKET_SIZE -                                                      \
   4)
```




<hr>



### define CRSF\_NUM\_CHANNELS 

```C++
#define CRSF_NUM_CHANNELS 16
```




<hr>



### define PACKED 

```C++
#define PACKED __attribute__((packed))
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/crsf_protocol.h`

