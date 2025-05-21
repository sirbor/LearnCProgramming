#include <stdio.h>

int main(void) {

  int a = 10, b = 3;
  int sum , diff , product , mod;
  float quotient;

  //Arithmetic Operators
  sum = a + b;
  diff = a - b;
  product = a * b;
  quotient = (float)a / b; // Type casting to float for accurate division
  mod = a % b;

  //Relational Operators
  int isEqual = (a == b);
  int isNotEqual = (a != b);
  int isGreater = (a > b);
  int isLess = (a < b);
  int isGreaterOrEqual = (a >= b);
  int isLessOrEqual = (a <= b);

  //Logical Operators
  int andResult = (a > 5 && b < 5); // Logical AND
  int orResult = (a > 5 || b < 5); // Logical OR
  int notResult = !(a > 5); // Logical NOT

  // Bitwise Operators
  int bitwiseAnd = a & b; // Bitwise AND
  int bitwiseOr = a | b; // Bitwise OR
  int bitwiseXor = a ^ b; // Bitwise XOR
  int leftShift = a << 1; // Left Shift
  int rightShift = a >> 1; // Right Shift
  
  //Increment and Decrement Operators
  a++; // Increment
  b--; // Decrement

  //Printing results
  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", diff);
  printf("Product: %d\n", product);
  printf("Quotient: %.2f\n", quotient);
  printf("Modulus: %d\n", mod);

  printf("Is Equal: %d\n", isEqual);
  printf("Is Not Equal: %d\n", isNotEqual);
  printf("Is Greater: %d\n", isGreater);
  printf("Is Less: %d\n", isLess);
  printf("Is Greater or Equal: %d\n", isGreaterOrEqual);
  printf("Is Less or Equal: %d\n", isLessOrEqual);

  printf("Logical AND Result: %d\n", andResult);
  printf("Logical OR Result: %d\n", orResult);
  printf("Logical NOT Result: %d\n", notResult);

  printf("Bitwise AND: %d\n", bitwiseAnd);
  printf("Bitwise OR: %d\n", bitwiseOr);
  printf("Bitwise XOR: %d\n", bitwiseXor);
  printf("Left Shift: %d\n", leftShift);
  printf("Right Shift: %d\n", rightShift);

  printf("Incremented a: %d\n", a);
  printf("Decremented b: %d\n", b);


}
