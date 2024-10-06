#include <Arduino.h>
#include <Keyboard.h>
#include <Joystick.h>

#define KEY_2 'a'
#define KEY_3 'b'
#define KEY_4 'c'
#define KEY_5 'd'
#define KEY_6 'e'
#define KEY_7 'f'
#define KEY_8 'g'
#define KEY_9 'h'
#define KEY_10 'i'
#define KEY_16 'j'
#define KEY_14 'k'
#define KEY_15 'l'
#define KEY_A0 KEY_BACKSPACE
#define KEY_A1 KEY_RETURN

#define STICK true
#define D_PAD false

volatile bool directionMode;

Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_GAMEPAD,
  0,     // Button Count
  0,     // Hat Switch Count
  true,  // X Axis
  true,  // Y Axis
  false, // Z Axis
  false, // Rx Axis
  false, // Ry Axis
  false, // Rz Axis
  false, // Rudder
  false, // Throttle
  false, // Accelerator
  false, // Brake
  false  // Steering
);

#define handleRest \
    // Handle Top Row \
    (digitalRead(6) == LOW) ? Keyboard.press(KEY_6) : Keyboard.release(KEY_6); \
    (digitalRead(7) == LOW) ? Keyboard.press(KEY_7) : Keyboard.release(KEY_7); \
    (digitalRead(8) == LOW) ? Keyboard.press(KEY_8) : Keyboard.release(KEY_8); \
    (digitalRead(9) == LOW) ? Keyboard.press(KEY_9) : Keyboard.release(KEY_9); \
    // Handle Bottom Row \
    (digitalRead(10) == LOW) ? Keyboard.press(KEY_10) : Keyboard.release(KEY_10); \
    (digitalRead(16) == LOW) ? Keyboard.press(KEY_16) : Keyboard.release(KEY_16); \
    (digitalRead(14) == LOW) ? Keyboard.press(KEY_14) : Keyboard.release(KEY_14); \
    (digitalRead(15) == LOW) ? Keyboard.press(KEY_15) : Keyboard.release(KEY_15); \
    // Start / Select \
    (digitalRead(A0) == LOW) ? Keyboard.press(KEY_A0) : Keyboard.release(KEY_A0); \
    (digitalRead(A1) == LOW) ? Keyboard.press(KEY_A1) : Keyboard.release(KEY_A1);

void setup() {
  pinMode(2, INPUT_PULLUP); // Up
  pinMode(3, INPUT_PULLUP); // Down
  pinMode(4, INPUT_PULLUP); // Left
  pinMode(5, INPUT_PULLUP); // Right
  pinMode(6, INPUT_PULLUP); // Top Row 1
  pinMode(7, INPUT_PULLUP); // Top Row 2
  pinMode(8, INPUT_PULLUP); // Top Row 3
  pinMode(9, INPUT_PULLUP); // Top Row 4
  pinMode(10, INPUT_PULLUP); // Bottom Row 1
  pinMode(16, INPUT_PULLUP); // Bottom Row 2
  pinMode(14, INPUT_PULLUP); // Bottom Row 3
  pinMode(15, INPUT_PULLUP); // Bottom Row 4
  pinMode(A0, INPUT_PULLUP); // Start
  pinMode(A1, INPUT_PULLUP); // Select

  delay(50); // Ensure that the pins have settled

  directionMode = (digitalRead(A0) == LOW && digitalRead(A1) == LOW) ? STICK : D_PAD;

  Keyboard.begin();
  Joystick.begin();
}

void stickMode() {
  while (true) {
    // Handle Directions
    Joystick.setXAxis(
      (digitalRead(4) == LOW)
        ? -127
        : (digitalRead(5) == LOW)
          ? 127
          : 0
    );
    Joystick.setYAxis(
      (digitalRead(2) == LOW)
        ? -127
        : (digitalRead(3) == LOW)
          ? 127
          : 0
    );

    handleRest

    delay(10); // Prevent input flooding in the host OS
  }
}

void dpadMode() {
  while (true) {
    // Handle Directions
    (digitalRead(2) == LOW) ? Keyboard.press(KEY_2) : Keyboard.release(KEY_2);
    (digitalRead(3) == LOW) ? Keyboard.press(KEY_3) : Keyboard.release(KEY_3);
    (digitalRead(4) == LOW) ? Keyboard.press(KEY_4) : Keyboard.release(KEY_4);
    (digitalRead(5) == LOW) ? Keyboard.press(KEY_5) : Keyboard.release(KEY_5);

    handleRest

    delay(10); // Prevent input flooding in the host OS
  }
}

void loop() {
  directionMode ? stickMode() : dpadMode();
}