#include <cstdint>
#include <cstdio>
#include <cmath>

#include "pico/stdlib.h"

double freq = 1;
double sec = 0;
double amp = 0.49;

double genSine(double sec, double amp, double freq) {
  return amp * (sin(2.0 * M_PI * freq * sec / 1000) + 1.0);
}

int main() {
  stdio_init_all();

  while (true) {
    for (int i = 0; i < 15; i++) {
      printf("%f,", genSine(sec, amp, freq * (i+1)));
    }
    printf("%f\n", genSine(sec, amp, freq * 16));
    sleep_ms(10);
    sec += 10;
  }

  return 0;
}
