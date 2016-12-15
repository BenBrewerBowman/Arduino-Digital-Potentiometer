# Arduino-Digital-Potentiometer

Arduino Mega SPI control for digital potentiometer: AD5171BRJZ5-R2, Analog Devices Inc., 5kOhm. 
(May work with other potentiometers by same manufacturer, untested.)

Control loop to fluctuate potentiometer up, then down, then up, then down. 
Ex. Glowing, then dimming and LED.

May need to change SPI configuration to work:
adress/SS: corresponding to particular slave number (0 if only one digital pot)
CS: corresponds to either MOSI or MISO pin depending on if input or output

Knowledge of SPI is required
