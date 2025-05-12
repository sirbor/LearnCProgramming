#include <stdio.h>

int main(void) {
  int roll_no;
  char name[50];
  scanf("Enter Roll No.: %d", &roll_no); 
  scanf("Enter Name: %s", name); 
  printf("Hello %s your roll no is %d", name , roll_no);
return 0;
}
