#include <stdio.h>

int main() {
  int age = 25;
  float rate = 16.5;
  double Pi = 3.141956;
  char grade = 'B';

  int scores[5] = {12, 14, 16 , 13, 10};

  struct Point {
    int x;
    int y;
  };

  struct Point P1 = {20 , 30};

  printf("The age is %d :\n", age);
  printf("The interst rate is %.3lf : \n", rate);
  printf("Pi is %.4lf\n", Pi);
  printf("The grade is %c\n", grade);

  printf("The scores are %d, %d, %d, %d, %d\n", scores[0],scores[1],scores[2],scores[3],scores[4]);
  printf("The points are %d,%d\n", P1.x,P1.y);
  return 0;


}
