#include <Servo.h>
// Pins to scan
const uint8_t firstPin = 0;
const uint8_t lastPin  = 5;
bool IPA_servo_open = false;
bool N2O_servo_open = false;
bool fill_servo_open = false;
Servo N2O;
int posN2O = 90;
void setup() {
  Serial.begin(9600);
  // Configure pins 8–13 as inputs (with external pull-downs)
  for (uint8_t pin = firstPin; pin <= lastPin; pin++) {
    pinMode(pin, INPUT);
  }
  N2O.attach(10);
  pinMode(10, INPUT);
}

void loop() {
  for (uint8_t pin = firstPin; pin <= lastPin; pin++) {
    if (digitalRead(pin) == HIGH) {
      // Print dynamic message
      //Serial.print("High on pin ");
      //Serial.print(pin);
      //Serial.println(" Received");
      
      // Debounce / single-edge detect
      delay(10);
      //while (digitalRead(pin) == HIGH) {
      //  delay(1);
      //}
    
    }
  }
    if (digitalRead(2) == HIGH){
      if (IPA_servo_open) {
        Serial.println("Pin 0 driven HIGH, servo already closed");
    }
    else {
      pinMode(10, OUTPUT);
      for (posN2O = 90; posN2O <= 180; posN2O += 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        N2O.write(posN2O);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        IPA_servo_open = true;
    }
  }
    if (digitalRead(2) == LOW){
      if (IPA_servo_open) {
      pinMode(10, OUTPUT);
      for (posN2O = 180; posN2O >= 90; posN2O -= 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        N2O.write(posN2O);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        IPA_servo_open = false;
        Serial.println("Servo closed");
        delay(2000);
    }
    else {
      Serial.println("Pin 0 driven LOW, servo already open");
    }
  }
  // small pause to avoid busy-spin
  delay(5);
}

