

# Class SerialIO



[**ClassList**](annotated.md) **>** [**SerialIO**](classSerialIO.md)



_Class that stores state and functions for initialising and decoding rc protocol._ 

* `#include <SerialIO.h>`





Inherited by the following classes: [crsf](classcrsf.md),  [sbus](classsbus.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**SerialIO**](#function-serialio) (HardwareSerial \* rxPort, int rxPin, int txPin, bool inverted) <br>_Constructor for the_ [_**SerialIO**_](classSerialIO.md) _class._ |
| virtual void | [**begin**](#function-begin) () <br>_Initialises the pins and setup serial port._  |
| virtual void | [**getChannel**](#function-getchannel) ([**crsf\_channels\_t**](crsf__protocol_8h.md#typedef-crsf_channels_t) \* channelData) <br>_Gives the decoded rc channels._  |
| virtual void | [**processIncoming**](#function-processincoming) () <br>_decode the incoming serial data._  |
| virtual  | [**~SerialIO**](#function-serialio) () <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  uint8\_t | [**\_buffer**](#variable-_buffer)  <br> |
|  bool | [**\_headerDetected**](#variable-_headerdetected)  <br> |
|  bool | [**\_inverted**](#variable-_inverted)  <br> |
|  uint8\_t | [**\_prevBuffer**](#variable-_prevbuffer)  <br> |
|  uint8\_t | [**\_rxIndex**](#variable-_rxindex)  <br> |
|  int | [**\_rxPin**](#variable-_rxpin)  <br> |
|  HardwareSerial \* | [**\_rxPort**](#variable-_rxport)  <br> |
|  int | [**\_txPin**](#variable-_txpin)  <br> |




















## Public Functions Documentation




### function SerialIO 

_Constructor for the_ [_**SerialIO**_](classSerialIO.md) _class._
```C++
inline SerialIO::SerialIO (
    HardwareSerial * rxPort,
    int rxPin,
    int txPin,
    bool inverted
) 
```



Initializes the pins and sets up the serial port.




**Parameters:**


* `rxPort` Pointer to the hardware serial port to use. 
* `rxPin` The RX pin number. 
* `txPin` The TX pin number. 
* `inverted` Whether the serial signal is inverted (true) or not (false). 




        

<hr>



### function begin 

```C++
virtual void SerialIO::begin () 
```




<hr>



### function getChannel 

_Gives the decoded rc channels._ 
```C++
virtual void SerialIO::getChannel (
    crsf_channels_t * channelData
) 
```





**Parameters:**


* `channelData` A pointer to a crsf\_channels\_t struct where the decoded channel data will be stored. 




        

<hr>



### function processIncoming 

```C++
virtual void SerialIO::processIncoming () 
```




<hr>



### function ~SerialIO 

```C++
inline virtual SerialIO::~SerialIO () 
```




<hr>
## Protected Attributes Documentation




### variable \_buffer 

```C++
uint8_t SerialIO::_buffer;
```




<hr>



### variable \_headerDetected 

```C++
bool SerialIO::_headerDetected;
```




<hr>



### variable \_inverted 

```C++
bool SerialIO::_inverted;
```




<hr>



### variable \_prevBuffer 

```C++
uint8_t SerialIO::_prevBuffer;
```




<hr>



### variable \_rxIndex 

```C++
uint8_t SerialIO::_rxIndex;
```




<hr>



### variable \_rxPin 

```C++
int SerialIO::_rxPin;
```




<hr>



### variable \_rxPort 

```C++
HardwareSerial* SerialIO::_rxPort;
```




<hr>



### variable \_txPin 

```C++
int SerialIO::_txPin;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/SerialIO.h`

