# Fiber Audio TX  
**Transmitter Firmware**

Firmware for the **fiber-optic audio transmitter** based on AVR microcontrollers.

---

## Features
- Audio sampling and transmission over optical fiber
- UART or ISP flashing supported
- Simple GNU Make build system

---

## Dependencies

Required toolchain:

- `gcc`
- `avr-gcc`
- `avr-libc`
- `avrdude`
- `make`

### Install on Debian / Ubuntu
```bash
sudo apt install gcc-avr binutils-avr avr-libc avrdude build-essential
