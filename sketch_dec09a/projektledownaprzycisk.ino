#include <Adafruit_NeoPixel.h> // biblioteka 
int buttonPin1 = 2; // pin na którym jest przycisk 1
int buttonPin2 = 3;
int buttonPin3 = 4;
int buttonPin4 = 5;
int buttonPin5 = 6;
int delayTime = 20;
int ledPin = 8; // pin na którym jest podłączona dioda
int ledCount = 60; // ilość diod
Adafruit_NeoPixel strip(ledCount, ledPin, NEO_GRB + NEO_KHZ800);
void setup()                    
{
pinMode(buttonPin1, INPUT_PULLUP);
pinMode(buttonPin2, INPUT_PULLUP);
pinMode(buttonPin3, INPUT_PULLUP);
pinMode(buttonPin4, INPUT_PULLUP);
pinMode(buttonPin5, INPUT_PULLUP);
pinMode(ledPin, OUTPUT);
strip.begin();
strip.show();
}
void loop()  {          
        
if (isButtonPressed(buttonPin1)){ 
 
colorchanges(strip.Color(  127,   0, 255), 10); 
colorchanges(strip.Color(255,   0,   0), 10);
colorchanges(strip.Color(  0, 255,   0), 10); 
colorchanges(strip.Color(  0,   0, 255), 10); 

}


  if (isButtonPressed(buttonPin2)){
  blinkingcolor(strip.Color(127, 127, 127), 10); 
  blinkingcolor(strip.Color(127,   0,   0), 10); 
  blinkingcolor(strip.Color(  0,   0, 127), 10); 
  }

 if (isButtonPressed(buttonPin3)){
  bomby(strip.Color(0,   0,   255), 10); 

  }
if (isButtonPressed(buttonPin4)){
    rainbow(10);
}


if (isButtonPressed(buttonPin5)){
colorchanges(strip.Color( 0 , 0, 0),10); 
}
}

bool isButtonPressed (int button) {
  if (digitalRead(button) == LOW) {
    delay(delayTime);
    if (digitalRead(button) == HIGH) {
      return true;
    }
  }
  return false;
}

void colorchanges(uint32_t color,int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         
    strip.show();                          
    delay(30);                       
}
}




void blinkingcolor(uint32_t color, int wait) {
  for(int a=0; a<15; a++) {
    for(int b=0; b<3; b++) { 
      strip.clear();        
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); 
      }
      strip.show();
      delay(70);
    }
  }
}

void bomby(uint32_t color, int wait) {
  for(int a=0; a<15; a++) {
    for(int b=0; b<5; b++) { 
      strip.clear();        
      for(int c=b; c<strip.numPixels(); c += 4) {

        strip.setPixelColor(c, color);
      }
      strip.show();
      delay(40);
    }
  }
}


void rainbow(int wait) {
  for(long firstledhue = 0; firstledhue < 5* 65536; firstledhue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { 
      int ledhue = firstledhue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(ledhue)));
    }
    strip.show(); 
    delay(30);  
  }
}
