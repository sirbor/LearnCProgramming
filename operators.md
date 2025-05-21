### Operators
- An operator is a symbol that operateson a value or a variable.
- C has a wide range of operators
1. Arithmetic Operators - used to perform mathematical operations.
- They include addition (+), subtraction (-), multiplication(*), division(/), and modulus(%).
- The arithmetic operators are used to perform basic mathematical calculations.

2. Relational Operators - used to compare two values.
- They include equal to (==), not equal to (!=), greater than (>), less than (<), greater than or equal to (>=), and less than or equal to (<=).
- The relational operators are used to compare two values and return a boolean result (true or false).

3. Logical Operators - used to combine multiple boolean expressions.
- They include logical AND (&&), logical OR (||), and logical NOT (!).
- The logical operators are used to perform logical operations on boolean values.

4. Bitwise Operators - operate on data at bit level
- They include bitwise AND (&), bitwise OR (|), bitwise XOR (^), left shift (<<), right shift (>>), and bitwise NOT (~).
- The bitwise operators are used to perform operations on individual bits of data.

5. Assignment Operators - used to assign values to variables.
- They include simple assignment (=), addition assignment (+=), subtraction assignment (-=), multiplication assignment (*=), division assignment (/=), and modulus assignment (%=).
- The assignment operators are used to assign values to variables in a concise manner.

6. Conditional Operators - also known as the ternary operator, used to evaluate a condition and return one of two values based on the result.
- The syntax is `condition ? value_if_true : value_if_false`.
- The conditional operator is a shorthand way of writing an if-else statement.

7. Increment and Decrement Operators - used to increase or decrease the value of a variable by 1.
- They include increment (++) and decrement (--).
- The increment operator increases the value of a variable by 1, while the decrement operator decreases the value of a variable by 1.

8. Sizeof Operator - used to determine the size of a data type or variable in bytes.
- The syntax is `sizeof(data_type)` or `sizeof(variable)`.
- The sizeof operator is useful for determining the memory size of different data types and variables.
- The sizeof operator returns the size in bytes of the specified data type or variable.
- It is commonly used to allocate memory dynamically using functions like malloc() and calloc().
- The sizeof operator can be used with any data type, including user-defined types like structures and unions.
- It is important to note that the sizeof operator returns the size in bytes, which may vary depending on the architecture of the system (32-bit or 64-bit).
- The sizeof operator can also be used with arrays to determine the total size of the array in bytes.
- The sizeof operator can be used with pointers to determine the size of the pointer itself, not the size of the data it points to.
- The sizeof operator is evaluated at compile time, making it efficient for determining sizes of data types and variables.

9. Comma Operator  - used to separate multiple expressions in a single statement.
- The syntax is `expression1, expression2, ..., expressionN`.
- The comma operator evaluates each expression from left to right and returns the value of the last expression.
- The comma operator is often used in for loops to separate initialization, condition, and increment expressions.
- It can also be used in function calls to pass multiple arguments.
- The comma operator has lower precedence than most other operators, so it is important to use parentheses to control the order of evaluation when necessary.
- The comma operator can be useful for writing concise code, but it can also make the code less readable if overused.
- It is generally recommended to use the comma operator sparingly and only when it improves code clarity.

