#include <Arduino.h>

int taster1 = 0;
int taster2 = 1;
int led = 14;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(taster1, INPUT);
  pinMode(taster2,INPUT);
}
void loop(){
  if (digitalRead(taster1) == HIGH){
    digitalWrite(led, HIGH);
  }
  else if (digitalRead(taster2) == HIGH){
    digitalWrite(led, LOW);
  }
delay(100);
}