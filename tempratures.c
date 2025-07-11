#include <stdio.h>
/*
*This is a temprature conversion Project
*To show the skills I have learnt
*On Varibles and data types
*/
int main(void)
{
const int lower = 0;
const int upper = 300;
int fahr = lower;
  while(fahr <= upper)
{
const int step = 20;
int celsius = 5 * (fahr - 32) / 9;
printf("%d\t%d\n", fahr, celsius);
fahr += step;
}
  return (0);
}
