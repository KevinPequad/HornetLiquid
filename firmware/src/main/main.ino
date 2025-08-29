#include <Servo.h>
// Pins to scan
const uint8_t firstPin = 0;
const uint8_t lastPin  = 5;
bool IPA_servo_open = true;
bool N2O_servo_open = true;
bool fill_servo_open = false;
Servo N2O;
Servo IPA;
Servo fill;
int posN2O = 180;
int posIPA = 180;
int posfill = 90;
int x;
int y;
int z;
void setup() {
  Serial.begin(9600);
  // Configure pins 8–13 as inputs (with external pull-downs)
  //for (uint8_t pin = firstPin; pin <= lastPin; pin++) {
    //pinMode(pin, INPUT);
  //}
  N2O.attach(10);
  pinMode(10, INPUT);
  IPA.attach(9);
  pinMode(9, INPUT);
  fill.attach(11);
  pinMode(11, INPUT);
}

void loop() {
  //for (uint8_t pin = firstPin; pin <= lastPin; pin++) {
    //if (digitalRead(pin) == HIGH) {
      // Print dynamic message
      //Serial.print("High on pin ");
      //Serial.print(pin);
      //Serial.println(" Received");
      
      // Debounce / single-edge detect
      //delay(10);
      //while (digitalRead(pin) == HIGH) {
      //  delay(1);
      //}
    
    //}
  //}
//high signal from t7 = close valve
    if (digitalRead(4) == HIGH){
      if (N2O_servo_open) {
      pinMode(10, OUTPUT);
      for (posN2O = 180; posN2O >= 90; posN2O -= 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        N2O.write(posN2O);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        x = 1;
        N2O_servo_open = false;     
    }
    else {
      if (x == 1) {
      Serial.println("Pin 4 driven HIGH, servo already closed");
      x = 0;
      }
    }
  }
  //low signal from t7 = open valve
    if (digitalRead(4) == LOW){
      if (N2O_servo_open) {
        if (x == 0) {
        Serial.println("Pin 4 driven LOW, N2O servo already open");
        x = 1;
        }
    }
    else {
      pinMode(10, OUTPUT);
      for (posN2O = 90; posN2O <= 180; posN2O += 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        N2O.write(posN2O);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        x = 0;
        N2O_servo_open = true;    
    }

  }
//IPA SERVO
//high signal from t7 = close valve
    if (digitalRead(3) == HIGH){
      if (IPA_servo_open) {
      pinMode(10, OUTPUT);
      for (posIPA = 180; posIPA >= 90; posIPA -= 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        IPA.write(posIPA);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        y = 1;
        Serial.println("IPA Servo Closed");
        IPA_servo_open = false;     
    }
    else {
      if (y == 1) {
      Serial.println("Pin 3 driven HIGH, servo already closed");
      y = 0;
      }
    }
  }
  //low signal from t7 = open valve
    if (digitalRead(3) == LOW){
      if (IPA_servo_open) {
        if (y == 0) {
        Serial.println("Pin 3 driven LOW, IPA servo already open");
        y = 1;
        }
    }
    else {
      pinMode(10, OUTPUT);
      for (posIPA = 90; posIPA <= 180; posIPA += 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        IPA.write(posIPA);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        y = 0;
        IPA_servo_open = true;    
    }

  }
//FILL Servo
//high signal from t7 = close valve
    if (digitalRead(2) == HIGH){
      if (fill_servo_open) {
      pinMode(10, OUTPUT);
      for (posfill = 180; posfill >= 90; posfill -= 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        fill.write(posfill);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        z = 1;
        fill_servo_open = false;     
    }
    else {
      if (z == 1) {
      Serial.println("Pin 2 driven HIGH, servo already closed");
      z = 0;
      }
    }
  }
  //low signal from t7 = open valve
    if (digitalRead(2) == LOW){
      if (fill_servo_open) {
        if (z == 0) {
        Serial.println("Pin 2 driven LOW, fill servo already open");
        z = 1;}
    }
    else {
      pinMode(10, OUTPUT);
      for (posfill = 90; posfill <= 180; posfill += 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
        fill.write(posfill);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
  }

        pinMode(10, INPUT);
        z = 0;
        fill_servo_open = true;    
    }

  }
}

