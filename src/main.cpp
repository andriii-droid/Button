#include <Arduino.h>
#include <Button.h>



Button b1 {15, b1.positive};
Button b2 {15, b2.positive};

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
  b1.updateButton();
  // b2.updateButton();
  // delay(5);

  // digitalWrite(16, b1.getState());
  // digitalWrite(17, b2.getState());

  // if (b1.getState())
  // {
  //   Serial.println("TrigPos");
  // }
  
}