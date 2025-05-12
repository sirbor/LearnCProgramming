#include <stdio.h>

#define MAX_USERS 100
#define PI 3.14159

int main(void) {

  //Variables
  
  int age = 25;
  float height = 5.6;
  double salary = 40000.69;
  char grade = 'Q';

  //Constants

  const int MAX_AGE = 100;
  const float MIN_HEIGHT = 1.0;

  //Literals
  char newLine = '\n';
  int num1 = 25;
  float pi = 3.14159;
  char greeting[] = "Hello, World";

  //Print Variables
  printf("The age is %d: \n", age);
  printf("The height is %f: \n", height);
  printf("The salary is %lf: \n", salary);
  printf("You were graded at group %c: \n", grade);

  //Print Constants
  printf("The maximum age is %d: \n", MAX_AGE);
  printf("The minimum is %f \n", MIN_HEIGHT);

  //Print Literals
  printf("Newline .... %c \n", newLine);
  printf("The number is %d \n", num1);
  printf("Pi is %f \n", pi);
  printf("Greeting: %s", greeting);

  return 0;
}
