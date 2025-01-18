#include <stdio.h>

int main() {
  int num,count,sum =0;
  printf("Please enter an intger value: ");
  scanf("%d", &num);
  for(count = 1; count <= num; num++) {
    sum += count;
  }
  printf("Sum = %d\n", sum);
  return 0;
}
