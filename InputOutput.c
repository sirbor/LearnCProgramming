#include <stdio.h>

int main(void) {
  
  int num;
  float rate;
  char grade;

  printf("Please enter an integer: \n");
  scanf("%d", &num);
  printf("Please enter the rates: \n");
  scanf("%f", &rate);
  printf("Please enter the credit score: \n");
  scanf(" %c", &grade);

  printf("You entered the following %d , %.4f and %c. \n", num, rate, grade);

  return 0;
}
