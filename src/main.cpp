#include <Arduino.h>

int taster1 = 0;
int taster2 = 1;
int led = 14;
int gate = 3;
int SND = 6;
int haeufigkeit = 50;

bool lampe = false;
int counter = 0;
bool wait= false;
int alpha = 90;
int alphazeit = alpha*10000/180;
int step = 18;
int zuendwinkelmin = 0;
int zuendwinkelmax = 180;
int singrenzeUp = zuendwinkelmax*10000/180;
int singrenzeDown = zuendwinkelmin*10000/180;



void setup(){
  pinMode(led, OUTPUT);
  pinMode(taster1, INPUT);
  pinMode(taster2,INPUT);
  pinMode(gate, OUTPUT);
}
void loop(){
  if (digitalRead(SND)==HIGH && wait == false){
    counter++;
    delayMicroseconds(alpha);
    digitalWrite(gate,HIGH);
    delayMicroseconds(10);
    digitalWrite(gate,LOW);
    wait = true;  
  } else if (digitalRead(SND)== LOW && wait == true){
    wait = false;
  }
  if (digitalRead(taster1)==HIGH && alphazeit+step <= singrenzeUp){
    alpha += step;
    delay(200);
  } else if (digitalRead(taster2) == HIGH && alphazeit-step >= singrenzeDown){
    alpha -= step;
    delay(200);
  }

}