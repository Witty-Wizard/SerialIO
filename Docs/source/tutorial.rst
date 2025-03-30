.. _tutorial:

Tutorial
========

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

See Also
^^^^^^^^
- :cpp:class:`SerialIO`
- :cpp:class:`sbus`
- :cpp:class:`crsf`
- :cpp:class:`ibus`
- :cpp:class:`fport`