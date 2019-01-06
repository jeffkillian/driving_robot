const int motorPin = 9;

void setup() {
 pinMode(9, OUTPUT)
  Serial.begin(9600);     
}

void loop() {
 { // This example basically replicates a blink, but with the motorPin instead.
  int onTime = 3000;  // milliseconds to turn the motor on
  int offTime = 3000; // milliseconds to turn the motor off

  analogWrite(motorPin, 255); // turn the motor on (full speed)
  delay(onTime);                // delay for onTime milliseconds
  analogWrite(motorPin, 0);  // turn the motor off
  delay(offTime);               // delay for offTime milliseconds

  // Uncomment the functions below by taking out the //. Look below for the
  // code examples or documentation.
  
  // speedUpandDown(); 
  // serialSpeed();
}
}
