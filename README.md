# ESP32 LED Control via Linux Terminal

This project demonstrates Linux-to-ESP32 communication using UART and C programming.

## Overview
A Linux user-space application sends numeric commands to an ESP32 via serial communication.  
The ESP32 firmware interprets the command and blinks an LED accordingly.



## Command Behavior
| Input | Action |
|------|-------|
| 1 | LED blinks once |
| 2 | LED blinks twice |
| 3 | LED blinks three times |
| 4 | LED blinks four times |

## Concepts Used
- Linux serial communication
- Makefile build automation
- ESP32 GPIO control
- UART-based command interface

## Tools
- ESP32
- Linux (Ubuntu)
- GCC
- Arduino IDE
