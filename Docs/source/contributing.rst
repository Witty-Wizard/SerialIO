Contributing
============

To add more protocols to your project, follow these steps:

1. **Create a New Protocol File** : Create a header file for the new protocol, e.g., `xyz_protocol.h`.
2. **Define Protocol Structure** : Define constants, data structures, and functions.
3. **Implement Protocol Functions** : Implement functions in a corresponding source file (`xyz_protocol.cpp`).
4. **Include Protocol Header** : Include the header file using `#include "xyz_protocol.h"`.
5. **Initialize Protocol** : Initialize the protocol in your code.
6. **Process Incoming Data** : Call the function to process data.
7. **Extract Channel Information** : Extract channel data using the provided function.

Basic Functions Required
------------------------

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