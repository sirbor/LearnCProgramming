### This is a program to show the syntax of a simple program in C

```c
#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}

```

### Explanation:

- This program includes the standard input-output library `stdio.h`,
- Defines the main function, and prints "Hello, World!" to the console.
- The `\n` is used to add a new line after the output. The program returns 0 to indicate successful execution.

### How to Compile and Run:

1. Save the code in a file named `helloworld.c`.
2. Open a terminal and navigate to the directory where the file is saved.
3. Compile the program using the command:

   ```
   gcc helloworld.c -o helloworld

   ```

4. Run the compiled program using the command:

   ```
    ./helloworld
   ```

### Output:

```
Hello, World!

```

### Additional Notes:

- Ensure you have GCC (GNU Compiler Collection) installed on your system to compile C programs.
- You can also use other compilers like Clang or MSVC, but the commands may vary slightly.
- This is a basic example to demonstrate the syntax and structure of a C program.
