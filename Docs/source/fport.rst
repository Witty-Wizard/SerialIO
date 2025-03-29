.. _frskyfport:

FrSky F.Port
=============

FrSky F.Port is a protocol developed by FrSky Electronic Co., Ltd., designed for communication between receivers and connected devices like servos or sensors. It is a one-line bus system that supports both control and data transmission, operating at a higher speed (115200 baud per second) compared to its predecessor, S.Port.

Specifications
--------------

- `Physical Layer`_
- `Message Format`_

.. _physical_fport:

Physical Layer
--------------

The physical layer of the FrSky F.Port protocol utilizes UART (Universal Asynchronous Receiver-Transmitter) communication at a baud rate of 115200.

UART Configuration
^^^^^^^^^^^^^^^^^^

The configuration of the UART communication for F.Port uses the following format:

- **8 bits of data**: Each data frame consists of 8 bits, representing the information being transmitted.
- **No parity**: It does not use a parity bit. Instead, it uses a checksum at the end of the whole packet for error detection.
- **1 stop bit**: Following the data bits, there is 1 stop bit. Stop bits indicate the end of a data frame and provide timing for the receiving device to process the data.

.. _format_fport:

Message Format
--------------

For the data format and more details, refer to the official documentation at the following link:

- `F.Port Protocol Specification (BetaFlight V2.1, 2017.11.21) <https://github.com/betaflight/betaflight/files/1491056/F.Port.protocol.betaFlight.V2.1.2017.11.21.pdf>`_

