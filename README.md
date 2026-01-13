# fiber-audio
EE2PRJ Team 03 Repo.

DEPENDANCIES:

gcc
,avr-gcc
,avr-libc
,avrdude
make

can be installed with : sudo apt install gcc-avr binutils-avr avr-libc avrdude build-essential
or use whatever toolchain you want

BUILD INSTRUCTIONS:

1.) make clean - cleanup

2.) make all - build hex binary

3.) make flash - flash via uart OR make flashISP - flash via ISP
