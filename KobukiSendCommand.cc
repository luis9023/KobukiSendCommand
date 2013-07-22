#include "KobukiSendCommand.h"
#include <stdio.h>
#include <iomanip>
#include <iostream>

using namespace std;
		//Global Variables. Which are the first two constants for the kobuki packet
		unsigned char header0 = 0xaa;
		unsigned char header1 = 0x55;

		//*************NOTE**************//
		//Kobuki works Low Byte High Byte//
		//*******************************//

void setBaseControl(unsigned short Speed, unsigned short Radius) {	//Send packet for base control
		
		KobukiCommand CommandKobuki;
		CommandKobuki.Length = 6;
		CommandKobuki.commandData = 1;
		CommandKobuki.commandDataSize = sizeof(baseControl);

		CommandKobuki.speedLow = Speed & 0xff;
		CommandKobuki.speedHigh = Speed >> 8;
		CommandKobuki.radiusLow = Radius & 0xff;
		CommandKobuki.radiusHigh = Radius >> 8;

		FILE * file;
		file = fopen("/dev/kobuki","w");		

		char buffer[] = {header0, header1, CommandKobuki.Length, CommandKobuki.commandData, CommandKobuki.commandDataSize, CommandKobuki.speedLow, CommandKobuki.speedHigh, CommandKobuki.radiusLow, CommandKobuki.radiusHigh};
				
		int totalSize = (int) CommandKobuki.Length + 3;
		unsigned char checksum = 0;
		
		for (unsigned int i = 2; i < totalSize; i++)
			checksum ^= buffer[i];
 
		fwrite(buffer, 1, totalSize, file);
		fwrite(&checksum, 1, 1, file);
		fclose(file);
}

void setLed(int Led) {
		KobukiCommand CommandKobuki;
		CommandKobuki.Length = 4;
		CommandKobuki.commandData = 12;
		CommandKobuki.commandDataSize = sizeof(SetDigitalOut);
		CommandKobuki.LedLow = 0;
		CommandKobuki.LedType = (char)Led;

		FILE * file;
		file = fopen("/dev/kobuki","w");	

		char buffer[] = {header0, header1, CommandKobuki.Length, CommandKobuki.commandData, CommandKobuki.commandDataSize, CommandKobuki.LedLow, CommandKobuki.LedType};
		int totalSize = (int) CommandKobuki.Length + 3;
		unsigned char checksum = 0;
		
		for (unsigned int i = 2; i < totalSize; i++)
			checksum ^= buffer[i];
 
		fwrite(buffer, 1, totalSize, file);
		fwrite(&checksum, 1, 1, file);
		fclose(file);
}

void setSound(unsigned char Sound) {		//Send Packet of SOUND
		KobukiCommand CommandKobuki;
		CommandKobuki.Length = 3;
		CommandKobuki.commandData = 4;
		CommandKobuki.commandDataSize = sizeof(Sound);

		CommandKobuki.soundType = Sound;
		FILE * file;
		file = fopen("/dev/kobuki","w");		

		char buffer[] = {header0, header1, CommandKobuki.Length, CommandKobuki.commandData, CommandKobuki.commandDataSize, CommandKobuki.soundType};
				
		int totalSize = (int) CommandKobuki.Length + 3;
		unsigned char checksum = 0;
		
		for (unsigned int i = 2; i < totalSize; i++)
			checksum ^= buffer[i];
 
		fwrite(buffer, 1, totalSize, file);
		fwrite(&checksum, 1, 1, file);
		fclose(file);
}

int main() {
		/*unsigned short speed = 300;	to drive
		unsigned short radius = 600;
		unsigned char sound = 6;
		setBaseControl(speed, radius);
		setSound(sound);
		while (true) {
			speed = 200;
			radius = 250;
			setBaseControl(speed, radius);
		}*/

		/*unsigned int led = 1;	to control led
		setLed(led);*/
	

	return 0;
}
