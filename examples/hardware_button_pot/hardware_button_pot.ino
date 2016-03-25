/*
 * Hardware buttons and pots example
 * 26 March 2016 - Adrian Ortiz
 */

#include "HardwareButton.h"
#include "HardwarePot.h"

HardwareButton button1 = HardwareButton(2);
HardwarePot pot1 = HardwarePot(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  button1.getState();

  if (button1.down) {
    Serial.println("Button:down");
  }
  if (button1.up) {
    Serial.println("Button:up");
  }
  if (button1.click) { // will only fire if "clicked" within a specified time
    Serial.println("Button:click");
  }

  if (pot1.changed()) {
    Serial.print("Potentiometer:");
    Serial.print(pot1.value);
  }

  delay(5);
}

