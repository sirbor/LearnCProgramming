#include <stdio.h>

int main() {
  int fahr, celcius;
  int step,lower,upper;
  lower = 0, step = 20, upper = 300;
  fahr = lower;
  while(fahr <= upper) {
    celcius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celcius);
    fahr = fahr + step;
  }
}
