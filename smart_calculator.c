#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function prototypes
void display_menu();
void arithmetic_operations();
void increment_decrement();
void assignment_operations();
void relational_operations();
void logical_operations();
void bitwise_operations();
void comma_operator_demo();
void sizeof_operator_demo();
void ternary_operator_demo();
void pointer_operations();
void member_operations();
void operator_precedence();
void common_pitfalls();
void clear_screen();
void press_enter_to_continue();

// Helper macro for section headers
#define SECTION_HEADER(title) \
    printf("\n=== %s ===\n", title); \
    printf("================================\n")

// Structure for member operations demo
typedef struct {
    int x;
    int y;
    char name[20];
} Point;

int main() {
    int choice;
    do {
        display_menu();
        printf("\nEnter your choice (1-14, 0 to exit): ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1: arithmetic_operations(); break;
            case 2: increment_decrement(); break;
            case 3: assignment_operations(); break;
            case 4: relational_operations(); break;
            case 5: logical_operations(); break;
            case 6: bitwise_operations(); break;
            case 7: comma_operator_demo(); break;
            case 8: sizeof_operator_demo(); break;
            case 9: ternary_operator_demo(); break;
            case 10: pointer_operations(); break;
            case 11: member_operations(); break;
            case 12: operator_precedence(); break;
            case 13: common_pitfalls(); break;
            case 14: clear_screen(); break;
            case 0: printf("\nExiting program. Goodbye!\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}

void display_menu() {
    clear_screen();
    printf("\n===== Ultimate C Operator Reference =====\n");
    printf("||                                    ||\n");
    printf("||  1. Arithmetic Operators          ||\n");
    printf("||  2. Increment/Decrement Operators ||\n");
    printf("||  3. Assignment Operators          ||\n");
    printf("||  4. Relational Operators          ||\n");
    printf("||  5. Logical Operators             ||\n");
    printf("||  6. Bitwise Operators             ||\n");
    printf("||  7. Comma Operator                ||\n");
    printf("||  8. sizeof Operator               ||\n");
    printf("||  9. Ternary (Conditional) Operator||\n");
    printf("|| 10. Pointer & Address Operators   ||\n");
    printf("|| 11. Member Access Operators       ||\n");
    printf("|| 12. Operator Precedence           ||\n");
    printf("|| 13. Common Pitfalls               ||\n");
    printf("|| 14. Clear Screen                  ||\n");
    printf("||  0. Exit                          ||\n");
    printf("||                                    ||\n");
    printf("========================================\n");
}

void arithmetic_operations() {
    clear_screen();
    SECTION_HEADER("Arithmetic Operators");
    
    printf("\nBasic arithmetic operators perform mathematical calculations:\n");
    printf("+ : Addition\n");
    printf("- : Subtraction\n");
    printf("* : Multiplication\n");
    printf("/ : Division\n");
    printf("%% : Modulus (remainder)\n");
    
    printf("\nEnter two integers (e.g., 15 4): ");
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("\nResults:\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    
    if (b != 0) {
        printf("%d / %d = %d (integer division)\n", a, b, a / b);
        printf("%d / %d = %.2f (floating-point division)\n", a, b, (float)a / b);
        printf("%d %% %d = %d (modulus/remainder)\n", a, b, a % b);
    } else {
        printf("\nWarning: Division by zero is undefined!\n");
    }
    
    printf("\nKey Notes:");
    printf("\n- Integer division truncates the decimal portion");
    printf("\n- Modulus operator only works with integers");
    printf("\n- Floating-point division requires at least one operand to be float/double");
    
    press_enter_to_continue();
}

void increment_decrement() {
    clear_screen();
    SECTION_HEADER("Increment/Decrement Operators");
    
    printf("\nThese operators modify a variable's value by 1:\n");
    printf("++x : Pre-increment (increments then returns new value)\n");
    printf("x++ : Post-increment (returns value then increments)\n");
    printf("--x : Pre-decrement\n");
    printf("x-- : Post-decrement\n");
    
    printf("\nEnter an integer: ");
    int x;
    scanf("%d", &x);
    int original = x;
    
    printf("\nInitial value: %d\n", original);
    
    // Fixed sequencing issues
    ++x;
    printf("++x : %d (x is now %d)\n", x, x);
    x = original;
    int post_inc = x++;
    printf("x++ : %d (x is now %d)\n", post_inc, x);
    x = original;
    --x;
    printf("--x : %d (x is now %d)\n", x, x);
    x = original;
    int post_dec = x--;
    printf("x-- : %d (x is now %d)\n", post_dec, x);
    
    printf("\nKey Notes:");
    printf("\n- Avoid using multiple increments/decrements on the same variable in a single expression");
    printf("\n- Pre and post versions behave differently when used in larger expressions");
    printf("\n- These operators modify the original variable");
    
    press_enter_to_continue();
}

void assignment_operations() {
    clear_screen();
    SECTION_HEADER("Assignment Operators");
    
    printf("\nAssignment operators combine arithmetic with assignment:\n");
    printf("=  : Simple assignment\n");
    printf("+= : Add and assign\n");
    printf("-= : Subtract and assign\n");
    printf("*= : Multiply and assign\n");
    printf("/= : Divide and assign\n");
    printf("%%= : Modulus and assign\n");
    printf("&= : Bitwise AND and assign\n");
    printf("|= : Bitwise OR and assign\n");
    printf("^= : Bitwise XOR and assign\n");
    printf("<<= : Left shift and assign\n");
    printf(">>= : Right shift and assign\n");
    
    printf("\nEnter two integers (e.g., 5 3): ");
    int a, b;
    scanf("%d %d", &a, &b);
    int original = a;
    
    printf("\nInitial values: a = %d, b = %d\n", a, b);
    
    a = original; a += b;
    printf("a += b → a = %d\n", a);
    
    a = original; a -= b;
    printf("a -= b → a = %d\n", a);
    
    a = original; a *= b;
    printf("a *= b → a = %d\n", a);
    
    a = original;
    if (b != 0) {
        a /= b;
        printf("a /= b → a = %d\n", a);
        a = original;
        a %= b;
        printf("a %%= b → a = %d\n", a);
    } else {
        printf("\nWarning: Division/modulus by zero is undefined!\n");
    }
    
    a = original; a &= b;
    printf("a &= b → a = %d\n", a);
    
    a = original; a |= b;
    printf("a |= b → a = %d\n", a);
    
    a = original; a ^= b;
    printf("a ^= b → a = %d\n", a);
    
    a = original; a <<= 1;
    printf("a <<= 1 → a = %d\n", a);
    
    a = original; a >>= 1;
    printf("a >>= 1 → a = %d\n", a);
    
    press_enter_to_continue();
}

void relational_operations() {
    clear_screen();
    SECTION_HEADER("Relational Operators");
    
    printf("\nRelational operators compare values and return 1 (true) or 0 (false):\n");
    printf(">  : Greater than\n");
    printf("<  : Less than\n");
    printf(">= : Greater than or equal\n");
    printf("<= : Less than or equal\n");
    printf("== : Equal to\n");
    printf("!= : Not equal to\n");
    
    printf("\nEnter two integers to compare: ");
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("\nResults:\n");
    printf("%d > %d : %d\n", a, b, a > b);
    printf("%d < %d : %d\n", a, b, a < b);
    printf("%d >= %d : %d\n", a, b, a >= b);
    printf("%d <= %d : %d\n", a, b, a <= b);
    printf("%d == %d : %d\n", a, b, a == b);
    printf("%d != %d : %d\n", a, b, a != b);
    
    press_enter_to_continue();
}

void logical_operations() {
    clear_screen();
    SECTION_HEADER("Logical Operators");
    
    printf("\nLogical operators work with boolean values (0=false, non-zero=true):\n");
    printf("&& : Logical AND\n");
    printf("|| : Logical OR\n");
    printf("!  : Logical NOT\n");
    
    printf("\nEnter two integers (0=false, non-zero=true): ");
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("\nResults:\n");
    printf("%d && %d : %d\n", a, b, a && b);
    printf("%d || %d : %d\n", a, b, a || b);
    printf("!%d : %d\n", a, !a);
    printf("!%d : %d\n", b, !b);
    
    printf("\nKey Notes:");
    printf("\n- Logical operators use short-circuit evaluation");
    printf("\n- Any non-zero value is considered true");
    printf("\n- The result is always 1 (true) or 0 (false)");
    
    press_enter_to_continue();
}

void bitwise_operations() {
    clear_screen();
    SECTION_HEADER("Bitwise Operators");
    
    printf("\nBitwise operators work on the binary representation of numbers:\n");
    printf("&  : Bitwise AND\n");
    printf("|  : Bitwise OR\n");
    printf("^  : Bitwise XOR\n");
    printf("~  : Bitwise NOT (one's complement)\n");
    printf("<< : Left shift\n");
    printf(">> : Right shift\n");
    
    printf("\nEnter two positive integers (e.g., 5 3): ");
    unsigned int a, b;
    scanf("%u %u", &a, &b);
    
    printf("\nResults (in decimal and binary):\n");
    printf("%u & %u = %u\n", a, b, a & b);
    printf("%u | %u = %u\n", a, b, a | b);
    printf("%u ^ %u = %u\n", a, b, a ^ b);
    printf("~%u = %u\n", a, ~a);
    printf("%u << 1 = %u\n", a, a << 1);
    printf("%u >> 1 = %u\n", a, a >> 1);
    
    printf("\nKey Notes:");
    printf("\n- Bitwise operators work on the binary representation");
    printf("\n- Left shift multiplies by 2, right shift divides by 2");
    printf("\n- Bitwise NOT flips all bits");
    
    press_enter_to_continue();
}

void comma_operator_demo() {
    clear_screen();
    SECTION_HEADER("Comma Operator");
    
    printf("\nThe comma operator evaluates multiple expressions and returns the last one:\n");
    
    int a = 5, b = 10;
    printf("Initial values: a = %d, b = %d\n", a, b);
    
    int result = (a += 5, b += a, a + b);
    printf("After (a += 5, b += a, a + b):\n");
    printf("a = %d, b = %d, result = %d\n", a, b, result);
    
    printf("\nIn for loops:\n");
    for(int i = 0, j = 10; i < j; i++, j--) {
        printf("i = %d, j = %d\n", i, j);
    }
    
    printf("\nKey Notes:");
    printf("\n- Expressions are evaluated left to right");
    printf("\n- The value of the whole expression is the last expression's value");
    printf("\n- Commonly used in for loops and complex macros");
    
    press_enter_to_continue();
}

void sizeof_operator_demo() {
    clear_screen();
    SECTION_HEADER("sizeof Operator");
    
    printf("\nThe sizeof operator returns the size in bytes of its operand:\n");
    
    printf("\nBasic types:\n");
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(float) = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    
    printf("\nDerived types:\n");
    int arr[10];
    printf("sizeof(int[10]) = %zu\n", sizeof(arr));
    
    struct example {
        int a;
        char b;
        double c;
    };
    printf("sizeof(struct example) = %zu\n", sizeof(struct example));
    
    printf("\nKey Notes:");
    printf("\n- Returns size in bytes as size_t (unsigned)");
    printf("\n- Works with types and expressions");
    printf("\n- Evaluated at compile-time, not runtime");
    
    press_enter_to_continue();
}

void ternary_operator_demo() {
    clear_screen();
    SECTION_HEADER("Ternary (Conditional) Operator");
    
    printf("\nThe ternary operator (?:) is a shorthand for if-else:\n");
    printf("condition ? expression1 : expression2\n");
    
    printf("\nEnter two integers: ");
    int a, b;
    scanf("%d %d", &a, &b);
    
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    printf("The larger value is: %d\n", max);
    printf("The smaller value is: %d\n", min);
    
    printf("\nNested ternary example:\n");
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    const char *result = (num > 0) ? "positive" : ((num < 0) ? "negative" : "zero");
    printf("The number is %s\n", result);
    
    printf("\nKey Notes:");
    printf("\n- More concise than if-else for simple conditions");
    printf("\n- Can be nested but becomes hard to read");
    printf("\n- Both expressions must be of compatible types");
    
    press_enter_to_continue();
}

void pointer_operations() {
    clear_screen();
    SECTION_HEADER("Pointer & Address Operators");
    
    printf("\nPointer operators:\n");
    printf("& : Address-of operator\n");
    printf("* : Dereference operator\n");
    
    int x = 42;
    int *ptr = &x;
    
    printf("\nVariable x = %d at address %p\n", x, (void*)&x);
    printf("Pointer ptr = %p points to value %d\n", (void*)ptr, *ptr);
    
    *ptr = 100;
    printf("After *ptr = 100, x = %d\n", x);
    
    int arr[3] = {10, 20, 30};
    printf("\nArray operations:\n");
    printf("arr[0] = %d at %p\n", arr[0], (void*)&arr[0]);
    printf("*(arr+1) = %d (same as arr[1])\n", *(arr+1));
    
    printf("\nPointer arithmetic:\n");
    printf("ptr = %p, ptr+1 = %p\n", (void*)ptr, (void*)(ptr+1));
    
    printf("\nKey Notes:");
    printf("\n- & gets the address of a variable");
    printf("\n- * dereferences a pointer to access the value");
    printf("\n- Pointer arithmetic depends on the pointed-to type size");
    
    press_enter_to_continue();
}

void member_operations() {
    clear_screen();
    SECTION_HEADER("Member Access Operators");
    
    printf("\nMember access operators:\n");
    printf(".  : Direct member access\n");
    printf("-> : Indirect member access (through pointer)\n");
    
    Point p1 = {10, 20, "Point A"};
    Point *p_ptr = &p1;
    
    printf("\nDirect access:\n");
    printf("p1.x = %d, p1.y = %d, p1.name = %s\n", p1.x, p1.y, p1.name);
    
    printf("\nPointer access:\n");
    printf("p_ptr->x = %d, p_ptr->y = %d, p_ptr->name = %s\n", 
           p_ptr->x, p_ptr->y, p_ptr->name);
    
    printf("\nArray of structures:\n");
    Point points[2] = {{1, 2, "First"}, {3, 4, "Second"}};
    printf("points[0].name = %s\n", points[0].name);
    printf("(points+1)->name = %s\n", (points+1)->name);
    
    printf("\nKey Notes:");
    printf("\n- Use . for direct structure access");
    printf("\n- Use -> for access through pointers");
    printf("\n- These have higher precedence than most other operators");
    
    press_enter_to_continue();
}

void operator_precedence() {
    clear_screen();
    SECTION_HEADER("Operator Precedence");
    
    printf("\nOperator Precedence Table (Highest to Lowest):\n");
    printf("=============================================\n");
    printf("() [] -> .  : Function call, array subscript, member access\n");
    printf("! ~ ++ -- + - * & (type) sizeof : Unary operators\n");
    printf("* / %%       : Multiplication, division, modulus\n");
    printf("+ -         : Addition, subtraction\n");
    printf("<< >>       : Bitwise shifts\n");
    printf("< <= > >=   : Relational\n");
    printf("== !=       : Equality\n");
    printf("&           : Bitwise AND\n");
    printf("^           : Bitwise XOR\n");
    printf("|           : Bitwise OR\n");
    printf("&&          : Logical AND\n");
    printf("||          : Logical OR\n");
    printf("?:          : Ternary conditional\n");
    printf("= += -= etc : Assignment\n");
    printf(",           : Comma operator\n");
    
    printf("\nExamples of precedence in action:\n");
    int a = 5, b = 3, c = 2;
    printf("a + b * c = %d (not %d)\n", a + b * c, (a + b) * c);
    printf("!a && b = %d\n", !a && b);
    printf("!(a && b) = %d\n", !(a && b));
    
    printf("\nKey Notes:");
    printf("\n- Use parentheses to clarify or override precedence");
    printf("\n- When in doubt, add parentheses");
    printf("\n- Some operators have right-to-left associativity");
    
    press_enter_to_continue();
}

void common_pitfalls() {
    clear_screen();
    SECTION_HEADER("Common Operator Pitfalls");
    
    printf("\n1. Assignment (=) vs Equality (==):\n");
    printf("   if (x = 5) {...} // Assigns 5 to x, always true\n");
    printf("   if (x == 5) {...} // Correct comparison\n");
    
    printf("\n2. Integer Division:\n");
    printf("   double d = 5/2; // 2.0, not 2.5\n");
    printf("   double d = 5.0/2; // 2.5\n");
    
    printf("\n3. Operator Precedence:\n");
    printf("   a & b == c // Equivalent to a & (b == c)\n");
    printf("   (a & b) == c // Probably what was intended\n");
    
    printf("\n4. Side Effects in Expressions:\n");
    printf("   a[i] = i++; // Undefined behavior\n");
    
    printf("\n5. Floating-point Comparisons:\n");
    printf("   Never use == with floats due to precision issues\n");
    printf("   Instead: fabs(a - b) < epsilon\n");
    
    printf("\n6. Short-circuit Evaluation:\n");
    printf("   if (ptr != NULL && *ptr == 42) // Safe\n");
    printf("   if (*ptr == 42 && ptr != NULL) // Crash if ptr is NULL\n");
    
    printf("\nKey Advice:");
    printf("\n- Enable compiler warnings (-Wall -Wextra)");
    printf("\n- Use parentheses liberally");
    printf("\n- Be explicit about your intentions");
    
    press_enter_to_continue();
}

void press_enter_to_continue() {
    printf("\n\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
