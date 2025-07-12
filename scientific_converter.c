#include <stdio.h>
#include <stdbool.h>
/*This is a project to display
* skills learnt on the dataypes and variables 
* in C Programming Language
*
*/
int main(void)
{
   // Demonstrate different data types
    char choice;               // Single character input
    unsigned short menu_option; // Positive menu selection
    float input_value;         // Measurement to convert (real number)
    double precise_result;     // High-precision result
    bool valid_input = false;  // Boolean flag

    // Conversion factors (demonstrates constants)
    const float CM_TO_INCH = 0.393701;
    const double KG_TO_LB = 2.20462;

    printf("=== Scientific Measurement Converter ===\n");
    
    while (!valid_input) {
        printf("\nChoose conversion:\n");
        printf("1. Centimeters to Inches\n");
        printf("2. Inches to Centimeters\n");
        printf("3. Kilograms to Pounds\n");
        printf("4. Pounds to Kilograms\n");
        printf("Enter choice (1-4): ");
        
        scanf("%hu", &menu_option); // %hu for unsigned short

        if (menu_option >= 1 && menu_option <= 4) {
            valid_input = true;
            
            printf("Enter value to convert: ");
            scanf("%f", &input_value);

            switch (menu_option) {
                case 1:
                    precise_result = input_value * CM_TO_INCH;
                    printf("%.2f cm = %.4f inches\n", input_value, precise_result);
                    break;
                case 2:
                    precise_result = input_value / CM_TO_INCH;
                    printf("%.2f inches = %.4f cm\n", input_value, precise_result);
                    break;
                case 3:
                    precise_result = input_value * KG_TO_LB;
                    printf("%.2f kg = %.4f lbs\n", input_value, precise_result);
                    break;
                case 4:
                    precise_result = input_value / KG_TO_LB;
                    printf("%.2f lbs = %.4f kg\n", input_value, precise_result);
                    break;
            }
        } else {
            printf("Invalid input! Please enter 1-4.\n");
            // Clear input buffer
            while (getchar() != '\n');
        }
    }

    return 0;
}

