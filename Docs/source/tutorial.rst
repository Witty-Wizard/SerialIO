.. _tutorial:

Tutorial
##########

General usage
==========================

To use the library for decoding RC protocols in your Arduino project, follow these steps:

1. **Include Necessary Libraries**:

.. code-block:: cpp

    #include <SerialIO.h>

2. **Define Channel Data Structure**:

.. code-block:: cpp

    crsf_channels_t channelData;

3. **Instantiate SerialIO Object**:

.. code-block:: cpp

    SerialIO *receiver = new crsf(&Serial1, pinRX, pinTX);

To instantiate a SerialIO object for receiving data only:

.. code-block:: cpp

    SerialIO *receiver = new crsf(&Serial1, pinRX);

4. **Initialize Communication**:

.. code-block:: cpp

    void setup() {
        receiver->begin();
    }

5. **Process Incoming Data**:

.. code-block:: cpp

    receiver->processIncoming();

6. **Retrieve Channel Data**:

.. code-block:: cpp

    receiver->getChannel(&channelData);

Using software serial
==========================
If you are using a board that does not have hardware serial ports, you can use the SoftwareSerial library to create a software serial port.
The SerialIO class can accept a SoftwareSerial object, but the begin method does not support software serial, so after creating the object, you need to 
manually initiate the software serial port.

.. note::

    On AVR boards, only ibus, and fport protocols are supported (fport required an external inverter circuit), this is because sbus and crsf use unusual baudrate that are not supported by the hardware serial.
    sbus can be used, by using a software serial library, but it is not recommended.

Sbus
^^^^^^

.. code-block:: cpp

    #include <SoftwareSerial.h>
    #include <SerialIO.h>

    #define pinRX 2
    #define pinTX 3
    #define SBUS_BAUDRATE 100000

    /** SoftwareSerial(pinRX, pinTX, true);
     *                               ^^^^
     *                               set to true because sbus uses inverted uart
     */

    SoftwareSerial *mySerial = new SoftwareSerial(pinRX, pinTX, true); 
    mySerial.begin(SBUS_BAUDRATE);
    SerialIO *receiver = new sbus(mySerial); 

Crossfire
^^^^^^^^^

.. note::

    Crossfire uses a rather high baudrate of `420000`, which is not supported by hardware serial and for software serial, 
    it is not recommended to use it, because the software serial library is not optimized for high baudrate. The following code
    is not tested. Best alternative would be to use a better microcontroller or if you are using ELRS receivers, then reduce the 
    baudrate to `115200`, which is supported by hardware and software serial.

.. code-block:: cpp

    #include <SoftwareSerial.h>
    #include <SerialIO.h>

    #define pinRX 2
    #define pinTX 3
    #define CRSF_BAUDRATE 100000

    SoftwareSerial *mySerial = new SoftwareSerial(pinRX, pinTX); 
    mySerial.begin(CRSF_BAUDRATE);
    SerialIO *receiver = new crsf(mySerial); 

See Also
^^^^^^^^
- :cpp:class:`SerialIO`
- :cpp:class:`sbus`
- :cpp:class:`crsf`
- :cpp:class:`ibus`
- :cpp:class:`fport`