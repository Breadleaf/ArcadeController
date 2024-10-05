#include <Arduino.h>
#include <Keyboard.h>

#define NUM_BUTTONS 14

const int buttonPins[NUM_BUTTONS] = {
  2,  3,  4,  5,
  6,  7,  8,  9,
  10, 16, 14, 15,
  A0, A1
};

const char keyMap[NUM_BUTTONS] = {
  'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h',
  'i', 'j', 'j', 'l',
  'm', 'n'
};

void setup() {
  for (int idx = 0; idx < NUM_BUTTONS; idx++) {
    pinMode(buttonPins[idx], INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {
  for (int idx = 0; idx < NUM_BUTTONS; idx++) {
    if (digitalRead(buttonPins[idx]) == LOW) {
      Keyboard.press(keyMap[idx]);
    } else {
      Keyboard.release(keyMap[idx]);
    }
  }

  delay(5); // 5ms of debounce time
}