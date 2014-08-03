#!/bin/bash

echo "Setting Fuse Bits"
sudo avrdude -c usbtiny -p m32 -P usb -U lfuse:w:0b11101111:m
sudo avrdude -c usbtiny -p m32 -P usb -U hfuse:w:0b11001001:m
echo "Finish"
