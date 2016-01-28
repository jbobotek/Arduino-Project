#include <Keypad.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 3; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {44,42,40,38}; //Rows 0 to 3
byte colPins[numCols]= {50,48,46}; //Columns 0 to 2

//initializes an instance of the Keypad class
Keypad keypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
byte ledPin = 13;

char pound = '#';
char star = '*';

boolean poundPress = false;
boolean starPress = false;
boolean poundRelease = false;
boolean starRelease = false;
boolean poundHold = false;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  digitalWrite(ledPin, LOW);   // sets the LED on
  keypad.setHoldTime(2000);//user must hold down a key for 2 seconds to trigger HOLD event
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
  
  // Fills keypad.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (keypad.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( keypad.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (keypad.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    if(keypad.key[i].kchar == star){
                        digitalWrite(ledPin, LOW);
                        starPress = true;
                        starRelease = false;
                        poundHold = false;
                    }
                    if(keypad.key[i].kchar == pound){
                        poundPress = true;
                        poundRelease = false;
                    }
                break;
                    case HOLD:
                    if(keypad.key[i].kchar == pound){
                        digitalWrite(ledPin, HIGH);
                        poundHold = true;
                    }
                break;
                    case RELEASED:
                    if(keypad.key[i].kchar == star){
                        starPress = false;
                        starRelease = true;
                    }
                    if(keypad.key[i].kchar == pound){
                        poundPress = false;
                        poundRelease = true;
                    }
                break;
                    case IDLE:
                    break;
                  }
            }
        }
        
    }
    if(starPress && poundPress){
        digitalWrite(ledPin, !digitalRead(ledPin));
        Serial.println("ALERT MOO");
          
    }
    if(starRelease && poundRelease && !poundHold){
          digitalWrite(ledPin, LOW);
    }
}
