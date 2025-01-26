#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
  int nl,nw,nc,c,state;
  nl=nc=nw=0;
  state = OUT;

  while((c = getchar()) != EOF) {
    ++nc;
    if(c == '\n') 
      ++nl;
    if(c = ' ' || c = '\n' || c = '\t') 
        state = OUT;
        else if (state == OUT) {
          state = IN;
          ++nw;
        }
  }
  printf("%d %d %d\n", nl, nw , nc);
}
