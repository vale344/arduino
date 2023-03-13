// sort =GND
// red =power
//orange= IRSensor

int IRSensor = 7; // connect IR sensor module to Arduino pin D9
int LED = 2; // connect LED to Arduino pin 13
int Red= 1;

void setup(){
  Serial.begin(115200); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output
  pinMode(Red, OUTPUT); // LED Pin Output
}

void loop(){
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  if (sensorStatus == 1) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led
    digitalWrite(LED, LOW); // LED LOW
    Serial.println("Motion Detected!"); // print Motion Detected! on the serial monitor window
   digitalWrite(LED, HIGH); // LED High
  }
  else  {
    //else turn on the onboard LED
    digitalWrite(Red, LOW); // LED High
    Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
  }
}