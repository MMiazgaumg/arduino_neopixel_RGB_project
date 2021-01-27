#include <Adafruit_NeoPixel.h> // biblioteka wykorzystana przy tworzeniu
int buttonPin1 = 2; // pin na którym jest przycisk 1
int buttonPin2 = 3; // pin na którym jest przycisk 2
int buttonPin3 = 4; // pin na którym jest przycisk 3
int buttonPin4 = 5; // pin na którym jest przycisk 4
int buttonPin5 = 6; // pin na którym jest przycisk 5
int delayTime = 20; //opóżnienie
int ledPin = 8; // pin na którym jest podłączona dioda
int ledCount = 60; // ilość diod
Adafruit_NeoPixel strip(ledCount, ledPin, NEO_GRB + NEO_KHZ800);
void setup()                    
{
pinMode(buttonPin1, INPUT_PULLUP); //przypisanie pinu jako wejście
pinMode(buttonPin2, INPUT_PULLUP);
pinMode(buttonPin3, INPUT_PULLUP);
pinMode(buttonPin4, INPUT_PULLUP);
pinMode(buttonPin5, INPUT_PULLUP);
pinMode(ledPin, OUTPUT); //przypisanie pinu jako wyjście
strip.show(); // wyłacza wszystkie ledy i inicjalizuje
}
void loop()  {          

    
if (isButtonPressed(buttonPin1)){ // pierwsza funkcja naprzemiennie zmieniają się kolory 
  for (int i = 0; i < 10000; i++){
colorchanges(strip.Color(  127,   127, 50), 10); 
colorchanges(strip.Color(  127,   0, 255), 10); // przypisanie koloru
colorchanges(strip.Color(255,   0,   0), 10);
colorchanges(strip.Color(  0, 255,   0), 10); 
colorchanges(strip.Color(  0,   0, 255), 10); 
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
  }
} 


  if (isButtonPressed(buttonPin2)){ //druga funkcja mruganie paska poszczególnymi kolorami
     for (int i = 0; i < 10000; i++){
  blinkingcolor(strip.Color(127, 127, 127), 10); //przypisanie koloru
  blinkingcolor(strip.Color(127,   0,   0), 10); 
  blinkingcolor(strip.Color(  0,   0, 127), 10); 
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
  }
  }

 if (isButtonPressed(buttonPin3)){ //trzecia funckja mruganie policyjnych świateł
   for (int i = 0; i < 10000; i++){
  bomby2(strip.Color(  0,   0, 255), 10); 
  bomby(strip.Color(0,   0,   255), 10); //przypisanie niebieskich światełe
  bomby3(strip.Color(0,   0,   255), 10);
   bomby(strip.Color(0,   0,   255), 10);
 bomby2(strip.Color(  0,   0, 255), 10);
  bomby(strip.Color(0,   0,   255), 10); 
 bomby4(strip.Color(0,   0,   255), 10);
  bomby(strip.Color(0,   0,   255), 10);
  bomby2(strip.Color(  0,   0, 255), 10);
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
  }
  }
if (isButtonPressed(buttonPin4)){ //czwarta funkcja przechodząca tęcza
   for (int i = 0; i < 10000; i++){
        rainbow(10); 
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
  }
    }


if (isButtonPressed(buttonPin5)){ //wyłączenie pokolei paska led
over(strip.Color( 0 , 0, 0),10); //brak ustawionego koloru co pozwoli po kolei wyłączać diody
}
}
bool isButtonPressedoff (int button) { // przypisanie działania przycisków, żeby wyłączyć ledy
  if (digitalRead(button) == LOW) { 
    delay(1);
    if (digitalRead(button) == LOW) {
      return true;
    }
  }
  return false;
}

bool isButtonPressed (int button) { // przypisanie działania przycisków
  if (digitalRead(button) == LOW) { 
    delay(delayTime);
    if (digitalRead(button) == HIGH) {
      return true;
    }
  }
  return false;
}

void colorchanges(uint32_t color,int wait) { //funkcja 1
  for(int i=0; i<strip.numPixels(); i++) { // każdemu ledowi pokolej zostaje ustawiony kolor
    strip.setPixelColor(i, color);         // ustawienie koloru piksela
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;

    strip.show();                          //uaktualnienie paska
    delay(30);                       //opóźnienie
}
}
 

void blinkingcolor(uint32_t color, int wait) { //funkcja 2
  for(int a=0; a<15; a++) { //powtórzenie animacji do 15 razy
    for(int b=0; b<5; b++) {  // mraganie po kolei kazdego leda
      strip.clear();        //czeszczenie ledów
      for(int c=b; c<strip.numPixels(); c += 5) { // co 5 ledów powtarza się cykl
        strip.setPixelColor(c, color); // ustawienie koloru piksela
      }
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
      strip.show();    //uaktualnienie paska
      delay(80); //opóźnienie
    }
  }
}

void bomby(uint32_t color, int wait) { //funkcja 3 identyczny kod jak powyżej tylko zmienione dane 
  for(int a=0; a<15; a++) {
    for(int b=0; b<5; b++) { 
      strip.clear();        
      for(int c=b; c<strip.numPixels(); c += 4) {
        strip.setPixelColor(c, color);
      }
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
      strip.show();    //uaktualnienie paska
      delay(30); //opóźnienie
    }
  }
}

void bomby2(uint32_t color,int wait) { // identyczny jak funkcja 1
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);   
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
    strip.show();                          
    delay(10);
  }
}             

void bomby3(uint32_t color, int wait) { //funkcja 3 identyczny kod jak powyżej tylko zmienione dane 
  for(int a=0; a<15; a++) {
    for(int b=0; b<60; b++) { 
      strip.clear();        
      for(int c=b; c<strip.numPixels(); c +=1) {
        strip.setPixelColor(c, color);
      }
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
      strip.show();    //uaktualnienie paska
      delay(5); //opóźnienie
    }
  }
}

void bomby4(uint32_t color, int wait) { //funkcja 3 identyczny kod jak powyżej tylko zmienione dane 
  for(int a=0; a<15; a++) {
    for(int b=0; b<60; b++) { 
      strip.clear();        
      for(int c=b; c<strip.numPixels(); c +=60) {

        strip.setPixelColor(c, color);
      }
if (isButtonPressedoff(buttonPin5))//podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
      strip.show();    //uaktualnienie paska
      delay(3); //opóźnienie
    }
  }
}
void rainbow(int wait) { //funkcja 4
  for(long firstledhue = 0; firstledhue < 10* 65536; firstledhue += 256) { //wykorzystujemy koło kolorów i opisujemy ilość wykoanych pętli powtórzeń
    for(int i=0; i<strip.numPixels(); i++) { // wykonujemy dla każdego leda
      int ledhue = firstledhue + (i * 65536L / strip.numPixels()); // wykonanie przesunięcia odcienia leda tak by wykonało pełen obórót kolorów
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(ledhue)));// ustawienie pełnego zakresu kolorów
    }
if (isButtonPressedoff(buttonPin5)) //podczas kliknięcia przycisku 5 kończymy pętle i przechodzimmy do funkcji przypisanej na 5 przycisku
break;
    strip.show();     //uaktualnienie paska
    delay(30);  //opóźnienie
  
  }
}

void over(uint32_t color,int wait) { //identyczna  funkcja jak 1 z brakiem wyjścia
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);        
    strip.show();                        
    delay(30);                       
}
}
