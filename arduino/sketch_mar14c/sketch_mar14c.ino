// Libraries to include for the code to work 
#include <Arduino.h>
 #include <IRremote.h> 
 // Define which Arduino pins will be connected to components 
 #define IR_RECEIVE_PIN 2 
 //================================================================= 
 // Configure the Arduino and IR receiver
  void setup() { 
    Serial.begin(115200); //115200
  // Prints will be sent to Serial Monitor at 115200 baud
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
   // Start the IR receiver on defined Arduino pin 
   } 
   //================================================================= 
   // The repeating section of the code 
   void loop() { 
     if (IrReceiver.decode())    // If IR receiver has received data
   { int ReceiverValue = IrReceiver.decodedIRData.command; 
   // Move the received value called "command" into a variable 
   Serial.println(ReceiverValue);
    // Print the variable containing the received value in the Serial Monitor 
    IrReceiver.resume(); // Enable receiving of the next value 
    } delay(200); // Wait 200 miliseconds then run loop code again 
    }


 