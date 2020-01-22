#include <Arduino.h>

//Buttons
int PIN_UP = 12;
int PIN_DOWN = 11;
int PIN_RIGHT = 9;
int PIN_LEFT = 10;
int PIN_ENTER = 1;
int PIN_ESC = 3;
int PIN_CTRL = 5;
int PIN_SPACE = 7;
int PIN_DEL = 8;
#define statusLed 13

//keys to press
#define KEY_UP 82u
#define KEY_DOWN 81
#define KEY_RIGHT 79
#define KEY_LEFT 80
#define KEY_ENTER 40
#define KEY_ESC 41
#define KEY_CTRL 224
#define KEY_SPACE 44
#define KEY_DEL 42

/*  Keyboard report buffer
    DO NOT CHANGE     */
uint8_t buf[8] = { 0 };

/*  state of button
    DO NOT CHANGE   */
int state = 1;
bool btnPressed = false;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_UP, INPUT);
  pinMode(PIN_DOWN, INPUT);
  pinMode(PIN_LEFT, INPUT);
  pinMode(PIN_RIGHT, INPUT);
  pinMode(PIN_ENTER, INPUT);
  pinMode(PIN_ESC, INPUT);
  pinMode(PIN_CTRL, INPUT);
  pinMode(PIN_SPACE, INPUT);
  pinMode(PIN_DEL, INPUT);


  pinMode(statusLed, OUTPUT);

  // enable internal pull-ups
  digitalWrite(PIN_UP, 1);
  digitalWrite(PIN_DOWN, 1);
  digitalWrite(PIN_RIGHT, 1);
  digitalWrite(PIN_LEFT, 1);
  digitalWrite(PIN_ENTER, 1);
  digitalWrite(PIN_ESC, 1);
  digitalWrite(PIN_CTRL, 1);
  digitalWrite(PIN_SPACE, 1);
  digitalWrite(PIN_DEL, 1);

  delay(200);
}

void loop()
{
  arrowUp();
  checkPressed(PIN_UP);
  arrowDown();
  checkPressed(PIN_DOWN);
  arrowRight();
  checkPressed(PIN_RIGHT);
  arrowLeft();
  checkPressed(PIN_LEFT);
  enterKey();
  checkPressed(PIN_ENTER);
  escKey();
  checkPressed(PIN_ESC);
  ctrlKey();
  checkPressed(PIN_CTRL);
  spaceKey();
  checkPressed(PIN_SPACE);
  deleteKey();
  checkPressed(PIN_DEL);
}

void deleteKey(){
  state = digitalRead(PIN_DEL);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_DEL;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void spaceKey(){
  state = digitalRead(PIN_SPACE);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_SPACE;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void ctrlKey(){
  state = digitalRead(PIN_CTRL);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_CTRL;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void escKey(){
  state = digitalRead(PIN_ESC);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_ESC;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void enterKey(){
  state = digitalRead(PIN_ENTER);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_ENTER;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void arrowUp(){
  state = digitalRead(PIN_UP);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_UP;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void arrowDown(){
  state = digitalRead(PIN_DOWN);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_DOWN;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void arrowLeft(){
  state = digitalRead(PIN_LEFT);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_LEFT;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void arrowRight(){
  state = digitalRead(PIN_RIGHT);
  if (state != 1 && !btnPressed) {
    btnPressed = true;
    buf[2] = KEY_RIGHT;   // set key to press
    Serial.write(buf, 8); // Send keypress
    releaseKey(); //loose press
  }
}

void checkPressed(int pinNumber){
  while (state != 1){
    state = digitalRead(pinNumber);
    delay(20);
  }
   if(state == 1 && btnPressed){
    btnPressed = false;
  }
}

void blinkLed() {
  for (int i = 0; i < 3 ; i++) {
    digitalWrite(statusLed, HIGH);
    delay(100);
    digitalWrite(statusLed, LOW);
    delay(100);
  }
}

/* DO NOT CHANGE */
void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key
  blinkLed();
}
