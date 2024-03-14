@page tutorial Tutorial

To use the library for decoding RC protocols in your Arduino project, follow these steps:

1. **Include Necessary Libraries**:
   Include the required libraries at the beginning of your sketch:
   ```cpp
   #include <crsf/crsf.h>
   #include <sbus/sbus.h>
   #include <serialIO.h>
   ```
2. **Define Channel Data Structure**:
   Define a structure to hold the decoded RC channel data.
   ```cpp
   crsf_channels_t channelData;
   ```
3. **Instantiate SerialIO Object**:
   Create an instance of the serialIO class, specifying the serial port, RX pin, and TX pin:
   ```cpp
   serialIO *receiver = new crsf(Serial1, pinRX, pinTX);
   ```
4. **Initialize Communication**:
   Call the begin() method to initialize communication with the specified serial port:
   ```cpp
   void setup() {
       receiver->begin();
   }
   ```

5. **Process Incoming Data**:
In the loop() function, call the processIncoming() method to process incoming bytes:

    ```cpp
    receiver->processIncoming();
    ```
6. **Retrieve Channel Data**:
To retrieve the decoded RC channel data, call the getChannel() method, passing a pointer to the channelData structure:

    ```cpp
        receiver->getChannel(&channelData);
    ```
**see also**:
    - @ref serialIO
    - @ref sbus
    - @ref crsf