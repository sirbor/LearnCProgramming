#include <stdio.h>
#include <stdbool.h>
/*
* Scientific Measurement Converter
* Data types and Variables
* KG to LB and Cm to INCHES and Vice Versa
*/
int main(void)
{
char choice;
unsigned short menu_option;
float input_value;
bool valid_input = false;
double precise_result;

const float KG_TO_LB = 2.20462;
const float CM_TO_INCHES = 0.393701;

printf("===Scientific Measurement Converter===\n");
while (!valid_input) {
    printf("\nChoose a conversion\n");
    printf("1. Convert from CM to INCHES\n");
    printf("2. Convert from INCHES to CM\n");
    printf("3. Convert from KG to LB\n");
    printf("4. COnvert from LB to KG\n");
    printf("Please choose a conversion option(1-4): \n");

    scanf("%hu", &menu_option);

    if(menu_option >= 1 && menu_option <= 4){
      valid_input = true;

    printf("Please input a value to convert: \n");
    scanf("%f", &input_value);

      switch(menu_option){
        case 1:
        precise_result = input_value * CM_TO_INCHES;
        printf("%f CM is %f Inches\n", input_value, precise_result);
        break;
        case 2:
        precise_result = input_value / CM_TO_INCHES;
        printf("%f Inches is %f Centimeters\n", input_value, precise_result);
        break;
        case 3:
        precise_result = input_value * KG_TO_LB;
        printf("%f KG is %f LB\n", input_value, precise_result);
        break;
        case 4:
        precise_result = input_value / KG_TO_LB;
        printf("%f LB is %f KG\n", input_value, precise_result);
        break;
      }
           }
     else {
        printf("Invalid Input! Please enter the option(1-4)\n");
        while(getchar() != '\n');
    }
    return (0);
  }
}
