const int red = 9;
const int green = 10;
const int blue = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  mainColours();
  showSpectrum(); 
}

void mainColours(){
  //All leds off
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue,LOW);
  delay(1000);

  //Only Red on
   digitalWrite(red, HIGH);
   digitalWrite(green, LOW);
   digitalWrite(blue,LOW);
   delay(1000);

   //Only green on
   digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue,LOW);
  delay(1000);

  //Only blue on
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue,HIGH);
  delay(1000);

  //Yellow (red+green)
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue,LOW);
  delay(1000);

  //Cyan(green+blue)
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue,HIGH);
  delay(1000);

  //Purple (red+blue)
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(1000);

  //White (All on)
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue,HIGH);
  delay(1000);
}

void showSpectrum(){
  //Shows all the 768 colours
  for(int i = 0; i <= 768; i++){
    showRGB(i);
    delay(10);
  }
}

void showRGB(int colour){
  //translates the int to a colour value on the RGB spectrum.
  //Each colour spans 255
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  if (colour <= 255){
  redIntensity = (255 - colour); //red goes from on to off
  greenIntensity = colour;    //green goes from off to on
  blueIntensity = 0;          //blue off    
  }
  else if (colour <= 511){
  redIntensity = 0;                        //red off
  greenIntensity =255 - (colour - 256);    //green goes from on to off
  blueIntensity = (colour - 256);          //blue off to onn    
  }
  else{
  redIntensity = (colour - 512);           //red goes from off to on
  greenIntensity = 0;                      //green off
  blueIntensity = 255 - (colour - 512);    //blue off to onn    
  }
  analogWrite(red, redIntensity);
  analogWrite(green, greenIntensity);
  analogWrite(blue, blueIntensity);
}
