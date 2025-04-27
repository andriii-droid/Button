#include <Arduino.h>
#include <Button.h>

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

void loop() {

}