#include <FastLED.h>
#define LED_PIN     8
#define NUM_LEDS    80
#define BRIGHTNESS  150
int button_move_R = 7;
int button_move_L = 9;
int i = 0;
int check =0;
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(button_move_R, INPUT);
  pinMode(button_move_L, INPUT);
  Serial.begin(9600);
  //FastLED.setBrightness(BRIGHTNESS);
 // FastLED.setDither(1);

}

void loop() { 

  
 movement();
}

void movement(){

   while(i<80) {
    check = 0;
   while(digitalRead(button_move_R)== LOW && digitalRead(button_move_L)  == LOW);
    
    if(digitalRead(button_move_R)==HIGH){
    leds[i - 1] = CRGB(0, 0, 0);
    leds[i] = CRGB(225, 0, 0);
    FastLED.show();
    i++;
    delay(100);
    }
   

   else if (digitalRead(button_move_L)==HIGH){
   if(i == 0)
   {
    
   if(digitalRead(button_move_L)==HIGH){
    i =  1;
   }
   }
    leds[i] = CRGB(0, 0, 0);
    leds[i-1] = CRGB(225, 0, 0);
    FastLED.show();
    i--;
    delay(100);
    }
    
   }
        for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(0, 255, 255);
        FastLED.show();
        }
        while(digitalRead(button_move_R) && digitalRead(button_move_L) == LOW); 
          for(int i = 0; i < 80; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }    
  
  
}

