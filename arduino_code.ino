
#include <Servo.h> //initialize servo library  

Servo servo1; //define servo 1 
Servo servo2; //define servo 2
const int ldrPin = A0;  //define photo diode

void setup() {

Serial.begin(9600); //open serial port

pinMode(ldrPin, INPUT); //define pin mode of photo diode 

servo1.attach(8); //attach servo 1 to pin 8 (right side)
servo1.write(0); // define initial servo 2 placement in degrees 
servo2.attach(10); //attach servo 1 to pin 8 (right side)
servo2.write(0); // define initial servo 2 placement in degrees 

delay(2000);
}

void loop() {

int ldrStatus = analogRead(ldrPin); //read photo sensor

if (ldrStatus <=600) {
 // for glasses down "in the sun"
servo1.write(89);
servo2.write(0);
delay(100);

Serial.println("glasses down"); //used for help when gluing the arms to servos 

}

else {
// for glasses up "in the shade/indoors"
servo1.write(1);  // define servo position when not bright enough 
servo2.write(88); // define servo position when not bright enough 
delay(100);
Serial.println("glasses up"); //used for help when gluing the arms to servos 

}

}
