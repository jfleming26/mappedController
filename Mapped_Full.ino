#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "aButton.h"
#include "Routes.h"

constexpr byte LED = 13;

Adafruit_PWMServoDriver driver0 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver driver1 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver driver2 = Adafruit_PWMServoDriver(0x42);
Adafruit_PWMServoDriver* controller[3] = { &driver0, &driver1, &driver2 };
constexpr int SERVOMIN = 120;   // This is the 'minimum' pulse length count (out of 4096)
constexpr int SERVOMAX = 440;   // This is the 'maximum' pulse length count (out of 4096)
constexpr int POINTMIN = 120;   // This is the 'minimum' pulse length count (out of 4096)
constexpr int POINTMAX = 440;   // This is the 'maximum' pulse length count (out of 4096)
constexpr byte SERVO_FREQ = 50; // Analog servos run at ~50 Hz updates
int servonum = 0;

//aButton button[6] = { A0, A1, A2, A3, A4, A5 };
aButton button[3] = { A0, A1, A2};
byte updateSw[6] = { 0 };


void setup()
{
    Serial.begin(9600);
    Serial.println("Start");

    for (int i = 0; i < 3; ++i)
    {
        controller[i]->begin();
        controller[i]->setOscillatorFrequency(27000000);
        controller[i]->setPWMFreq(SERVO_FREQ);
    }

    //updatePoints();
    Serial.println("System Ready \n\n");

}


void loop()
{

    updateSw[0] = button[0].toggleSwitch();
    updateSw[1] = button[1].toggleSwitch();
    updateSw[2] = button[2].toggleSwitch();
 /*   updateSw[3] = button[3].toggleSwitch();
    updateSw[4] = button[4].toggleSwitch();
    updateSw[5] = button[5].toggleSwitch();
*/
    for (int i = 0; i < 2; ++i)
    {
        if (updateSw[i] != 0)
        {
            callRoute = updateSw[i] + (i*8);
        }
    }

    if (callRoute != 0)
    {
        copyArray(activeRoute, oldRoute);
 /*       Serial.print("callRoute = ");
        Serial.println(callRoute);
 */       
        unsigned long startTime = millis();

        checkRoute(callRoute);

/*        Serial.print(activeRoute[1][1]);
        Serial.print("\t");
        Serial.println(oldRoute[1][1]);
*/
        updatePoints();
        callRoute = 0;

        unsigned long endTime = millis();
        unsigned long duration = (endTime - startTime);
        double sDuration = double(duration) / 1000;
        Serial.print("Completed in ");
        Serial.print(sDuration);
        Serial.println(" seconds \n\n");
    }
}


void updatePoints()
{
    for (int i = 0; i < 6; ++i)
    {
        for (int x = 0; x < 8; ++x)
        {
            int z = x + 8;
            
            if (activeRoute[i][x] != oldRoute [i][x] && activeRoute[i][x] == 1)
            {
                delay(200);
                switch (i)
                {
                    case 0:
                    {
                        controller[0]->setPWM(x, 0, POINTMIN);
                       
                        break;
                    }
                    case 1:
                    {
                        controller[0]->setPWM(z, 0, POINTMIN);
                        
                        break;
                    }
                    case 2:
                    {
                        controller[1]->setPWM(x, 0, POINTMIN);
                        
                        break;
                    }
                    case 3:
                    {
                        controller[1]->setPWM(z, 0, POINTMIN);
                        
                        break;
                    }
                    case 4:
                    {
                        controller[2]->setPWM(x, 0, POINTMIN);
                      
                        break;
                    }
                    case 5:
                    {
                        controller[2]->setPWM(z, 0, POINTMIN);
                    
                        break;
                    }
                }
            }
            if (activeRoute[i][x] != oldRoute[i][x] && activeRoute[i][x] == 2)
            {
                delay(200);
                switch (i)
                    {
                    case 0:
                    {
                        controller[0]->setPWM(x, 0, POINTMAX);
                       
                        break;
                    }
                    case 1:
                    {
                        controller[0]->setPWM(z, 0, POINTMAX);
            
                        break;
                    }
                    case 2:
                    {
                        controller[1]->setPWM(x, 0, POINTMAX);
                        
                        break;
                    }
                    case 3:
                    {
                        controller[1]->setPWM(z, 0, POINTMAX);
                        
                        break;
                    }
                    case 4:
                    {
                        controller[2]->setPWM(x, 0, POINTMAX);
                       
                        break;
                    }
                    case 5:
                    {
                        controller[2]->setPWM(z, 0, POINTMAX);
               
                        break;
                    }
                }
            }
        }
    }
}

