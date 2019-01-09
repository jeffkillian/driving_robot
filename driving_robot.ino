#include <IRremote.h>

/*
   - Pins 5 and 6: controlled by Timer 0 used for delay, millis, and micros
  - Pins 9 and 10: controlled by timer 1    servo library
  - Pins 11 and 3: controlled by timer 2    tone
*/
const int motorPin = 8;
const int IRInputPin = 2;
const String forward = "fda05f";
const String repeat = "ffffff";

unsigned long lastButtonTime = millis();
const int timeoutDelay = 2000;  // milliseconds - I'm guessing here, this needs to be longer than the IR repeat interval

IRrecv irrecv(IRInputPin);
decode_results results;


void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {

  if (irrecv.decode(&results)) {
    irrecv.resume();// Continue to look for more inputs
    String buttonPressed = String(results.value, HEX);
    Serial.println(buttonPressed);

    if (buttonPressed == forward) {
      moveForward();
    }

    if (buttonPressed) {
      moveForward();
    }

  }

  if (millis() - lastButtonTime > timeoutDelay) {
    digitalWrite(motorPin, LOW);  // turn the motor off
  }





}

void moveForward() {
  lastButtonTime = millis();
  digitalWrite(motorPin, HIGH); // turn the motor on (full speed)
}

