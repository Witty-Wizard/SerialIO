# SBUS Protocol Overview
The SBUS (Serial Bus) protocol is a digital communication protocol commonly used in radio-controlled (RC) systems for transmitting control signals between transmitters and receivers. SBUS offers several advantages over traditional PWM (Pulse Width Modulation) signals, including higher resolution, lower latency, and support for multiple channels over a single wire.

## Key Features
Inverted UART Communication: SBUS utilizes inverted UART serial communication, where logical high and low states are inverted compared to standard UART.
Baud Rate: The standard baud rate for SBUS communication is 100,000 bits per second (100 kbps).
Data Frame: Each SBUS data frame consists of 25 bytes of information, including servo channel data, digital channel data, flags, and synchronization information.
Channel Data: SBUS supports up to 16 proportional servo channels and two digital channels.
Frame Rate: The frame rate for SBUS communication is typically around 200 Hz, providing rapid updates for precise control.