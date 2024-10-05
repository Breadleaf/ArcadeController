// I removed all loops and arrays because `arr[0] == *(arr + 0)` to
// dereference which is slower than just hard coding everything.

#include <Arduino.h>
#include <Keyboard.h>

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
#define KEY_A0 'm'
#define KEY_A1 'n'

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  (digitalRead(2) == LOW) ? Keyboard.press(KEY_2) : Keyboard.release(KEY_2);
  (digitalRead(3) == LOW) ? Keyboard.press(KEY_3) : Keyboard.release(KEY_3);
  (digitalRead(4) == LOW) ? Keyboard.press(KEY_4) : Keyboard.release(KEY_4);
  (digitalRead(5) == LOW) ? Keyboard.press(KEY_5) : Keyboard.release(KEY_5);
  (digitalRead(6) == LOW) ? Keyboard.press(KEY_6) : Keyboard.release(KEY_6);
  (digitalRead(7) == LOW) ? Keyboard.press(KEY_7) : Keyboard.release(KEY_7);
  (digitalRead(8) == LOW) ? Keyboard.press(KEY_8) : Keyboard.release(KEY_8);
  (digitalRead(9) == LOW) ? Keyboard.press(KEY_9) : Keyboard.release(KEY_9);
  (digitalRead(10) == LOW) ? Keyboard.press(KEY_10) : Keyboard.release(KEY_10);
  (digitalRead(16) == LOW) ? Keyboard.press(KEY_16) : Keyboard.release(KEY_16);
  (digitalRead(14) == LOW) ? Keyboard.press(KEY_14) : Keyboard.release(KEY_14);
  (digitalRead(15) == LOW) ? Keyboard.press(KEY_15) : Keyboard.release(KEY_15);
  (digitalRead(A0) == LOW) ? Keyboard.press(KEY_A0) : Keyboard.release(KEY_A0);
  (digitalRead(A1) == LOW) ? Keyboard.press(KEY_A1) : Keyboard.release(KEY_A1);
}