#include <stdio.h>

int main() {
  int x = 5;
  int y = x++;
  printf("X is %d\n", x);
  printf("Y is %d\n", y);
  return 0;
}
