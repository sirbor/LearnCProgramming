#include <stdio.h>

int main(void) {
  int upper,lower, step;
  int fahr, celsius;

  upper = 300;
  lower = 0;
  step = 20;

  fahr = lower;
  printf("Fahr\tCelsius\n");
  while(fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}
