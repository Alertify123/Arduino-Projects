const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;

long interval = 1670; //for this testing, instead of 10 mins change, it will be 1.67 seconds



void setup() {
  for(int x = 2; x < 8; x++){
    pinMode(x,OUTPUT);
  }

  pinMode(switchPin, INPUT);

}

void loop() {
  unsigned long currentTime = millis();

  if(currentTime - previousTime > interval){
    previousTime = currentTime;

    digitalWrite(led,HIGH);
  led++;

  if(led == 7){
    // for(int i = 7; i >1; i--){
    //   digitalWrite(i,LOW);
    // }
  }
  }

  

  switchState = digitalRead(switchPin); 

  if(switchState != prevSwitchState){
    for(int i = 2; i < 8; i++ ){
      digitalWrite(i,LOW);
    }
  led = 2;
  previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
