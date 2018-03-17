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
  leds[x-2]=CRGB(174,200,238);
  leds[x+2]=CRGB(174,200,238);
  leds[x+1]=CRGB(174,200,238);
  leds[x-1]=CRGB(174,200,238);
  FastLED.show();
  if(leds[x+1]==CRGB(255,0,0)||leds[x-1]==CRGB(255,0,0)||leds[x-2]==CRGB(255,0,0)||leds[x+2]==CRGB(255,0,0)){//
    leds[x+1]=CRGB(0,0,0);                   //
    leds[x-1]=CRGB(0,0,0);
    leds[x-2]=CRGB(0,0,0);
    leds[x+2]=CRGB(0,0,0);
    leds[x-1]==CRGB(174,200,238);
    leds[x-1]==CRGB(174,200,238);      // CHECKS FOR AN ENEMY AND 
    leds[x-1]=CRGB(174,200,238);              //  REMOVES IT.
    leds[x+1]=CRGB(174,200,238);   
    FastLED.show();
  }
  //delay(300);
  leds[x+2]=CRGB(0,0,0);
  leds[x-2]=CRGB(0,0,0);
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
int numEnemies=0;
int maxEnemies=6;
int j;
int startTime;
int SpawnLocation;
int mobLocations;
int steps=0;
int razmqna;
int mob[6];
int dead[80];
int spawnMob(int x){
  
  if(numEnemies<maxEnemies&&millis()>numEnemies*random(2000,6000)){
    Serial.print("Spawn!");
    leds[79]=CRGB(255,0,0);
    FastLED.show();
    mob[numEnemies]=79;
    numEnemies++;
  }
  if(millis()>steps*1000){
    for(j=0;j<numEnemies;j++){
        leds[mob[j]]=CRGB(0,0,0);
        if(leds[mob[j]-1]==CRGB(0,255,0)){
          endGame(255,0,0);
        }
        if(leds[mob[j]-1]==CRGB(174,200,238)){    //CHECK IF THE PLAYER IS SHOOTING.
          Serial.println("YOU ARE HITTING ME");
          leds[mob[j]-1]==CRGB(0,0,0);
        }
        else{
        leds[mob[j]-1]=CRGB(255,0,0);
        }
        FastLED.show();
        mob[j]--;
    }
    steps++;
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
    Serial.println("move right");
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
    Serial.println("move left");
   if(i == 0){   
    i =  1;
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
  leds[x-2]=CRGB(174,200,238);
  leds[x+2]=CRGB(174,200,238);
  leds[x+1]=CRGB(174,200,238);
  leds[x-1]=CRGB(174,200,238);
  FastLED.show();
  if(leds[x+1]==CRGB(255,0,0)||leds[x-1]==CRGB(255,0,0)||leds[x-2]==CRGB(255,0,0)||leds[x+2]==CRGB(255,0,0)){//
    leds[x+1]=CRGB(0,0,0);                   //
    leds[x-1]=CRGB(0,0,0);
    leds[x-2]=CRGB(0,0,0);
    leds[x+2]=CRGB(0,0,0);
    leds[x-1]==CRGB(174,200,238);
    leds[x-1]==CRGB(174,200,238);      // CHECKS FOR AN ENEMY AND 
    leds[x-1]=CRGB(174,200,238);              //  REMOVES IT.
    leds[x+1]=CRGB(174,200,238);   
    FastLED.show();
  }
  //delay(300);
  leds[x+2]=CRGB(0,0,0);
  leds[x-2]=CRGB(0,0,0);
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
int numEnemies=0;
int maxEnemies=6;
int j;
int startTime;
int SpawnLocation;
int mobLocations;
int steps=0;
int razmqna;
int mob[6];
int dead[80];
int spawnMob(int x){
  
  if(numEnemies<maxEnemies&&millis()>numEnemies*random(2000,6000)){
    Serial.print("Spawn!");
    leds[79]=CRGB(255,0,0);
    FastLED.show();
    mob[numEnemies]=79;
    numEnemies++;
  }
  if(millis()>steps*1000){
    for(j=0;j<numEnemies;j++){
        leds[mob[j]]=CRGB(0,0,0);
        if(leds[mob[j]-1]==CRGB(0,255,0)){
          endGame(255,0,0);
        }
        if(leds[mob[j]-1]==CRGB(174,200,238)){    //CHECK IF THE PLAYER IS SHOOTING.
          Serial.println("YOU ARE HITTING ME");
          leds[mob[j]-1]==CRGB(0,0,0);
        }
        else{
        leds[mob[j]-1]=CRGB(255,0,0);
        }
        FastLED.show();
        mob[j]--;
    }
    steps++;
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
    Serial.println("move right");
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
    Serial.println("move left");
   if(i == 0){   
    i =  1;
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



