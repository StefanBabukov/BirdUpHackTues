#include <FastLED.h>
#define LED_PIN     8
#define NUM_LEDS    80
int butmove = 7;
int butattack = 9;
int i = 0;
CRGB leds[NUM_LEDS];

//unsigned long previousmillis = 0;
//const long interval = 1000;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(butmove, INPUT);
  pinMode(butattack, INPUT);
  Serial.begin(9600);
}
int attack(int x){
  Serial.print("ATTACK");
  leds[x+1]=CRGB(255,255,0);
  leds[x-1]=CRGB(255,255,0);
  FastLED.show();
  if(leds[x+1]==CRGB(255,0,0)||leds[x-1]==CRGB(255,0,0)){//
    leds[x+1]=CRGB(0,0,0);                   //
    leds[x-1]=CRGB(0,0,0);                   // CHECKS FOR AN ENEMY AND 
    leds[x-1]=CRGB(255,255,0);              //  REMOVES IT.
    leds[x+1]=CRGB(255,255,0);   
    FastLED.show();
  }
  delay(300);
  leds[x+1]=CRGB(0,0,0);
  leds[x-1]=CRGB(0,0,0);
  return x;
}
int endGame(int red,int green, int blue){
        for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(red, green, blue);
        FastLED.show();
        //i++;
        }
        while(digitalRead(butmove) == LOW);   
        for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(0, 0, 0);
        FastLED.show();
        //i++;
        }
}
void loop() {
  leds[20]=CRGB(255,0,0);
  leds[30]=CRGB(255,0,0);
  leds[40]=CRGB(255,0,0);
  leds[30]=CRGB(255,0,0);
  unsigned long currentmillis = millis();
 
   for(int i = 0; i < 80; i++) {
   while(digitalRead(butmove) == LOW&&digitalRead(butattack)==LOW);
   if(digitalRead(butmove)==HIGH){
    if(leds[i]==CRGB(255,0,0)){
      endGame(255,0,0);
      i=0;
      continue;
    }
    leds[i - 1] = CRGB(0, 0, 0);
    leds[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(100);
    }
    if(digitalRead(butattack)==HIGH){
    attack(i-1);
    i--;
   }
   }
   endGame(0,255,0);
}



