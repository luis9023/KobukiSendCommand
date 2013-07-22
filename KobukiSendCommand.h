#ifndef INCLUDED_KobukiSendCommand_h_
#define INCLUDED_KobukiSendCommand_h_
	
	void setBaseControl(unsigned short Speed, unsigned short Radius);
	void setLed(int Led);
	void setSound(int Sound);

	struct BaseControl {
			unsigned char speed[2];					//2
			unsigned char radius[2];				//2
		};

	struct Sound {
			unsigned char note;						//1
		};

	struct SoundSequence {
			unsigned char segmentName;
		};

	struct RequestExtra {
			unsigned char requestFlag;
		};

	struct ChangeFrame {
			unsigned char frameId;
		};

	struct RequestEeprom {
			unsigned char frameId;
		};

	struct SetDigitalOut {
			unsigned char gpOut[2];
		};

	struct KobukiCommand {
			unsigned char Length;
			unsigned char commandData;
			unsigned char commandDataSize;			


			//BaseControl
			unsigned char speedHigh;
			unsigned char speedLow;
			unsigned char radiusHigh;
			unsigned char radiusLow;

			//Sound
			/**********************************
			**********SoundTypes***************
			TurningOn = 0
			TurningOff = 1
			RechargeStart = 2
			PressButton = 3
			ErrorSound = 4
			Start Cleaning = 5
			CleaningEnd = 6
			************************************
			***********************************/
			unsigned char soundType;

			//Led
			unsigned char LedLow;
			unsigned char LedType;

	};

	enum CommandName {
			baseControl = 1,
			sound = 3,
			soundSequence = 4,
			requestExtra = 9,
			changeFrame = 10,
			requestEeprom = 11,
			setDigitalOut = 12,
		};




#endif
