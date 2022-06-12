
// Include Libraries
#include "Arduino.h"
#include "Joystick.h"


// Pin Definitions
#define JOYSTICK_PIN_SW	2
#define JOYSTICK_PIN_VRX	A3
#define JOYSTICK_PIN_VRY	A1



// Global variables and defines

// object initialization
Joystick joystick(JOYSTICK_PIN_VRX,JOYSTICK_PIN_VRY,JOYSTICK_PIN_SW);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 min
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // PS2 X Y Axis Joystick Module - Test Code
    // Read Joystick X,Y axis and press
    int joystickX =  joystick.getX();
    int joystickY =  joystick.getY();
    int joystickSW =  joystick.getSW();
    Serial.print(F("X: ")); Serial.print(joystickX);
    Serial.print(F("\tY: ")); Serial.print(joystickY);
    Serial.print(F("\tSW: ")); Serial.println(joystickSW);

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) PS2 X Y Axis Joystick Module"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing PS2 X Y Axis Joystick Module"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
