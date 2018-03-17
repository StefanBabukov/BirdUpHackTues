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

/*int attack(int x, int interval){
  unsigned long currentmillis = millis();
  
  leds[x-1]=CRGB(0,0,255);
  leds[x+1]=CRGB(0,0,255);

  if(currentmillis - previousmillis >= interval) {
    previousmillis = currentmillis;
  }

  leds[x-1]=CRGB(0,0, 0);
  leds[x+1]=CRGB(0,0,0);
  
} //new

int attack (int x, int interval){
  Serial.print("OK");
  leds[x-1] =  CRGB(150,0,255);
  leds[x+1] =  CRGB(150,0,255);
  FastLED.show();
}
*/
void loop() {
  unsigned long currentmillis = millis();
  
  for(int i = 0; i < 80; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    
  }
   for(int i = 0; i < 80; i++) {
   if(digitalRead(butattack) == HIGH) {
      // attack(i, 1000); //new
       Serial.print("OK");
  leds[i-1] =  CRGB(150,0,255);
  leds[i+1] =  CRGB(150,0,255);
  FastLED.show();
   }
   while(digitalRead(butmove) == LOW);
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
        while(digitalRead(butmove) == LOW); 
        
}


