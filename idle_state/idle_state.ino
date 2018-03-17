#include <FastLED.h>
#define LED_PIN     8
#define NUM_LEDS    80
int r = 0;
int g = 0;
int b = 0;
int interval = 10000;
CRGB leds[NUM_LEDS];
unsigned long prevmillis = 0;

void mod1() {

  if(r == 0) {
    r = 255;
  }
    
  if(g == 255) {
    g = 0;
  }

  if(b == 255) {
    b = 0;
  }
  
  for(int i = 0; i < 80; i++) {
  leds[i] = CRGB(r, g, b);
  FastLED.show();
  }
    
  for(int i = 0; i < 80; i++) {
  leds[i] = CRGB(0, 0, 0);
  FastLED.show();
  }

  r -= 40;
  g += 30;
  b += 20;
    
  for(int i = 80; i > 0; i--) {
  leds[i] = CRGB(r, g, b);
  FastLED.show();
  }

  for(int i = 80; i > 0; i--) {
  leds[i] = CRGB(0, 0, 0);
  FastLED.show();
  }

  r += 20;
  g += 30;
  b -= 40;
}

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  unsigned long currmillis = millis();

    if(currmillis - prevmillis >= interval) {
      prevmillis = currmillis;
      i++;
      if(i == 1) {
        mod1();
      }
    }
}
