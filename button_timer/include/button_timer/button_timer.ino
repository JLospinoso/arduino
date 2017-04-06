#include "Clock.h"
#include "Program.h"

Program prog;

void setup() {
}

void loop() {
  prog.step();
  delay(1000);
}


