
#include "aButton.h"


aButton::aButton(byte pin)
{
	this->pin = pin;
	init();
}

void aButton::init()
{
	pinMode(pin, INPUT);
	currentState = 0;
	bounceState = 0;
	averageState = 0;
	bStateNew = RELEASED;
	bStateOld = RELEASED;
	checkButton = false;
}

int aButton::debounceRead()
{

	if (checkButton == false)
	{
		bounceState = 0;
		currentState = analogRead(pin);
		if (currentState < 1000)
		{
			checkButton = true;
			debounceTime = millis();
		}
	}

	if (checkButton == true)
	{

		currentTime = millis();
		if (currentTime - debounceTime >= debounceDelay)
		{
			bounceState = analogRead(pin);
			if (bounceState == currentState)
			{
				averageState = ((bounceState + currentState) / 2);
			}
			//	Serial.print("Average: ");
			//	Serial.println(averageState);
			if (averageState < 185 && averageState > 145)
			{
				checkButton = false;
				//Serial.println(1);
				return 1;
			}
			else if (averageState < 290 && averageState > 260)
			{
				checkButton = false;
				//Serial.println(2);
				return 2;
			}
			else if (averageState < 450 && averageState > 420)
			{
				checkButton = false;
				//Serial.println(3);
				return 3;
			}
			else if (averageState < 615 && averageState > 585)
			{
				checkButton = false;
				//Serial.println(4);
				return 4;
			}
			else if (averageState < 745 && averageState > 715)
			{
				checkButton = false;
				//Serial.println(5);
				return 5;
			}
			else if (averageState < 850 && averageState > 820)
			{
				checkButton = false;
				//Serial.println(6);
				return 6;
			}
			else if (averageState < 945 && averageState > 915)
			{
				checkButton = false;
				//Serial.println(7);
				return 7;
			}
			else if (averageState < 1000 && averageState > 960)
			{
				checkButton = false;
				//Serial.println(8);
				return 8;
			}
			else
			{
				checkButton = 0;
			}
		}
	}
	if (checkButton == false)
	{
		return 0;
	}
}

int aButton::toggleSwitch()
{
	bStateNew = debounceRead();									//call the debounce function
	if (bStateNew == RELEASED && bStateOld != RELEASED)			//run if the button changes state from pressed to 
	{                                                           //not pressed, this means it toggles after the button 
																//is released, regardless of how long it is held down
		returnVal = bStateOld;

	}
	else
	{
		returnVal = 0;
	}

	bStateOld = bStateNew;
	return returnVal;
}