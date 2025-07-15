### Input and Output in C

- In C, input and output operations are primarily handled through the standard library functions.
- The most common functions for input and output are `printf` for output and `scanf` for input.

#### Output with `printf`

The `printf` function is used to print formatted output to the standard output (usually the console). The syntax is as follows:

```c
#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}
```

#### Input with `scanf`

The `scanf` function is used to read formatted input from the standard input (usually the keyboard). The syntax is as follows:

```c
#include <stdio.h>
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered: %d\n", number);
    return 0;
}
```

#### Formatted Output

You can format the output using format specifiers in `printf`. Here are some common format specifiers:

- `%d` for integers
- `%f` for floating-point numbers
- `%c` for characters
- `%s` for strings

#### Example of Formatted Output

```c
#include <stdio.h>
int main() {
    int age = 25;
    float height = 5.9;
    char initial = 'A';
    char name[] = "Alice";

    printf("Name: %s\n", name);
    printf("Initial: %c\n", initial);
    printf("Age: %d\n", age);
    printf("Height: %.1f feet\n", height);

    return 0;
}
```

#### Input with Multiple Values

You can read multiple values in a single `scanf` call by separating the format specifiers with spaces. For example:

```c
#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("You entered: %d and %d\n", a, b);
    return 0;
}
```

#### Error Handling in Input

When using `scanf`, it's important to check if the input was successful. You can do this by checking the return value of `scanf`, which indicates the number of successfully read items.

```c
#include <stdio.h>
int main() {
    int number;
    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input!\n");
        return 1; // Exit with an error code
    }
    printf("You entered: %d\n", number);
    return 0;
}
```

#### Reading Strings

To read strings, you can use `scanf` with the `%s` format specifier. However, be cautious about buffer overflow. It's safer to use `fgets` for reading strings.

```c
#include <stdio.h>
int main() {
    char name[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // safer than scanf for strings
    printf("Hello, %s", name);
    return 0;
}
```

#### Summary

- In C, input and output operations are handled using functions from the standard library.
- The `printf` function is used for formatted output, while `scanf` is used for reading input.
- It's important to handle errors and buffer sizes properly to avoid issues like buffer overflow.
- For reading strings, `fgets` is often preferred over `scanf` for safety. Always check the return values of input functions to ensure successful operations.

#### File Input and Output

- In addition to standard input and output, C also provides functions for file input and output.
- The standard library provides functions like `fopen`, `fclose`, `fprintf`, `fscanf`, `fread`, and `fwrite` for working with files.

#### Example of File I/O

```c
#include <stdio.h>
int main() {
    FILE *file = fopen("example.txt", "w"); // Open file for writing
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Hello, File!\n"); // Write to file
    fclose(file); // Close the file

    file = fopen("example.txt", "r"); // Open file for reading
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), file); // Read from file
    printf("File content: %s", buffer);

    fclose(file); // Close the file
    return 0;
}
```

#### Summary of File I/O

- File input and output in C is handled using file pointers and functions from the standard library.
- You can open files using `fopen`, read from or write to them using `fprintf`, `fscanf`, `fread`, and `fwrite`, and close them with `fclose`.
- Always check if the file was opened successfully before performing operations on it.

#### Error Handling in File I/O

- When working with files, it's crucial to handle errors properly.
- Always check if the file pointer returned by `fopen` is `NULL`, which indicates that the file could not be opened.
- Additionally, check the return values of functions like `fprintf` and `fscanf` to ensure that operations were successful.

```c
#include <stdio.h>
int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (fprintf(file, "Hello, File!\n") < 0) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    fclose(file);

    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        perror("Error reading from file");
        fclose(file);
        return 1;
    }

    printf("File content: %s", buffer);

    fclose(file);
    return 0;
}
```

#### Summary of Error Handling in File I/O

- When performing file operations, always check for errors by verifying if the file pointer is `NULL` after opening a file.
- Use functions like `perror` to print error messages when operations fail.
- This helps in diagnosing issues related to file access, such as permissions or non-existent files.

#### Conclusion

- Input and output in C are fundamental operations that allow interaction with users and files.
- The `printf` and `scanf` functions are essential for console I/O, while file operations are handled through a set of standard library functions.
- Proper error handling is crucial to ensure robust and reliable programs. By understanding these concepts, you can effectively manage input and output in your C programs.
