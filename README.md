# IthoEcoFanRFT
Cloned from Klusjesman, modified to work on Arduino and ESP8266 with Arduino IDE

Will work with a 868MHz CC1101 module.
The CC1150 may also work, except for receiving (which is not required for controlling an Itho EcoFan).
A 433MHz CC1101/CC1150 might also work, because it has the same chip. But a 433MHz CC11xx board has a different RF filter, causing a lot less transmission power (and reception).
```
Connections between the CC1101 and the ESP8266 or Arduino:
CC11xx pins    ESP pins Arduino pins  Description
*  1 - VCC        VCC      VCC           3v3
*  2 - GND        GND      GND           Ground
*  3 - MOSI       13=D7    Pin 11        Data input to CC11xx
*  4 - SCK        14=D5    Pin 13        Clock pin
*  5 - MISO/GDO1  12=D6    Pin 12        Data output from CC11xx / serial clock from CC11xx
*  6 - GDO0       ?        Pin 2?        Serial data to CC11xx
*  7 - CSN        15=D8    Pin 10        Chip select / (SPI_SS)
*  8 - GDO2       ?        Pin  ?        output as a symbol of receiving or sending data
```
Note that CC11xx pins GDO0 and GDO2 are not used (yet).

Beware that the CC11xx modules are 3.3V (3.6V max) on all pins!
This won't be a problem with an ESP8266, but for Arduino you either need to use a 3.3V Arduino or use levelshifters and a separate 3.3V power source.
