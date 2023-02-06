#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Servo.h>
Servo servox;
Servo servoy;

const uint64_t pipeIn = 0xE8E8F0F0E1LL; 

RF24 radio(9, 10);


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
  
  servox.attach(6);
  servoy.attach(5);
  
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

/*
    if (data.Y < 80) { //Reverse
      servoy.write(90);
    }

    if (data.Y > 145) {//forward
      servoy.write(180);
    }

    if (data.X > 155) {//right 
      servox.write(180);
    }

    if (data.X < 80) {//left 
      servox.write(90);
    }

    if (data.X > 100 && data.X < 170 && data.Y > 80 && data.Y < 130) { //stop 
      servox.write(0);
      servoy.write(0);
    }
*/

    if (data.value < 80) { //Reverse
      servoy.write(90);
    }

    if (data.value > 145) {//forward
      servoy.write(180);
    }

    if (data.value1 > 155) {//right 
      servox.write(180);
    }

    if (data.value1 < 80) {//left 
      servox.write(90);
    }

    if (data.value > 100 && data.value < 170 && data.value1 > 80 && data.value1 < 130) { //stop
      servox.write(0);
      servoy.write(0);
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
