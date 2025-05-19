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


