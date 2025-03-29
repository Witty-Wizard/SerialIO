.. _mainpage:

SerialIO
=========

SerialIO is a common library designed to simplify the implementation of RC protocol decoding in Arduino projects. It provides a modular and extensible architecture that allows for easy integration of various RC protocols.

Supported Protocols
--------------------

- `Futaba SBus protocol <sbus.html>`_
- `Crossfire RC protocol <https://github.com/crsf-wg/crsf/wiki>`_
- `Flysky IBus protocol <https://basejunction.wordpress.com/2015/08/23/en-flysky-i6-14-channels-part1/>`_
- `FrSky F.Port <fport.html>`_

Getting Started
----------------

- `Installation`_
- `Tutorial`_
- `Examples`_

.. _installation:

Installation
------------

Arduino Installation
^^^^^^^^^^^^^^^^^^^^

To use the SerialIO library in your Arduino projects, follow these installation steps:

1. Download the SerialIO library from the `GitHub repository <https://github.com/Witty-Wizard/SerialIO>`_.
2. Extract the downloaded ZIP file.
3. Copy the extracted folder to the `libraries` directory in your Arduino sketchbook.
4. Restart the Arduino IDE.
5. You should now be able to include the SerialIO library in your Arduino sketches.

PlatformIO Installation
^^^^^^^^^^^^^^^^^^^^^^^

If you are using PlatformIO, you can install the SerialIO library directly from the PlatformIO Library Manager. Add the following line to your `platformio.ini` file:

.. code-block:: ini

   lib_deps = Witty-Wizard/SerialIO

.. _tutorial:

Tutorial
--------

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
--------

- `SerialIO`_
- `sbus`_
- `crsf`_
- `ibus`_
- `fport`_

.. _example:

Examples
--------

CRSF Basic Example
^^^^^^^^^^^^^^^^^^

.. literalinclude:: ./examples/espresiff/crsf_basic/crsf_basic.ino

SBUS Basic Example
^^^^^^^^^^^^^^^^^^

.. literalinclude:: ./examples/espresiff/sbus_basic/sbus_basic.ino

Guide to Adding More Protocols
-------------------------------

Steps
^^^^^

To add more protocols to your project, follow these steps:

1. **Create a New Protocol File** : Create a header file for the new protocol, e.g., `xyz_protocol.h`.
2. **Define Protocol Structure** : Define constants, data structures, and functions.
3. **Implement Protocol Functions** : Implement functions in a corresponding source file (`xyz_protocol.cpp`).
4. **Include Protocol Header** : Include the header file using `#include "xyz_protocol.h"`.
5. **Initialize Protocol** : Initialize the protocol in your code.
6. **Process Incoming Data** : Call the function to process data.
7. **Extract Channel Information** : Extract channel data using the provided function.

Basic Functions Required
^^^^^^^^^^^^^^^^^^^^^^^^

For a new protocol, implement these basic functions:

- `void begin()` : Initialize the protocol.
- `void processIncoming()` : Process incoming data.
- `void getChannels()` : Extract channel information.

Here is a template for a new protocol header:

.. code-block:: cpp

    #pragma once
    #ifndef XYZ_PROTOCOL_H
    #define XYZ_PROTOCOL_H

    #include <Arduino.h>

    class XYZProtocol : public SerialIO {
    public:
        explicit XYZProtocol(HardwareSerial &rxPort, int rxPin, int txPin, bool inverted = false)
            : SerialIO(&rxPort, rxPin, txPin, inverted) {}
        ~XYZProtocol();

        void begin();
        void processIncoming();
        void getChannel();

    private:
        HardwareSerial *_serialPort;
    };

    #endif // XYZ_PROTOCOL_H

License
-------

This library is distributed under the GNU `General Public License version 3.0 <https://www.gnu.org/licenses/gpl-3.0.html>`_.

