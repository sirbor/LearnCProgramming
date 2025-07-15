#include <stdio.h>
/*
* User Registration System
* Takes names, age , height and gender
*/
int main(void)
{
char name[50];
int age;
float height;
char gender;

printf("====User Registration System=====\n");

printf("What is your name? \n");
scanf(" %[^\n]", name);

printf("How old are you? \n");
scanf("%d", &age);

printf("Please state your height in centimeters: \n");
scanf("%f", &height);

printf("Please state sex given at birth M/F?\n");
scanf(" %c", &gender);


printf("====User Details=====\n");
printf("My name is %s\n", name);
printf("I/'m %d years old. \n", age);
printf("My height is %.2f centimeters.\n", height);
printf("My gender is %c by birth.\n", gender);

return(0);


}

