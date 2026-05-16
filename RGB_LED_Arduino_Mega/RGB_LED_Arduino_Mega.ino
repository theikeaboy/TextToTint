const int redPin = 10;
const int greenPin = 8;
const int bluePin = 6;

void setup() {
  // put your setup code here, to run once;
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
Serial.begin(9600);
setColor(0, 0, 0);
}

void loop() {
  // put your main code here, to run repeatedly;
Serial.print("Tell me the color you want: ");
while(Serial.available() == 0){}
if(Serial.available() > 0) {
  String colorInput = Serial.readStringUntil('\n');
  colorInput.trim();
  colorInput.toLowerCase();
  if (colorInput.indexOf("red") >= 0) {
    Serial.println("red");
    setColor(255, 0, 0);
    }
    else if(colorInput.indexOf("green") >= 0) {
      Serial.println("green");
      setColor(0, 255, 0);
      }
    else if(colorInput.indexOf("blue") >= 0) {
      Serial.println("blue");
      setColor(0, 0, 255);
      }
    else if(colorInput.indexOf("purple") >= 0) {
      Serial.println("purple");
      setColor(128, 0, 128);
      }
    else if(colorInput.indexOf("orange") >= 0) {
      Serial.println("orange");
      setColor(255,165,0);
    }
    else if(colorInput.indexOf("pink") >= 0) {
      Serial.println("pink");
      setColor(189, 4, 105);
    }
    else if(colorInput.indexOf("white") >= 0) {
      Serial.println("white");
      setColor(255, 255, 255);
    }
    else if(colorInput.indexOf("yellow") >= 0) {
      Serial.println("yellow");
      setColor(255, 255, 0);
    }
    else if(colorInput.indexOf("off") >= 0) {
      Serial.println("off");
      setColor(0, 0, 0);
    }
    else if(colorInput.indexOf("rainbow") >= 0) {
      while(Serial.available() <= 0) {
        Serial.println("rainbow");
        rainbowEffect();
      }
    }
    else {Serial.println("color not registered");}



    
  }

}

void rainbowEffect(){
  for(int i = 0; i <=255; i+=5){
    if(Serial.available() > 0) return;
    setColor(255 - i, i, 0);
    delay(50);
  }
  for(int i = 0; i <=255; i+=5){
    if(Serial.available() > 0) return;
    setColor(0, 255 - i, i);
    delay(50);
  }
  for(int i = 0; i <=255; i+=5){
    if(Serial.available() > 0) return;
    setColor(i, 0, 255 - i);
    delay(50);
  }
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, 255 - r);
  analogWrite(greenPin, 255 - g);
  analogWrite(bluePin, 255 - b);
}
