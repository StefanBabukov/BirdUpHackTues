#include "FastLED.h"
#include "Arduino.h"
#define NUM_LEDS 80
#define DATA_PIN 8
int button_move_R = 7;
int button_move_L = 9;
int i = 0;
int LEDSpeed = 300;         
int maxLEDSpeed = 1000;     
int LEDAcceleration = 0;           
int LEDPosition = 0;        
byte intensity = 250;         
byte bright = 10;           
int animationDelay = 0;     
boolean constSpeed = true;
int lt;
int rt;

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
/*void cylon()
{
  constSpeed = true;
  showLED(LEDPosition, 0, 255, intensity);
  fadeLEDs(200);
  setDelay(LEDSpeed);
}*/
void showLED(int pos, byte LEDhue, byte LEDsaturation, byte LEDbright) 
{
  leds[pos] = CHSV(LEDhue,LEDsaturation,LEDbright);
  FastLED.show(); 
}

void fadeLEDs(int fadeVal)
{
  for (int i = 0; i<NUM_LEDS; i++)
  {
    leds[i].fadeToBlackBy(fadeVal);
  }
}



void setDelay(int LSpeed)
{
  animationDelay = maxLEDSpeed - abs(LSpeed);
  delay(animationDelay);  
}
int Direction(int RT)
{
  if(constSpeed)
  {
    LEDAcceleration = 1; 
    if(RT>0)
    {
      LEDSpeed = maxLEDSpeed/1.1;   
    } 
    if (RT<0)
    {
      LEDSpeed = -maxLEDSpeed/1.1;  
    }
  }
  LEDSpeed = LEDSpeed + LEDAcceleration;                        
  if(LEDSpeed>0)
  {
    LEDPosition++;                                     
  }
  if (LEDSpeed<0)
  {
    LEDPosition--;                                     
  }
}
bool fadeActive = false;

void loop()
{ 
  while(digitalRead(button_move_R)== LOW && digitalRead(button_move_L)  == LOW);
  if(digitalRead(button_move_R)==HIGH){
     rt = 1;

    }
  else if(digitalRead(button_move_L)==HIGH){
    rt= -1;
  } 
  Direction(rt);  
 // lt = 0;
  //rt = 0;
  showLED(LEDPosition, 0, 255  fadeActive = true;  fadeActive = true;, intensity);
  fadeLEDs(1000);
  setDelay(LEDSpeed);
//  movement();
  
}


