#include "FastLED.h"
#include "Arduino.h"
#define NUM_LEDS 80
#define DATA_PIN 8
int button_move_R = 7;
int button_move_L = 9;
int i = 0;
int LEDSpeed = 0;         
int maxLEDSpeed = 1000;     
int LEDAcceleration = 20;           
int LEDPosition = 0;        
byte intensity = 250;         
byte bright = 10;           
int animationDelay = 0;     
boolean constSpeed = true;

CRGB leds[NUM_LEDS];
byte ledh[NUM_LEDS];
byte ledb[NUM_LEDS];

void setup()
{
  pinMode(button_move_R, INPUT);
  pinMode(button_move_L, INPUT);
  delay(2000); 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); 
}
void cylon()
{
  constSpeed = true;
  showLED(LEDPosition, 0, 255, intensity);
  fadeLEDs(200);
  setDelay(LEDSpeed);
}
void showLED(int pos, byte LEDhue, byte LEDsaturation, byte LEDbright)
{
  leds[pos] = CHSV(LEDhue,LEDsaturation,LEDbright);
  FastLED.show(); 
}

void fadeLEDs(int fadeVal){
  for (int i = 0; i<NUM_LEDS; i++){
    leds[i].fadeToBlackBy(fadeVal);
  }
}

void setDelay(int LSpeed)
{
  animationDelay = maxLEDSpeed - abs(LSpeed);
  delay(animationDelay);  
}
void adjustSpeed()
{
  LEDSpeed = LEDSpeed + LEDAcceleration;                        
  if (LEDSpeed>0)
  {
    LEDPosition++;                                     
  }
  if (LEDSpeed<0)
  {
    LEDPosition--;                                     
  }
}

void loop()
{ 
  while(i<80)
  {
     while(digitalRead(button_move_R)== LOW && digitalRead(button_move_L)  == LOW);
          //spawnMob(i-1);
        //}
        //spawnMob(i-1);
      if(digitalRead(button_move_R)==HIGH)
      {
        /*if(leds[i]==CRGB(255,0,0))
        * {
            endGame(255,0,0);
            i=0;
            lastmovement=1;
            continue;
          }*/
        LEDSpeed = 400;
      }
   

   else if (digitalRead(button_move_L)==HIGH)
   {
     /*   if(LEDPosition == 0){   
        //if(digitalRead(button_move_L)==HIGH){
    LEDPosition =  1;
  // }*/
        LEDSpeed = -400;
   }

   
    
    /*if(digitalRead(button_attack)==HIGH){
    Serial.println("attack is pressed");
    if(direct == 1) {
      attack(i-1);  if(LEDPosition == 0){   
        //if(digitalRead(button_move_L)==HIGH){
    LEDPosition =  1;
  // }
    }
    if(direct == 0) {
      attack(i);
    }
   }*/
   
   }
   adjustSpeed();
   cylon();
   //cylon();
//  movement();
  


}


