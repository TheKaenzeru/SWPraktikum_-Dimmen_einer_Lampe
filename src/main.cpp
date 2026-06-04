#include <Arduino.h>

int taster1 = 0;
int taster2 = 1;
int led = 14;
int gate = 3;
int SND = 6; // Spannungsnull Durchgang
int haeufigkeit = 50;
int SNI = 9; // Spannungnull Interrupt

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

volatile bool NDG = false; // Null Durchgang

void trigger(){
  NDG = true;
}


void setup(){
  pinMode(led, OUTPUT);
  pinMode(taster1, INPUT);
  pinMode(taster2,INPUT);
  pinMode(gate, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SNI), trigger, RISING);

}
void loop(){
  if (NDG == true){
    NDG = false;
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