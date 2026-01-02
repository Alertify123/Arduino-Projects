int switchState = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2); // stores in switchState if pin 2 has voltage (HIGH or 1) or no voltage (LOW or 0)

  if(switchState == LOW){
    //the button is not pressed

    digitalWrite(3, HIGH); // green led is on
    digitalWrite(4, LOW); // red led is off
    digitalWrite(5, LOW); // red led is off

  }
  else{

    digitalWrite(3, LOW); // green led is off
    digitalWrite(4, LOW); // red led is on
    digitalWrite(5, HIGH); // red led is on

    delay(250); //wait for a quarter second (250 ms or 0.25 sec)
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }  

} // go back to the beginning of the loop
