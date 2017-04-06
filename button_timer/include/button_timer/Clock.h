#pragma once
//works?

struct Clock {
  Clock()
    : counter{} {
  }

  void reset() {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  void increment() {
    if (++counter > 7) counter = 0;
    set_lights();
  }
private:
  void set_lights() {
    reset();
    if (0b001 & counter) digitalWrite(3, HIGH);
    if (0b010 & counter) digitalWrite(4, HIGH);
    if (0b100 & counter) digitalWrite(5, HIGH);
  }
  size_t counter;
};


