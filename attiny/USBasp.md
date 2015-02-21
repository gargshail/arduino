# firmware upgrade notes

Below command was able to flash the firmware but I was not able to use the programmer afterwords
avrdude -c avrisp -p m8  -P /dev/ttyACM0 -b 19200 -U flash:w:usbasp.2005-04-21.hex



It worked after flashing firmware with this command   -B5 is to set sync period
avrdude -c avrisp -p m8  -B5 -P /dev/ttyACM0 -b 19200 -U flash:w:usbasp.atmega8.2011-05-28.hex

and
able to read it using
avrdude -c avrisp -p m8  -B5 -P /dev/ttyACM0 -b 19200 -U flash:w:usbasp.atmega8.2011-05-28.hex

If I remove -B5 then it erros out as below

	avrdude: error: programm enable: target doesn't answer. 1


you can specify -B5 setting in ~/.avrduderc or /etc/avrdude.con with following line

## modify .avrduderc or /etc/avrdude.conf  Higher value means slower bitclock

	default_bitclock = 3;



