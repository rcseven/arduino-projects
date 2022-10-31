#include <SoftwareSerial.h>
const int waterSens = A0;//define water sensor to pin A0
const int speaker = 8;//define speaker to pin 8
const int led = 9;
const int txd = 2;
const int rxd = 3;
SoftwareSerial mySerial = SoftwareSerial (rxd, txd);
int SensorValue;//create sensor data variable

void setup() {


pinMode(speaker, OUTPUT);//set speaker as an output

pinMode(waterSens, INPUT); //set water sensor as an input

pinMode(led, OUTPUT);
    
}

void loop() {
 
  int sensorValue = analogRead(waterSens);//read the water sensor value
if (sensorValue >= 400) {
      tone(speaker, 200, 560);
      delay(200);
      tone(speaker, 600, 800);
      delay(200);
      digitalWrite(led, HIGH);
       mySerial.print("AT+CMGF=1\r"); 
       delay(1000);  
       mySerial.print("AT+CMGS=\"+639663941206\"\r");  
       delay(1000);  
       mySerial.println("INTRUDER ALERT!" );  
       mySerial.print("\r");  
       delay(1000);  
       mySerial.println((char)26);  
       mySerial.println();
       delay(5000);
       tone(speaker, 200, 560);
       delay(200);
       tone(speaker, 600, 800);
       delay(200);
       digitalWrite(led, HIGH);
       
     }//if the sensor senses water then play an alarm
     else
      {
      digitalWrite(led, LOW);
      digitalWrite(speaker, LOW);
      } 
  
}
 