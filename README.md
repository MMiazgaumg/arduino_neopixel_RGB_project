#  Projekt led sterowany na przyciski
## Opis projektu
Układ sterowania paskiem RGB. Projekt będzie polegał na sterowaniu po przez przyciski kolorami paska LED RGB. 

Przy wykorzystaniu: 
- arduino uno, 
- pasek led RGB WS2813B, 
- 5 x przcisków ,
- zasilacz 5V 3A,
- rezystor 330WW,
- 10 x kondenstaro elektrolityczny 100uF.

Układ po przycisnięciu przycisku, będzie wykonywał różne funkcje:
- Przycisk pierwszy będzie powodował zapalanie pokolei ledów na jeden kolor, aż to zapełnienia całego paska jednym kolorem.
- Przycisk drugi będzie powodował mruganie pokolei co określony odstęp ledów w takim samym kolorze, 
- Przycisk trzeci będzie powodował palenie się ledów jak tzw."policyjne bomby",
- Przycisk czwarty będzie powodował tworzenie tęczy płynnie przechodzącej po pasku led,
- Przycisk piąty będzie służył do czyszczenia paska led oraz umożliwienie włączenia innej funkcji.

## Wykonany układ na zdjęciach
![Zdjęcie układu](image2.jpeg)
![Zdjęcie układu](image3.jpeg)
![Zdjęcie układu](image4.jpeg)
![Zdjęcie układu](image5.jpeg)

## Film pokazujący działanie układu
https://youtu.be/r7FylPGo1qg

## Opis kodu

Kod jest wykonany na pasek o długości 60 ledów. Przy tworzeniu programu wykorzystaliśmy bibliotekę Adafruit_NeoPixel. W tej części kodu przypisujemy wszystkie piny, ilość ledów, stały czas opóźnienia oraz wpisujemy bilioteke z której korzystamy.

``` c++
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
```
