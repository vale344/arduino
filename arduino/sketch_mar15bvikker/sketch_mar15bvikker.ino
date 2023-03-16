
//NOTE
// music file skal vare wav 
//libary
#include <Arduino.h>
  //remote
#include <IRremote.hpp>
  //SD
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
//reciver
#define IR_RECEIVE_PIN 7//pin 7
//butten
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_PLAY_PAUSE 64

//pins led
 #define  Gren_pin  2//pin 2
 #define  red_pin  3
 #define  blue_pin  4

 //pins sd
 #define SD_ChipSelectPin 10 //blue ledning

  

  //POWER LOADER
 byte PowernLedState = LOW;// siger om der er power i dinne LEd

 TMRpcm tmrpcm;

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
 //remode
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  //pins
  pinMode(Gren_pin, OUTPUT); 
  pinMode(red_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);

   //SD
  tmrpcm.speakerPin=9;
   if(!SD.begin(SD_ChipSelectPin))
   {
     Serial.println("SD fail");
     return;
   }
    else{   
    Serial.println("SD ok");   
  }
   tmrpcm.setVolume(6);
   //play song når vis have en kan
   // under 2MB
   // og der må kun være bugstaver i navnet
  // tmrpcm.play("test.wav");

}
void loop() {
// put your main code here, to run repeatedly:
  if (IrReceiver.decode())
  {
    int ReceiverVal = IrReceiver.decodedIRData.command;
    Serial.println(ReceiverVal);
// key 0
    if(ReceiverVal==22)
    {
   
    //      Serial.println("0");
    }
// key 1
    int sensorValue=0;
   
    switch(ReceiverVal){
  //key 1
      case IR_BUTTON_1: 
      {
        Serial.println("Pressed on button 1");
       
        Serial.println("on");
        PowernLedState = (PowernLedState == LOW) ? HIGH: LOW;
        digitalWrite(Gren_pin, PowernLedState);
         
        tmrpcm.play("test.wav");

        break;
      }
      //key2
          case IR_BUTTON_2: {
        Serial.println("Pressed on button 2");
            PowernLedState = (PowernLedState == LOW) ? HIGH: LOW;
        digitalWrite(red_pin, PowernLedState);
       // tmrpcm.play("power.wav");
     
        //POWER TO THE PEOPLE
        break;
      }
        //key3
        case IR_BUTTON_3: 
      {
        Serial.println("Pressed on button 3");
         PowernLedState = (PowernLedState == LOW) ? HIGH: LOW;
        digitalWrite(blue_pin, PowernLedState);
       // tmrpcm.play("mulan.wav");
        break;
      }
      //key >||
      case IR_BUTTON_PLAY_PAUSE:
      {
        Serial.println("Pressed on button play/pause");
       // tmrpcm.pause();
        break;
      }
      default: {
        Serial.println("Button not recognized");
      }
 }


 IrReceiver.resume();
 }
delay(200);
}



