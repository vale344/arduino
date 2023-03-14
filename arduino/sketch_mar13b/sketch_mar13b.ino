// sort =GND
// red =power
//orange= IRSensor
#include <IRremote.hpp>



int IRSensor = 7; // connect IR sensor module to Arduino pin D9
IRrecv IR(IRSensor);
int LED = 2; // connect LED to Arduino pin 13
int Red= 3;
decode_results results;
unsigned long key_value = 0;

void setup(){
  //
  Serial.begin(9600); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output
  pinMode(Red, OUTPUT); // LED Pin Output
  IR.enableIRIn();
}

void loop(){
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  if (sensorStatus == 1) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led
    digitalWrite(Red, LOW); // LED LOW
    Serial.println("Motion Detected!"); // print Motion Detected! on the serial monitor window
   digitalWrite(LED, HIGH); // LED High
  }
  else  {
    //else turn on the onboard LED
    digitalWrite(Red, HIGH); // LED High
    Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
  }

  while (IR.decode(&results)==0){

  }
  //if (IR.decode(&results)){
  //  Serial.println(results.value, HEX);
//delay(100);
//IR.resume();
 if (IR.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
          Serial.println("CH-");
          break;
          case 0xFF629D:
          Serial.println("CH");
          break;
          case 0xFFE21D:
          Serial.println("CH+");
          break;
          case 0xFF22DD:
          Serial.println("|<<");
          break;
          case 0xFF02FD:
          Serial.println(">>|");
          break ;  
          case 0xFFC23D:
          Serial.println(">|");
          break ;               
          case 0xFFE01F:
          Serial.println("-");
          break ;  
          case 0xFFA857:
          Serial.println("+");
          break ;  
          case 0xFF906F:
          Serial.println("EQ");
          break ;  
          case 0xFF6897:
          Serial.println("0");
          break ;  
          case 0xFF9867:
          Serial.println("100+");
          break ;
          case 0xFFB04F:
          Serial.println("200+");
          break ;
          case 0xFF30CF:
          Serial.println("1");
          break ;
          case 0xFF18E7:
          Serial.println("2");
          break ;
          case 0xFF7A85:
          Serial.println("3");
          break ;
          case 0xFF10EF:
          Serial.println("4");
          break ;
          case 0xFF38C7:
          Serial.println("5");
          break ;
          case 0xFF5AA5:
          Serial.println("6");
          break ;
          case 0xFF42BD:
          Serial.println("7");
          break ;
          case 0xFF4AB5:
          Serial.println("8");
          break ;
          case 0xFF52AD:
          Serial.println("9");
          break ;      
        }
        key_value = results.value;
        IR.resume(); 
  }
}
    