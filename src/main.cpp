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
int alpha = 5000;
int singrenzeUp = 10000;
int singrenzeDown = 0;
int step = 500;

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
  if (digitalRead(taster1)==HIGH && alpha+step <= singrenzeUp){
    alpha += step;
    delay(200);
  } else if (digitalRead(taster2) == HIGH && alpha-step >= singrenzeDown){
    alpha -= step;
    delay(200);
  }

}