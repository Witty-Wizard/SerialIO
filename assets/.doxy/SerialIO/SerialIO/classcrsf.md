

# Class crsf



[**ClassList**](annotated.md) **>** [**crsf**](classcrsf.md)



_A class for handling CRSF protocol communication._ 

* `#include <crsf.h>`



Inherits the following classes: [SerialIO](classSerialIO.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**begin**](#function-begin) () override<br>_Initializes the CRSF communication._  |
|  uint8\_t | [**crc8**](#function-crc8) (uint8\_t \* data, uint8\_t len) <br> |
|   | [**crsf**](#function-crsf) (HardwareSerial & rxPort, int rxPin, int txPin=-1, bool inverted=false) <br>_Constructor for the CRSF class._  |
| virtual void | [**getChannel**](#function-getchannel) ([**crsf\_channels\_t**](crsf__protocol_8h.md#typedef-crsf_channels_t) \* channelData) override<br>_Retrieves the decoded RC channels from the received CRSF data._  |
| virtual void | [**processIncoming**](#function-processincoming) () override<br>_Processes incoming CRSF data._  |
| virtual  | [**~crsf**](#function-crsf) () <br> |


## Public Functions inherited from SerialIO

See [SerialIO](classSerialIO.md)

| Type | Name |
| ---: | :--- |
|   | [**SerialIO**](classSerialIO.md#function-serialio) (HardwareSerial \* rxPort, int rxPin, int txPin, bool inverted) <br>_Constructor for the_ [_**SerialIO**_](classSerialIO.md) _class._ |
| virtual void | [**begin**](classSerialIO.md#function-begin) () <br>_Initialises the pins and setup serial port._  |
| virtual void | [**getChannel**](classSerialIO.md#function-getchannel) ([**crsf\_channels\_t**](crsf__protocol_8h.md#typedef-crsf_channels_t) \* channelData) <br>_Gives the decoded rc channels._  |
| virtual void | [**processIncoming**](classSerialIO.md#function-processincoming) () <br>_decode the incoming serial data._  |
| virtual  | [**~SerialIO**](classSerialIO.md#function-serialio) () <br> |
















## Protected Attributes inherited from SerialIO

See [SerialIO](classSerialIO.md)

| Type | Name |
| ---: | :--- |
|  uint8\_t | [**\_buffer**](classSerialIO.md#variable-_buffer)  <br> |
|  bool | [**\_headerDetected**](classSerialIO.md#variable-_headerdetected)  <br> |
|  bool | [**\_inverted**](classSerialIO.md#variable-_inverted)  <br> |
|  uint8\_t | [**\_prevBuffer**](classSerialIO.md#variable-_prevbuffer)  <br> |
|  uint8\_t | [**\_rxIndex**](classSerialIO.md#variable-_rxindex)  <br> |
|  int | [**\_rxPin**](classSerialIO.md#variable-_rxpin)  <br> |
|  HardwareSerial \* | [**\_rxPort**](classSerialIO.md#variable-_rxport)  <br> |
|  int | [**\_txPin**](classSerialIO.md#variable-_txpin)  <br> |






































## Public Functions Documentation




### function begin 

```C++
virtual void crsf::begin () override
```



Implements [*SerialIO::begin*](classSerialIO.md#function-begin)


<hr>



### function crc8 

```C++
uint8_t crsf::crc8 (
    uint8_t * data,
    uint8_t len
) 
```




<hr>



### function crsf 

_Constructor for the CRSF class._ 
```C++
inline explicit crsf::crsf (
    HardwareSerial & rxPort,
    int rxPin,
    int txPin=-1,
    bool inverted=false
) 
```





**Parameters:**


* `rxPort` Reference to the hardware serial port for RX communication. 
* `rxPin` The RX pin number. 
* `txPin` The TX pin number. 
* `inverted` Whether the serial signal is inverted (true) or not (false). 




        

<hr>



### function getChannel 

_Retrieves the decoded RC channels from the received CRSF data._ 
```C++
virtual void crsf::getChannel (
    crsf_channels_t * channelData
) override
```





**Parameters:**


* `channelData` Pointer to a crsf\_channels\_t struct where the decoded channel data will be stored. 




        
Implements [*SerialIO::getChannel*](classSerialIO.md#function-getchannel)


<hr>



### function processIncoming 

```C++
virtual void crsf::processIncoming () override
```



Implements [*SerialIO::processIncoming*](classSerialIO.md#function-processincoming)


<hr>



### function ~crsf 

```C++
inline virtual crsf::~crsf () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/crsf.h`

