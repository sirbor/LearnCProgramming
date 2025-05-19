#include <stdio.h> //input and output header files

int main(void) {
  int upper,lower,step;
  int celsius,fahr;

  upper = 300;
  lower = 0;
  step = 20;

fahr = lower;
  printf("Celcius\tFahrnehit\n");
  while(fahr <= upper) {
    celsius = 5 * (fahr - 32)/9;
    printf("%d\t%d\n", celsius, fahr);
    fahr += step;
  }
  return 0;
}
