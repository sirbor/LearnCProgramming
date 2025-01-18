#include <stdio.h>

int main() {
  int c , nc;
  nc = 0;
  while((c = getchar()) != EOF) 
    if(c == '\n')
      ++nc;
  printf("%d\n", nc);
}

