/*
 * Original Author: Klusjesman
 *
 * Tested with STK500 + ATMega328P
 * GCC-AVR compiler
 * 
 * Modified by supersjimmie:
 * Code and libraries made compatible with Arduino and ESP8266 
 * Tested with Arduino IDE v1.6.5 and 1.6.9
 * For ESP8266 tested with ESP8266 core for Arduino v 2.1.0 and 2.2.0 Stable
 * (See https://github.com/esp8266/Arduino/ )
 * 
 */

/*
CC11xx pins    ESP pins Arduino pins  Description
1 - VCC        VCC      VCC           3v3
2 - GND        GND      GND           Ground

3 - MOSI       13=D7    Pin 11        Data input to CC11xx
4 - SCK        14=D5    Pin 13        Clock pin
5 - MISO/GDO1  12=D6    Pin 12        Data output from CC11xx / serial clock from CC11xx
6 - GDO0       ?        Pin 2?        Serial data to CC11xx
7 - GDO2       ?        Pin  ?        output as a symbol of receiving or sending data
8 - CSN        15=D8    Pin 10        Chip select / (SPI_SS)
*/

#include <SPI.h>
#include "IthoCC1101.h"
#include "IthoPacket.h"

IthoCC1101 rf;
IthoPacket packet;

void setup(void) {
  Serial.begin(115200);
  delay(500);
  Serial.println("setup begin");
  rf.init();
  Serial.println("setup done");
  sendRegister();
  Serial.println("join command sent");
}

void loop(void) {
	//set CC1101 registers
	rf.initReceive();
	Serial.print("start\n");
	sei();

	while (1==1) {
		if (rf.checkForNewPacket()) {
			packet = rf.getLastPacket();
			//show counter
			Serial.print("counter=");
			Serial.print(packet.counter);
			Serial.print(", ");
			//show command
			switch (packet.command) {
        case IthoUnknown:
          Serial.print("unknown\n");
          break;
        case IthoAway:
          Serial.print("away\n");
          break;
        case IthoLow:
          Serial.print("low\n");
          break;
        case IthoMedium:
          Serial.print("medium\n");
          break;
        case IthoFull:
          Serial.print("full\n");
          break;
        case IthoTimer1:
          Serial.print("timer1\n");
          break;
        case IthoTimer2:
          Serial.print("timer2\n");
          break;
        case IthoTimer3:
          Serial.print("timer3\n");
          break;
        case IthoJoin:
          Serial.print("join\n");
          break;
        case IthoLeave:
          Serial.print("leave\n");
          break;
			} // switch (recv) command
		} // checkfornewpacket
	yield();
	} // while 1==1
} // outer loop

void sendRegister() {
   Serial.println("sending join...");
   rf.sendCommand(IthoJoin);
   Serial.println("sending join done.");
}

void sendAway() {
   Serial.println("sending away...");
   rf.sendCommand(IthoAway);
   Serial.println("sending away done.");
}
void sendLowSpeed() {
   Serial.println("sending low...");
   rf.sendCommand(IthoLow);
   Serial.println("sending low done.");
}

void sendMediumSpeed() {
   Serial.println("sending medium...");
   rf.sendCommand(IthoMedium);
   Serial.println("sending medium done.");
}

void sendFullSpeed() {
   Serial.println("sending FullSpeed...");
   rf.sendCommand(IthoFull);
   Serial.println("sending FullSpeed done.");
}

void sendTimer() {
   Serial.println("sending timer...");
   rf.sendCommand(IthoTimer1);
   Serial.println("sending timer done.");
}

