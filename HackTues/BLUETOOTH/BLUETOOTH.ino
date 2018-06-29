#include <FastLED.h>
#include <SoftwareSerial.h>
#define LED_PIN     8 // Data pin for led tape
#define NUM_LEDS    80
int button_move_R = 7;
int button_move_L = 9;
int button_attack = 5;
int i = 0;
SoftwareSerial mySerial(8, 9);
int lastmovement;// 0 left, 1 right
int direct;
long previousTime = 0;
CRGB leds[NUM_LEDS];
int enemyPos[80]; // has the enemy poition 
int playerPos[80];
bool isAlive=true;

int attack(int x, int y) {

  if (x+2 == y){
   
 
    enemyPos[y] = 0;
    leds[x - 2] = CRGB(0,0,255);
    leds[x - 1] = CRGB(0,0,255);
    leds[x + 1] = CRGB(0,0,255);
    leds[x + 2] = CRGB(0,0,255);
    FastLED.show();
  
  }
  if(y-x <2){
  if(enemyPos[y] == 0) {
    leds[y] = CRGB(0,0,0);
    isAlive = false;
    //Serial.println("HIT HT HIT");
    FastLED.show();
  }
  }
  leds[x - 2] = CRGB(0,0,255);
  leds[x - 1] = CRGB(0,0,255);
  leds[x + 1] = CRGB(0,0,255);
  leds[x + 2] = CRGB(0,0,255);
  leds[x] = CRGB(0,255,0);
  FastLED.show();
  leds[x - 2] = CRGB(0,0,0);
  leds[x - 1] = CRGB(0,0,0);
  leds[x + 1] = CRGB(0,0,0);
  leds[x + 2] = CRGB(0,0,0);
  FastLED.show(); 

}

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(button_move_R, INPUT);
  pinMode(button_move_L, INPUT);  
  pinMode(button_attack, INPUT);
  Serial.begin(9600);
  Serial.begin(9600);
   mySerial.begin(9600);
}

int second, third, forth, fifth;
int x = 80;

void loop() {  
   while(mySerial.available()) { 
     Serial.print(mySerial.read());
  if(mySerial.read()==1){
    //Serial.println("move right");
    if(i >= 79){   
      for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(0, 170, 255);
        FastLED.show();
        //i++;
        }
        while(digitalRead(button_move_R) == LOW&&digitalRead(button_move_L)==LOW&&digitalRead(button_attack)==LOW);   
        for(int i = 0; i < 80; i++) {
        leds[i] = CRGB(0, 0, 0);
        FastLED.show();
        //i++;
        }
        i = 0;
        x = 79;
    }
    if(leds[i] == CRGB(255,0,0)) {
          for(int i = 0; i < 80; i++) {
            leds[i] = CRGB(255, 0, 0);
            FastLED.show();
            //i++;
            }
            while(digitalRead(button_move_R) == LOW&&digitalRead(button_move_L)==LOW&&digitalRead(button_attack)==LOW);   
            for(int i = 0; i < 80; i++) {
            leds[i] = CRGB(0, 0, 0);
            FastLED.show();
            //i++;
          }
          i = 0;
          x = 79;
    }
    playerPos[i] = 1;
    playerPos[i-1] = 0;
    if(playerPos[i] == 1 && playerPos[i - 1] == 0) {
      leds[i-1] = CRGB(0, 0, 0);
      leds[i] = CRGB(0, 255, 0);
    }
    i++;
    if(i > lastmovement) {
      direct = 1;
    }
    lastmovement=i;
    FastLED.show();
    delay(50);
  }
  
  else if (mySerial.read()==2){
   // Serial.println("move left");
    if(i == 0){   
      i =  1;
    }
    playerPos[i]=0;
    playerPos[i-1]=1;
    if(playerPos[i] == 0 && playerPos[i - 1] == 1) {
      leds[i] = CRGB(0, 0, 0);
      leds[i-1] = CRGB(0, 255, 0);
    }
    i--;
    if(i < lastmovement) {
      direct = 0;
    }
    lastmovement=i;
    FastLED.show();
    delay(50);
  }
  
   if(Interval(millis(), 200, &previousTime))
    {
      if(isAlive == false){
      x = -1;
      }
      x--;
      if (x == -1) {
        x = 80;
      }
      
      /*second = x + 2;
      third = x + 3;
      forth = x + 4;
      fifth = x + 5;*/
      //if(enemyPos[x] != playerPos[i])
      //Serial.println("1: ");
      //Serial.println(x);
      enemyPos[x] = 1;
      enemyPos[x + 1] = 0;
      leds[x] = CRGB(255,0,0);
      leds[x + 1] = CRGB(0,0,0);
      /*enemyPos[second] = 1;
      enemyPos[second + 1] = 0;
      leds[second] = CRGB(255,0,0);
      leds[second + 1] = CRGB(0,0,0);
      enemyPos[third] = 1;
      enemyPos[third + 1] = 0;
      leds[third] = CRGB(255,0,0);
      leds[third + 1] = CRGB(0,0,0);
      enemyPos[forth] = 1;
      enemyPos[forth + 1] = 0;
      leds[forth] = CRGB(255,0,0);
      leds[forth + 1] = CRGB(0,0,0);
      enemyPos[fifth] = 1;
      enemyPos[fifth + 1] = 0;
      leds[fifth] = CRGB(255,0,0);
      leds[fifth + 1] = CRGB(0,0,0);*/
    //  Serial.println("2: ");
    //  Serial.println(x);
      FastLED.show();
     // Serial.println("3: ");
     // Serial.println(x);
    }
    
  if(mySerial.read()==3){
    if(direct == 1) {
      attack(i-1, x-1);
      Serial.println("right i-1");
      Serial.println(i-1);
      Serial.println("right x-1");
      Serial.println(x-1);
      
    }
    
    if(direct == 0) {
      attack(i, x);
      Serial.println("left i");
      Serial.println(i);
      Serial.println("left x");
      Serial.println(x);
    }
  }
}
}

bool Interval(unsigned long currTime, int interval, long *previousTime)
{
  if(currTime - *previousTime >= interval)
  {
    *previousTime = currTime;
    return true;
  }
  return false;
}
    

  



