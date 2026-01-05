#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2); // 4 is sending to the conductive sensor material through resistor, 2 is the sensing pin

int threshold = 1000;
const int ledPin = 12;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long sensorValue = capSensor.capacitiveSensor(30); // 30 samples
  Serial.println(sensorValue);

  if(sensorValue > threshold){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }
  delay(10);
}
