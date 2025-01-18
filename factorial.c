#include <stdio.h>

int factorial(int num) {
  if(num < 0) {
    printf("Factorial of a negative integer is not precedented\n");
    return -1;
  } if(num == 0 || num == 1) {
    return 1;
  }
  int result = 1;
  for(int i = 2; i <= num; i++){
    result *= i;
  }
  return result;
}

int main() {
  int n;
  printf("PLease enter a non - negative integer\n");
  scanf("%d", &n);

  int fact = factorial(n);
  if(fact != -1) {
    printf("Factorial of %d is %d\n", n , fact);
  }
  return 0;
}
