#include<Servo.h>
Servo servo1;
Servo servo2;
int hpos=0;
int vpos=0;
 
const int trigger=7;
const int echopin=11;
float distance;
unsigned long int pulse;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echopin,INPUT);
  servo1.attach(9);
  servo2.attach(8);
  servo1.write(0);
  servo2.write(180);
}

void sonar()
{
    digitalWrite(trigger,LOW);
    delay(2);
    digitalWrite(trigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);

    pulse=pulseIn(echopin,HIGH);
    distance=(pulse/2000000.0)*(343); //In metres
    distance=100*distance;
}

void loop() 
{
  for (hpos = 0; hpos <= 180; hpos += 1)
  { 
    servo1.write(hpos);               
    delay(5);
    sonar();
    Serial.print(distance);
    Serial.print(" ");
    Serial.print(hpos);
    Serial.print(" ");
    Serial.println(vpos);
    delay(10);                     
  }
  vpos++;
  servo2.write(180-vpos);
  if(vpos==90)
  exit(0);
  for (hpos = 180; hpos >= 0; hpos -= 1) 
  { 
    servo1.write(hpos);              
    delay(5);
    sonar();
    Serial.print(distance);
    Serial.print(" ");
    Serial.print(hpos);
    Serial.print(" ");
    Serial.println(vpos);
    delay(10);
  }
  vpos++;
  servo2.write(180-vpos);
  if(vpos==90)
  exit(0);
}
