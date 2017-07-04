#ifndef VT100_h
#define VT100_h

#include "Arduino.h"

class VT100
{
  public:
	VT100(int baud);
    void SaveCursorPosition();
    void RecallCursorPosition();
    void ClearScreen();
    void MoveCursor(int x, int y);
    void Bold(bool on);
    void Blink(bool on);
    void ClearLine(int y);
	void print(String val);
  private:
  int _baud;
};
#endif

