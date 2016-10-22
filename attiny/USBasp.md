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


# Setup issues

Resolve permissions issue 

sudo vi /etc/udev/rules.d/uspasp.rules
SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", GROUP="dialout", MODE="0666"

systemctl restart udev

vendor id is displayed in 
	dmesg
	usb 2-1.1: Product: USBasp
	usb 2-1.1: Manufacturer: www.fischl.de
	usb 2-1.1: USB disconnect, device number 10
	usb 2-1.1: new low-speed USB device number 11 using ehci-pci
	usb 2-1.1: New USB device found, idVendor=16c0, idProduct=05dc


You need to select following options correctly
1. Board  - Attiny25/45/85 
2. Processor - Attiny85
3. Port
4. Clock - internal 8MHz 


