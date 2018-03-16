#include <FastLED.h>
#define LED_PIN     
#define NUM_LEDS    
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() {
  

}
