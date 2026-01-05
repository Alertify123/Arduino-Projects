import processing.serial.*;
Serial myPort;

PImage logo;
int bgcolor = 0;


void setup(){
  
  size(1,1);
  surface.setResizable(true);
  colorMode(HSB, 255);
  
  logo = loadImage("https://icon2.cleanpng.com/20180809/gfb/kisspng-arduino-max-electronic-circuit-pure-data-oscillosc-arduino-bluetooth-control-google-play-5b6cda38e3f4d0.6548838615338604089337.jpg");
  
  surface.setSize(logo.width, logo.height);
  
  println("Available serial ports: ");
  println(Serial.list());
  
  myPort = new Serial(this, Serial.list()[1], 9600);
}


void draw(){
  if(myPort.available() > 0){
    bgcolor = myPort.read();
    println(bgcolor);
  println(bgcolor);
  }
  
  background(bgcolor, 255, 255);
  image(logo,0,0);
}
