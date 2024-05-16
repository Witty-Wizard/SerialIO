

# Class sbus



[**ClassList**](annotated.md) **>** [**sbus**](classsbus.md)



_A class for handling SBUS protocol communication._ 

* `#include <sbus.h>`



Inherits the following classes: [SerialIO](classSerialIO.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**begin**](#function-begin) () override<br>_Initializes the SBUS communication._  |
| virtual void | [**getChannel**](#function-getchannel) ([**crsf\_channels\_t**](crsf__protocol_8h.md#typedef-crsf_channels_t) \* channelData) override<br>_Gets the decoded RC channels from the SBUS data._  |
| virtual void | [**processIncoming**](#function-processincoming) () override<br>_Processes incoming SBUS data._  |
|   | [**sbus**](#function-sbus) (HardwareSerial & rxPort, int rxPin, int txPin=-1, bool inverted=true) <br>_Constructor for the SBUS class._  |
| virtual  | [**~sbus**](#function-sbus) () <br> |


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
virtual void sbus::begin () override
```



Implements [*SerialIO::begin*](classSerialIO.md#function-begin)


<hr>



### function getChannel 

_Gets the decoded RC channels from the SBUS data._ 
```C++
virtual void sbus::getChannel (
    crsf_channels_t * channelData
) override
```





**Parameters:**


* `channelData` Pointer to a crsf\_channels\_t struct where the decoded channel data will be stored. 




        
Implements [*SerialIO::getChannel*](classSerialIO.md#function-getchannel)


<hr>



### function processIncoming 

```C++
virtual void sbus::processIncoming () override
```



Implements [*SerialIO::processIncoming*](classSerialIO.md#function-processincoming)


<hr>



### function sbus 

_Constructor for the SBUS class._ 
```C++
inline explicit sbus::sbus (
    HardwareSerial & rxPort,
    int rxPin,
    int txPin=-1,
    bool inverted=true
) 
```





**Parameters:**


* `rxPort` Reference to the hardware serial port for RX communication. 
* `rxPin` The RX pin number. 
* `txPin` The TX pin number. 
* `inverted` Whether the serial signal is inverted (true) or not (false). 




        

<hr>



### function ~sbus 

```C++
inline virtual sbus::~sbus () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/sbus.h`

