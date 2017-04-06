#include "ArduinoShim.h"
#include "button_timer\Clock.h"
#include "button_timer\Program.h"

int main() {
  Program prog;
  manuallySet(2, HIGH);
  while(true) {
    prog.step();
    delay(1000);
  }
}