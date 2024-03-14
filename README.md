![Doxygen CI](https://github.com/Witty-Wizard/SerialIO/actions/workflows/main.yaml/badge.svg)
[![Doxygen](https://github.com/adafruit/ci-arduino/blob/master/assets/doxygen_badge.svg)](https://witty-wizard.github.io/SerialIO/)
![GitHub License](https://img.shields.io/github/license/Witty-Wizard/SerialIO)

# SerialIO Library

A versatile Arduino library that provides support for decoding multiple RC protocols such as SBUS and CRSF.

# Overview

SerialIO is a common library designed to simplify the implementation of RC protocol decoding in Arduino projects. It provides a modular and extensible architecture that allows for easy integration of various RC protocols.

## Supported Protocols

- [SBUS](https://witty-wizard.github.io/SerialIO/sbusintro.html) : Futaba SBUS protocol.
- [CRSF](https://witty-wizard.github.io/SerialIO/crsfintro.html) : Crossfire RC protocol.

## Installation

To use the SerialIO library in your Arduino projects, follow these installation steps:

1. Install the library directly from PlatformIO by adding the following line to your `platformio.ini` file:

   ```ini
   lib_deps = Witty-Wizard/SerialIO @ ^0.0.2
   ```
