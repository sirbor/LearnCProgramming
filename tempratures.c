#include <stdio.h> //input and output header files

int main(void) {
  
  int lower,upper,step;
  int fahr,celcius;
  lower = 0, upper = 300, step = 20;

  fahr = lower;
  printf("Fahr\tCelcius\n");
  while(fahr <= upper) {
    celcius = 5 * (fahr - 32) /9;
    printf("%d\t%d\n", fahr , celcius);
    fahr += step;
  }
  return 0;
}
