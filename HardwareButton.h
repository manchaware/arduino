/*
 * HardwareButton.h
 * 26 March 2016 - Adrian Ortiz
 * Based on Arduino Debounce tutorial https://www.arduino.cc/en/Tutorial/Debounce
 *
 * Will set "events" for up, down, and click. Click is only set if released
 * within BUTTON_CLICK_MAX_DELAY time
 */

#include <Arduino.h>

#ifndef HardwareButton_h
#define HardwareButton_h

#define HARDWARE_BUTTON_DEBOUNCE_DELAY 25
#define HARDWARE_BUTTON_CLICK_MAX_DELAY 250

class HardwareButton {
  public:
    HardwareButton(int buttonPin);
    HardwareButton();

    void getState();

    bool down = false;
    bool up = false;
    bool click = false;

  private:
    int pin;
    int buttonState;
    int lastButtonState = LOW;

    long lastDownTime = 0;
    long lastClickTime = 0;
    long lastDebounceTime = 0;
};

#endif
