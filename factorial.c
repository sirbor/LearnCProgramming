#include <stdio.h>

int factorial(int num) {
  if (num < 0) {
    printf("Factorial of 0 is 1\n");
    return -1;
  } if(num == 0 || num ==1) {
    return 1;
  } 
  int result = 1;
  for(int i = 2; i <= num; i++) {
    result *= i;
  }
  return result;
}

int main(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  int fact= factorial(n);
  if(fact != -1) {
    printf("The factorial of %d is %d", n, fact);
  }
  return 0;
}
