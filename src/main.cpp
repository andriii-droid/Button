#include <Arduino.h>
#include <Button.h>

Button b1{15};

void setup() {
  Serial.begin(9600);
  Serial.println("Setup Complete");

  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);


  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() 
{
  b1.updateButton();

  if(b1.getState(b1.click) || b1.getState(b1.time) || b1.getState(b1.twice))
  {
    digitalWrite(17, !digitalRead(17));
    Serial.println(b1.getState(b1.click));
    Serial.println(b1.getState(b1.time));
    Serial.println(b1.getState(b1.twice));
  }

}