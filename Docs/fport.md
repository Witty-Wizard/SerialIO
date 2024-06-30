# FrSky F.Port {#frskyfport}

FrSky F.Port is a protocol developed by FrSky Electronic Co., Ltd., designed for communication between receivers and connected devices like servos or sensors. It is a one-line bus system that supports both control and data transmission, operating at a higher speed (115200 baud per second) compared to its predecessor, S.Port.

## Specifications

- [Physical Layer](#physical_fport)
- [Message Format](#format_fport)

### Physical Layer {#physical_fport}

The physical layer of the FrSky F.Port protocol utilizes UART (Universal Asynchronous Receiver-Transmitter) communication at a baud rate of 115200.

#### Uart Configuration

When it comes to the configuration of the UART communication for SBus, it uses the following format:

- **8 bits of data**: Each data frame consists of 8 bits, representing the information being transmitted.
- **No parity**: It does not use parity bit instead it uses a checksum at the end of the whole packet.
- **1 stop bits**: Following the data bits and the parity bit, there are 1 stop bits. Stop bits indicate the end of a data frame and provide timing for the receiving device to process the data.

### Message Format {#format_fport}
For the data format and more details go to [this link](https://github.com/betaflight/betaflight/files/1491056/F.Port.protocol.betaFlight.V2.1.2017.11.21.pdf) 
