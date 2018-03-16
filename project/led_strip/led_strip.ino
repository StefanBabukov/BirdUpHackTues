#include <FastLED.h>
#define LED_PIN     8
#define NUM_LEDS    80
int button = 7;
int i = 0;
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {
  for(int i = 0; i < 80; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    
  }
   for(int i = 0; i < 80; i++) {
   while(digitalRead(button) == LOW); 
    leds[i - 1] = CRGB(0, 0, 0);
    leds[i] = CRGB(225, 0, 0);
    //leds[i + 1] = CRGB(225, 0, 0);
    FastLED.show();
    //i++;
    delay(50);
    }
    for(int i = 0; i < 80; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    i++;
  }    
    
        for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(0, 255, 0);
        FastLED.show();
        //i++;
        }
        while(digitalRead(button) == LOW); 
        
}
