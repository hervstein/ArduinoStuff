/*Tomas de Camino Beck
www.funcostarica.org

*/
#include <Adafruit_CircuitPlayground.h>
#define MIN 500
#define MAX 1005
#define ALARM 700

void setup() {
  // put your setup code here, to run once:
  pinMode(A9,INPUT);
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A9);
  if(val>ALARM)CircuitPlayground.playTone(880,100);
  Serial.println(val);
  pixelMeter(val,MIN,MAX);
}

void pixelMeter(float value, float minimum, float maximum){
  int p = map(value,minimum,maximum,0,9);
  CircuitPlayground.clearPixels();
  for(int i=0;i<=p;i++){
    int c=map(i,0,9,0,255);
    CircuitPlayground.setPixelColor(i, CircuitPlayground.strip.Color(255,0,0));
  }
}
