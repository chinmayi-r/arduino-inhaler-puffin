/* For use with a Gas sensor with an analog out! 
  
  - If the Sensor detects many particles; "case 0" will be activated and the exact amount of particles in the air will be sent to the serial and bluetooth monitor.
  - If the Sensor detects few particles; "case 1" will be activated and the exact amount of particles in the air will be sent to the serial and bluetooth monitor.
  - If the Sensor does not dedect any particles; "case 2" will be activated and and "No particles" will be sent to the serial and bluetooth monitor. 
*/

#include<SoftwareSerial.h>
const int Gassensor = A0;
int blueToothTx = 8;
int blueToothRx = 9;
int switchState = 0;           //If the two wires are connected
// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 900;  // sensor maximum
SoftwareSerial blueTooth(blueToothTx,blueToothRx);
void setup() {
 pinMode(Gassensor,INPUT);
// pinMode(2,OUTPUT);
 //pinMode(3,OUTPUT);
 //pinMode(4,OUTPUT);
 pinMode(5,INPUT);
 //pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(A1,OUTPUT);
 digitalWrite(11,HIGH);
 digitalWrite(12,HIGH);
 analogWrite(A1,0);
 Serial.begin(9600);
// initialize serial communication at 9600 bits.
  blueTooth.begin(9600);
  // initialize bluetooth communication at 9600 bits.
  //for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    //pinMode( pinNumber,OUTPUT);
    //digitalWrite( pinNumber, LOW);
  //}
}
void loop() {
  switchState = digitalRead(5);
  // read the sensor on analog A0:
  int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)
  int range = map(sensorReading , sensorMin , sensorMax , 0, 3);
  
  // range value:
  switch (range) {
 case 0:    // Extreme pollution
    Serial.println(analogRead(A0));
    if(switchState==HIGH){
    //  digitalWrite(10,HIGH);
      Serial.print('d');
      Serial.println(analogRead(A0));
       blueTooth.print('d');
      blueTooth.println(analogRead(A0));
    }
    else{
      blueTooth.println(analogRead(A0));
    }
    //digitalWrite(2,LOW);
    //digitalWrite(3,HIGH);
    //digitalWrite(4,LOW);
    break;
 case 1:    // Some amount of particles
    Serial.println(analogRead(A0));
    if(switchState==HIGH){
      //digitalWrite(10,HIGH);
      Serial.print('d');
      Serial.println(analogRead(A0));
      blueTooth.print('d');
      blueTooth.println(analogRead(A0));
      
    }
    else{
      blueTooth.println(analogRead(A0));
    }
    //digitalWrite(2,LOW);
    //digitalWrite(3,LOW);
    //digitalWrite(4,HIGH);
    break;
 case 2:    // Very few particles
    Serial.println("Hardly any particles");
    if(switchState==HIGH){
      //digitalWrite(10,HIGH);
      Serial.print('d');
      Serial.println(analogRead(A0));
       blueTooth.print('d');
      blueTooth.println(analogRead(A0));
    }
    else
    {
      blueTooth.println(analogRead(A0));
    }
    //digitalWrite(2,HIGH);
    //digitalWrite(3,LOW);
    //digitalWrite(4,LOW);  
    break;
   }
   delay(500);// delay between reads
   //digitalWrite(10,LOW);
   //digitalWrite(2,LOW);
   //digitalWrite(3,LOW);
   //digitalWrite(4,LOW);
  }
