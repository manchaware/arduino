/*
 * HardwareButton.h
 * 26 March 2016 - Adrian Ortiz
 * Based on Arduino Debounce tutorial https://www.arduino.cc/en/Tutorial/Debounce
 *
 * Will set "events" for up, down, and click. Click is only set if released
 * within BUTTON_CLICK_MAX_DELAY time
 */

#include "HardwareButton.h"

HardwareButton::HardwareButton(int buttonPin) {
  pin = buttonPin;
  pinMode(pin, INPUT);
}

HardwareButton::HardwareButton() {
}

void HardwareButton::getState() {
  int reading = digitalRead(pin);

  click = down = up = false;

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > BUTTON_DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;

      down = (buttonState == HIGH);
      up = !down;

      if (down) {
        lastDownTime = millis();
      }

      if (up && ((millis() - lastDownTime) < BUTTON_CLICK_MAX_DELAY)) {
        click = true;
      }
    }
  }

  lastButtonState = reading;
}
