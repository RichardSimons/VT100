#include "Arduino.h"
#include "VT100.h"

VT100::VT100(int baud){
	_baud = baud;
	Serial.begin(_baud);
}

void VT100::print(String val){
	Serial.print(val);
}

void VT100::SaveCursorPosition() {
  Serial.print("\x1B[7");
}

void VT100::RecallCursorPosition() {
  Serial.print("\x1B[8");
}

void VT100::ClearScreen() {
  // Esc[2J
  Serial.print("\x1B[2J");
}

void VT100::MoveCursor(int x, int y) {
  Serial.print("\x1B[");
  Serial.print(y);
  Serial.print(";");
  Serial.print(x);
  Serial.print("f");
}

void VT100::Bold(bool on) {
  if (on == 1)
  {
    Serial.print("\x1B[1m");
  }
  else
  {
    Serial.print("\x1B[0m");
  }
}

void VT100::Blink(bool on) {
  if (on)
  {
    Serial.print("\x1B[5m");
  }
  else
  {
    Serial.print("\x1B[0m");
  }
}

void VT100::ClearLine(int y) {
  MoveCursor(1, y);
  Serial.print("\x1B[2K");
}

