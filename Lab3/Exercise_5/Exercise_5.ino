
byte ledPin = 13;

int col0 = 21, col1 = 20, col2 = 19, row0 = 18, row1 = 17, row2 = 16, row3 = 15;


void initializePin()
{
  pinMode(col0, INPUT_PULLUP);
  pinMode(col1, INPUT_PULLUP);
  pinMode(col2, INPUT_PULLUP);
  pinMode(row0, OUTPUT);
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  digitalWrite(row0, LOW);
  digitalWrite(row1, LOW);
  digitalWrite(row2, LOW);
  digitalWrite(row3, LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  digitalWrite(ledPin, LOW);   // sets the LED on
  attachInterrupt(digitalPinToInterrupt(col0), ISR21, LOW);
  attachInterrupt(digitalPinToInterrupt(col1), ISR20, LOW);
  attachInterrupt(digitalPinToInterrupt(col2), ISR19, LOW);
}

void loop()
{
    initializePin();
    attachInterrupt(digitalPinToInterrupt(col0), ISR21, LOW);
    attachInterrupt(digitalPinToInterrupt(col1), ISR20, LOW);
    attachInterrupt(digitalPinToInterrupt(col2), ISR19, LOW);
}

void ISR21(){

  //pin 21 interrupt, look for writes from noncontrol pins, then 
  //figures out what button was pressed, and prints out that button to console
  
  detachInterrupt(digitalPinToInterrupt(col0));
  pinMode(row0, INPUT_PULLUP);
  pinMode(row1, INPUT_PULLUP);
  pinMode(row2, INPUT_PULLUP);
  pinMode(row3, INPUT_PULLUP);
  pinMode(col0, OUTPUT);
  digitalWrite(col0, LOW);
 
  if (digitalRead(row0) == LOW) {
    Serial.println('1');
  }
  if (digitalRead(row1) == LOW) {
    Serial.println('4');
  }
  if (digitalRead(row2) == LOW) {
    Serial.println('7');
  }
  if (digitalRead(row3) == LOW) {
    Serial.println('*');
  }
}

void ISR20(){

  //pin 20 interrupt, look for writes from noncontrol pins, then 
  //figures out what button was pressed, and prints out that button to console
  
  detachInterrupt(digitalPinToInterrupt(col0));
  pinMode(row0, INPUT_PULLUP);
  pinMode(row1, INPUT_PULLUP);
  pinMode(row2, INPUT_PULLUP);
  pinMode(row3, INPUT_PULLUP);
  pinMode(col1, OUTPUT);
  digitalWrite(col1, LOW);
 
  if (digitalRead(row0) == LOW) {
    Serial.println('2');
  }
  if (digitalRead(row1) == LOW) {
    Serial.println('5');
  }
  if (digitalRead(row2) == LOW) {
    Serial.println('8');
  }
  if (digitalRead(row3) == LOW) {
    Serial.println('0');
  }
}

void ISR19(){

  //pin 19 interrupt, look for writes from noncontrol pins, then 
  //figures out what button was pressed, and prints out that button to console
  
  detachInterrupt(digitalPinToInterrupt(col0));
  pinMode(row0, INPUT_PULLUP);
  pinMode(row1, INPUT_PULLUP);
  pinMode(row2, INPUT_PULLUP);
  pinMode(row3, INPUT_PULLUP);
  pinMode(col2, OUTPUT);
  digitalWrite(col2, LOW);
 
  if (digitalRead(row0) == LOW) {
    Serial.println('3');
  }
  if (digitalRead(row1) == LOW) {
    Serial.println('6');
  }
  if (digitalRead(row2) == LOW) {
    Serial.println('9');
  }
  if (digitalRead(row3) == LOW) {
    Serial.println('#');
  }
}

