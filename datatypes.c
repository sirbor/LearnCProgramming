#include <stdio.h>
/*
*Data types in c include the following
*Integers - whole numbers which can be either positive or negative.
*Defined using char, int, short, long or long long.
*Unsigned integers - whole numbers which can only be positive.
*Defined using unsigned char, unsigned int, unsigned short, unsigned long or unsigned long long.
*Floating point numbers - real numbers (numbers with fractions). Defined using float and double.
*/
int main(void)
{
char c = 'A';
int i = 42;
short s = 30000;
long l = 1234567890;
long long ll = 1234567890123456789;
unsigned char uc = 255;
unsigned int ui = 4294967295;
unsigned short us = 65535;
unsigned long ul = 18446744073709551615U;
unsigned long long ull = 18446744073709551615ULL;
float f = 3.14f;
double d = 3.141592653589793;
printf("Integer: %d, Unsigned Integer: %u, Float: %.2f, Double: %.15f\n", i, ui, f, d);
return (0);
}
