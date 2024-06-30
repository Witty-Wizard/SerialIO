@mainpage
SerialIO is a common library designed to simplify the implementation of RC protocol decoding in Arduino projects. It provides a modular and extensible architecture that allows for easy integration of various RC protocols.

# Supported Protocol

- [Futaba SBus protocol](#futabasbus)
- [Crossfire RC protocol](https://github.com/crsf-wg/crsf/wiki)
- [Flysky IBus protocol](https://basejunction.wordpress.com/2015/08/23/en-flysky-i6-14-channels-part1/)
- [FrSky F.Port](#frskyfport)

# Getting Started

- [Installation](#installation)
- [Tutorial](#tutorial)
- [Examples](#example)

## Installation {#installation}

### Arduino Installation

To use the SerialIO library in your Arduino projects, follow these installation steps:

1. Download the SerialIO library from the [GitHub repository](https://github.com/Witty-Wizard/SerialIO).
2. Extract the downloaded ZIP file.
3. Copy the extracted folder to the `libraries` directory in your Arduino sketchbook.
4. Restart the Arduino IDE.
5. You should now be able to include the SerialIO library in your Arduino sketches.

### PlatformIO Installation

If you are using PlatformIO, you can install the SerialIO library directly from the PlatformIO Library Manager. Add the following line to your `platformio.ini` file:

```ini
lib_deps = Witty-Wizard/SerialIO
```

## Tutorial {#tutorial}

To use the library for decoding RC protocols in your Arduino project, follow these steps:

1.  **Include Necessary Libraries**:
    Include the required libraries at the beginning of your sketch:
    ```cpp
    #include <SerialIO.h>
    ```
2.  **Define Channel Data Structure**:
    Define a structure to hold the decoded RC channel data.
    ```cpp
    crsf_channels_t channelData;
    ```
3.  **Instantiate SerialIO Object**:
    Create an instance of the SerialIO class, specifying the serial port, RX pin, and TX pin:
    ```cpp
    SerialIO *receiver = new crsf(&Serial1, pinRX, pinTX);
    ```
    To instantiate a SerialIO object for receiving data only, you can create an instance of the crsf class specifying the serial port, RX pin:
    ```cpp
    SerialIO *receiver = new crsf(&Serial1, pinRX);
    ```
4.  **Initialize Communication**:
    Call the begin() method to initialize communication with the specified serial port:

    ```cpp
    void setup() {
        receiver->begin();
    }
    ```

5.  **Process Incoming Data**:
    In the loop() function, call the processIncoming() method to process incoming bytes:

        ```cpp
        receiver->processIncoming();
        ```

6.  **Retrieve Channel Data**:
    To retrieve the decoded RC channel data, call the getChannel() method, passing a pointer to the channelData structure:

        ```cpp
            receiver->getChannel(&channelData);
        ```

    **see also**: - @ref SerialIO - @ref sbus - @ref crsf - @ref ibus

## Examples {#example}

### CRSF Basic Example

@include "./examples/espresiff/crsf_basic/crsf_basic.ino"

### SBUS Basic Example

@include "./examples/espresiff/sbus_basic/sbus_basic.ino"

# Guide to Adding More Protocols

## Steps

To add more protocols to your project, follow these steps:

1. **Create a New Protocol File** : Start by creating a new header file for each additional protocol you want to add. For example, if you want to add a protocol named "XYZ", create a file named `xyz_protocol.h`.

2. **Define Protocol Structure** : In the protocol header file (`xyz_protocol.h`), define the structure of the protocol, including any necessary constants, data structures, and functions.

3. **Implement Protocol Functions** : Implement the protocol functions in a corresponding source file (`xyz_protocol.cpp`). These functions should handle initializing the protocol, processing incoming data, and extracting channel information.

4. **Include Protocol Header** : In your main project files or wherever you want to use the protocol, include the header file of the protocol you've created (`#include "xyz_protocol.h"`).

5. **Initialize Protocol** : Initialize the protocol in your code by calling the initialization function provided by the protocol implementation.

6. **Process Incoming Data** : Call the function to process incoming data from the protocol whenever data is received.

7. **Extract Channel Information** : Use the provided function to extract channel information from the received data, if applicable.

## Basic Functions Required

For initializing the header of a new protocol, you'll typically need the following basic functions:

- `void begin()` : Initializes the protocol, sets up necessary parameters, and prepares for data reception.
- `void processIncoming()`: Processes incoming data from the protocol, including parsing and interpreting the received data.
- `void getChannels()`: Extracts channel information from the received data, if the protocol deals with channel data.

Here's a basic template for the header of a new protocol:

```cpp
#pragma once
#ifndef XYZ_PROTOCOL_H
#define XYZ_PROTOCOL_H

// Include any necessary headers
#include <Arduino.h>

// Define any constants or data structures specific to the protocol

class XYZProtocol : public SerialIO {
public:
  explicit XYZProtocol(HardwareSerial &rxPort, int rxPin, int txPin,
                       bool inverted = false)
      : SerialIO(&rxPort, rxPin, txPin, inverted){};
  ;
  ~XYZProtocol();

  void begin();
  void processIncoming();
  void getChannel(/* Parameters as needed */);

private:
  HardwareSerial *_serialPort;
  // Add any additional private members as needed
};

#endif // XYZ_PROTOCOL_H
```

# License

This library is distributed under the GNU [General Public License version 3.0](https://www.gnu.org/licenses/gpl-3.0.html).
