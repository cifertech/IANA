#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"    

const int potPin = A2; 
const int potPin1 = A3;


MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

int16_t value; 
int16_t value1; 

const uint64_t pipeOut = 0xE8E8F0F0E1LL; 

RF24 radio(9, 10); // CN and CSN 

struct MyData {
  byte X;
  byte Y;
  int value=0;
  int value1=0;
};

MyData data;

void setup()
{
  Serial.begin(9600);
  
  pinMode(potPin, INPUT); 
  pinMode(potPin1, INPUT);
  
  Wire.begin();
  mpu.initialize();

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pipeOut);
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  data.X = map(ax, -17000, 17000, 0, 255 ); 
  data.Y = map(ay, -17000, 17000, 0, 255);  

  value = analogRead(potPin);          
  data.value = map(value, 0, 1023, 0, 255); 
  
  value1 = analogRead(potPin1);          
  data.value1 = map(value1, 0, 1023, 0, 255);

  delay(50);
  radio.write(&data, sizeof(MyData));

  Serial.print("Axis X = ");
  Serial.print(data.X);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.println(data.Y);

  Serial.print("P1 =  ");
  Serial.print(data.value);
  Serial.print("P2 =  ");
  Serial.println(data.value1);
}
