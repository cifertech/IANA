#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <LedControl.h>

const uint64_t pipeIn = 0xE8E8F0F0E1LL; 

RF24 radio(9, 10);

int DIN = 7; 
int CS =  6;
int CLK = 5; 

LedControl lc=LedControl(DIN,CLK,CS,0);

struct MyData {
  byte X; 
  byte Y;
  int value;
  int value1;
};

MyData data;

void setup()
{
  Serial.begin(9600); 

  lc.shutdown(0,false);      
  lc.setIntensity(0,15);     
  lc.clearDisplay(0);       

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, pipeIn);
  radio.startListening();

}

void recvData()
{
  if ( radio.available() ) {
    radio.read(&data, sizeof(MyData));


    if (data.Y < 80) { //Reverse   
    byte a[8] = {0x18,0x3C,0x7E,0xFF,0x3C,0x3C,0x3C,0x3C};
    printByte(a);
    }

    if (data.Y > 145) {//forward
    byte a[8] = {0x3C,0x3C,0x3C,0x3C,0xFF,0x7E,0x3C,0x18};
    printByte(a);
    }

    if (data.X > 155) {//right
    byte a[8] = {0x10,0x30,0x7F,0xFF,0xFF,0x7F,0x30,0x10};
    printByte(a);
    }

    if (data.X < 80) {//left
    byte a[8] = {0x08,0x0C,0xFE,0xFF,0xFF,0xFE,0x0C,0x08};
    printByte(a);
    }

    if (data.X > 100 && data.X < 170 && data.Y > 80 && data.Y < 130) { //stop
    byte a[8] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};
    printByte(a);
    }
  }
}

void loop()
{
  recvData();
  Serial.print("X= ");
  Serial.print(data.X);
  Serial.print("    ");
  Serial.print("Y= ");
  Serial.print(data.Y);
  Serial.print("    ");
  Serial.print("P1=  ");
  Serial.print(data.value);
  Serial.print("    ");
  Serial.print("P2=  ");
  Serial.print(data.value1);
  Serial.print("\n");
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
