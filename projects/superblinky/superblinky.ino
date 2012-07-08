/* Blinky v2.0
   Jason Wright
*/

const int ledPin = 0;    // LED connected to digital PWM pin 3, 0 on teensy++
const int analogPin = 0; // Potentiometer connected to analog pin 0

int analogVal;
int delayVal;
int fadeVal = 0;
boolean fadeUp = true;

void setup()  { 
  Serial.begin(38400); // initiate serial connection at 38400 baud
} 

void loop()  { 
  analogVal = analogRead(analogPin);
  
  delayVal = map(analogVal, 0, 1024, 1, 5);
  analogWrite(ledPin, fadeVal);           
  delay(delayVal);                            

  if(fadeUp) {
    fadeVal++;
  } else {
    fadeVal--;
  }
  
  if(fadeVal == 255 || fadeVal == 0) {
    fadeUp = !fadeUp;
    Serial.print("analog 0 is: ");
    Serial.println(analogVal);
    delay(1); //for stability
  }
}


