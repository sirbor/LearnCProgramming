### Input and Output Operator:
- Input and Output operators are used to read and write data in C. 
- The standard input and output functions are defined in the `stdio.h` header file.
- The most commonly used input and output functions are:
  - `printf()`: Used to print formatted output to the console.
  - `scanf()`: Used to read formatted input from the console.
  - `getchar()`: Used to read a single character from the standard input.
  - `putchar()`: Used to write a single character to the standard output.
  - `gets()`: Used to read a string from the standard input (deprecated).
  - `puts()`: Used to write a string to the standard output.

### Example of Input and Output in C:
```c
#include <stdio.h>
int main() {
    int num;
    char str[100];

    // Input
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Enter a string: ");
    scanf("%s", str);

    // Output
    printf("You entered: %d\n", num);
    printf("You entered: %s\n", str);

    return 0;
}
```
### Explanation:

- The `#include <stdio.h>` directive includes the standard input and output library.
- The `main()` function is the entry point of the program.
- The `printf()` function is used to print messages to the console.
- The `scanf()` function is used to read input from the user.
- The `%d` format specifier is used to read and print integers.
- The `%s` format specifier is used to read and print strings.
- The `&` operator is used to get the address of the variable where the input will be stored.
- The `return 0;` statement indicates that the program has executed successfully.
- The `int` data type is used to declare integer variables.
- The `char` data type is used to declare character arrays (strings).
- The `str` array is used to store the string input.
- The `%c` format specifier is used to read and print any character
- The ` %c` formart specifier witha space before `%c` tells `scanf` to skip **any leading whitespace**, including:
1. Spaces
2. tabs
3. Newlines
- It waits for actual character input instead of consuming leftover whitespace.

### Multiple Input:
- You can read multiple inputs in a single `scanf()` statement by separating the format specifiers with spaces.

```c
#include <stdio.h>
int main() {
    int num1, num2;
    char str[100];

    // Input
    printf("Enter two integers and a string: ");
    scanf("%d %d %s", &num1, &num2, str);

    // Output
    printf("You entered: %d, %d, %s\n", num1, num2, str);

    return 0;
}

```
### Explanation:
- The `scanf()` function reads two integers and a string in a single line.
- The format specifiers `%d %d %s` are used to read two integers and a string, respectively.
- The values are stored in the variables `num1`, `num2`, and `str`.
### Output Formatting:
- The `printf()` function can be used to format the output using format specifiers.
- The format specifiers include:
  - `%d`: Integer
  - `%f`: Float
  - `%c`: Character
  - `%s`: String
  - `%lf`: Double
  - `%x`: Hexadecimal integer
  - `%o`: Octal integer
  - `%p`: Pointer address
- You can also specify the width and precision of the output using the format specifiers.
```c
#include <stdio.h>
int main() {
    float num = 123.456789;

    // Output with different format specifiers
    printf("Integer: %d\n", (int)num);
    printf("Float: %.2f\n", num);
    printf("Hexadecimal: %x\n", (int)num);
    printf("Octal: %o\n", (int)num);
    printf("Pointer address: %p\n", &num);

    return 0;
}
```
### Explanation:
- The `printf()` function is used to format the output.
- The `%.2f` format specifier is used to print the float value with two decimal places.
- The `%x` format specifier is used to print the hexadecimal representation of the integer value.
- The `%o` format specifier is used to print the octal representation of the integer value.
- The `%p` format specifier is used to print the address of the variable in hexadecimal format.


