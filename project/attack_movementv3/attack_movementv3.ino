#include <FastLED.h>
#define LED_PIN     8
#define NUM_LEDS    80
int button_move_R = 7;
#define BRIGHTNESS  150
int button_move_L = 9;
int button_attack = 5;
int i = 0;
int lastmovement;// -1 left, 1 right
int direct;
CRGB leds[NUM_LEDS];

//unsigned long previousmillis = 0;
//const long interval = 1000;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(button_move_R, INPUT);
pinMode(button_move_L, INPUT);  
  pinMode(button_attack, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
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
  FastLED.show();
  return x;
}
int endGame(int red,int green, int blue){
        for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(red, green, blue);
        FastLED.show();
        //i++;
        }
        while(digitalRead(button_move_R) == LOW&&digitalRead(button_move_L)==LOW&&digitalRead(button_attack)==LOW);   
        for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(0, 0, 0);
        FastLED.show();
        //i++;
        }
}
int Enemies=0;
int j;
int startTime;
int SpawnLocation;
int mobLocations;
CRGB mob[NUM_LEDS];
int spawnMob(int x){
  if(Enemies<6&&millis()>Enemies*4000){
    Serial.print("Spawn!");
    SpawnLocation=random(x+15,80);
    Serial.print(SpawnLocation);
    Enemies++;
    if(SpawnLocation==mobLocations){
      SpawnLocation=random(x+15,80);
    }
    leds[SpawnLocation]=CRGB(255,0,0);
    FastLED.show();
    mobLocations=SpawnLocation;
  }
  
}
void loop() {
  
  Serial.println(startTime);
 // startTime = millis();
   while(i<80) {
   while(digitalRead(button_move_R)== LOW && digitalRead(button_move_L)  == LOW&&digitalRead(button_attack)==LOW){
        spawnMob(i-1);
   }
        spawnMob(i-1);
  if(digitalRead(button_move_R)==HIGH){
     if(leds[i]==CRGB(255,0,0)){
        endGame(255,0,0);
        i=0;
        lastmovement=1;
        continue;
      }
    leds[i-1] = CRGB(0, 0, 0);
    leds[i] = CRGB(0, 255, 0);
    FastLED.show();
    i++;
    if(i > lastmovement) {
      direct = 1;
    }
    lastmovement=i;
    delay(100);
    }
   

   else if (digitalRead(button_move_L)==HIGH){
   if(i == 0){   
   //if(digitalRead(button_move_L)==HIGH){
    i =  1;
  // }
   }
   if(leds[i]==CRGB(0,255,0)){
    leds[i] = CRGB(0, 0, 0);
   }
    leds[i-1] = CRGB(0, 255, 0);
    i--;
    if(i < lastmovement) {
      direct = 0;
    }
    lastmovement=i;
    FastLED.show();
    delay(100);
    }
    if(digitalRead(button_attack)==HIGH){
    Serial.println("attack is pressed");
    if(direct == 1) {
      attack(i-1);
    }
    if(direct == 0) {
      attack(i);
    }
   }
   
   }
   i=0;
   endGame(0,255,255);
}



