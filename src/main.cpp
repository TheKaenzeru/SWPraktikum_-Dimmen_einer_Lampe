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

void setup(){
  pinMode(led, OUTPUT);
  pinMode(taster1, INPUT);
  pinMode(taster2,INPUT);
  pinMode(gate, OUTPUT);
}
void loop(){
  if (digitalRead(SND)==HIGH && wait == false){
    counter++;
    wait = true;  
  } else if (digitalRead(SND)== LOW && wait == true){
    wait = false;
  }

  if (counter >= haeufigkeit){
    counter = 0;
    lampe = !lampe;
  }

  if (lampe){
    digitalWrite(gate, HIGH);
  } else {
    digitalWrite(gate,LOW);
  }

}