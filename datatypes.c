#include <stdio.h>
/*
* This file is part of the C Programming Language course.
* It is used to demonstrate the use of various data types in C.
* Variables are containers used for data storing values
* like numbers or characters
* int - for stroing numbers without decimals
* float -for storing floating point numbers 
* char -for storing single characters
* syntax -typeVariable name = value;
*/
int main(void)
{
int age = 25;
float taxRate = 7.8;
char score = 'A';
printf("%d\n",age);
printf("%.4lf\n",taxRate);
printf("%c\n",score);
return (0);
}
