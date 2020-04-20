// aButton.h

#ifndef _ABUTTON_h
#define _ABUTTON_h
#include <Arduino.h>

class aButton
{
private:
	byte pin;

public:
	aButton(byte pin);
	void init();
	int debounceRead();
	int toggleSwitch();

	const unsigned long debounceDelay = 30;
	unsigned long debounceTime, currentTime;

	const int RELEASED = 0;
	int currentState;
	int bounceState;
	int averageState;
	int bStateNew;
	int bStateOld;
	int returnVal = 0;
	bool checkButton;

};






#endif

