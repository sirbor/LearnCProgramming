
## This program demonstrates variables in C
- Variables are named storage locations in mmeory that holds a value.

### Declaration of Variables:
- Syntax - type variableName = value;

** Example : **

`
int age = 25;

`

### Basic Data types in C;
1. int - 2 or 4 bytes - stores whole numbers without decimals eg 1
2. flaot - 4 bytes - stores fractional numbers containing 1 or more decimals storing 6-7 decimal digits eg 1.99
3. double - 8 bytes - stores fractional numbers containing 1 or more decimals storing 15 decimal digits eg 1.99999999
4. char - 1 byte - stores a single character/letter/number or ASCII values eg 'A' , '1' , 'a'

- integers - whole numbers can be positive or negative. defined using char,short,int, long or long long.
- unsigned integers - whole numbers can only be positive. defined using unsigned char, unsigned int, unsigned short, unsigned long, unsigned long long.
- Floating point numbers - real numbers with decimals (float and double)
- Structues - user defined data types that can hold multiple values of different data types.

### Initializing varibales:

`

int age = 25;
flaot height = 5.8;
duble salary 40000.96;
char grade = 'A';

`
** using variables: **

`

age = 30; changes age to 30
height = 6.0; changes height to 6.0
grade = 'B'; changes grade to B 
salary = 45000.00; changes saler to 45,000

`
### Constants:
- Constants are fixed values that do not change during the execution of a program.
- Constants are declared using the keyword const.
** Example: **
 `
 const int MAX_AGE = 100;
 const float PI = 3.14;
 const char GRADE = 'A';
 
`
- Constants are used to define fixed values that are used in the program.

### Escape Sequences:
- Escape sequences are used to represent special characters in strings.
- Escape sequences are preceded by a backslash (\).
** Example: **
- \n - new line
- \t - tab
- \\ - backslash
- \" - double quote
- \' - single quote
- \b - backspace
- \f - form feed
- \v - vertical tab
- \0 - null character
- Escape sequences are used to format strings and display special characters.

### Format Specifiers:
- Format specifiers are used to format the output of variables.
- Format specifiers are preceded by a percentage sign (%).
** Example: **
- %d - integer
- %f - float
- %lf - double
- %c - character
- %s - string
- %d is used to print integers
- %f is used to print float
- %lf is used to print double

### Decimal Precision:
- Decimal precision is used to control the number of decimal places displayed in float and double values.
** Example: ** 
`
printf("%.2f", height); // prints height with 2 decimal places
printf("%.3lf", salary); // prints salary with 3 decimal places

`






