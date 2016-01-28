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
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

//variables declaration
boolean valOnePresent;
String num[1000]; //used to store numerical keypresses as strings until used
int value = 0; //used to move array pointer forward to store next number
int ans;

void setup()
{
  Serial.begin(9600);
}


//ok, now how to make a calculator? we need to have these commands saved as variables or something




//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
  
  char key = myKeypad.getKey();
  
  if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0')){
      valOnePresent = true;
      num[value] += (char)key;
      Serial.print(key);
  }

  else if (key != NO_KEY && key == '*'){
    if (!valOnePresent){
      
    }
    else{
        Serial.print(key);
        num[value] += (char)'\n';
        value++;
    }
  }

  else if (key != NO_KEY && key == '#' ){
      if(valOnePresent){
          ans = 0;
          ans = num[0].toInt();
          num[0] = "";
          int x;
          for(x = 1; x <= value; x++){
              ans *= num[x].toInt();
              
              //clear values as we go
              num[x] = "";
          }
          Serial.print("=");
          Serial.println(ans);

          //clear values for next run
          valOnePresent = false;
          value = 0;
          
      }
      else{
        Serial.println("Error: No Numbers Present");
      }
  }  
}
