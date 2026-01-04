//variables to calibrate sensor
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13; // just using pin 13 as the book says, cuz its connected to a L light by default

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  
  sensorValue = analogRead(A0);
/*
Calculates the frequency 
input is current sensorValue, calibration is low and high, and the output mapping to 50hz (very low hum) to 4000hz(very high screech)
*/
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8,pitch,20); // tone(pin 8, at this frequency, at this duration)

  delay(10);
}
