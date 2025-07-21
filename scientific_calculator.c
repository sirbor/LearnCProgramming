/**
 * @file smart_calculator.c
 * @brief Complete smart calculator with scientific, programmer, graphing, and statistical functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <complex.h>
#include <dirent.h>

#define MAX_HISTORY 50
#define MAX_EXPR_LEN 200
#define MAX_VARS 26
#define PI 3.14159265358979323846
#define EULER 2.71828182845904523536
#define HISTORY_FILE "calculator_history.txt"
#define GRAPH_WIDTH 60
#define GRAPH_HEIGHT 20

/* Complex number type */
typedef double complex cmplx;

/* Enhanced enum types */
typedef enum {
    DEG, RAD, GRAD
} AngleMode;

typedef enum {
    BASIC, SCIENTIFIC, PROGRAMMER, CONVERTER, GRAPHING
} CalcMode;

typedef enum {
    DECIMAL, HEX, OCTAL, BINARY
} NumberBase;

typedef enum {
    REAL_MODE, CMPLX_MODE
} NumberMode;

/* Enhanced struct for calculations */
typedef struct {
    char expression[MAX_EXPR_LEN];
    double result;
    cmplx cmplx_result;
    time_t timestamp;
    NumberMode num_mode;
} Calculation;

/* Variable storage structure */
typedef struct {
    char name;
    double value;
    cmplx cmplx_value;
    bool is_complex;
} Variable;

/* Enhanced calculator state */
typedef struct {
    AngleMode angle_mode;
    CalcMode current_mode;
    NumberBase num_base;
    NumberMode num_mode;
    Calculation history[MAX_HISTORY];
    int history_count;
    double last_result;
    cmplx last_cmplx_result;
    double memory_register;
    cmplx cmplx_memory_register;
    bool debug_mode;
    Variable variables[MAX_VARS];
    FILE* history_file;
} CalculatorState;

/* Global state with initialization */
CalculatorState calc = {
    .angle_mode = DEG,
    .current_mode = BASIC,
    .num_base = DECIMAL,
    .num_mode = REAL_MODE,
    .history_count = 0,
    .last_result = 0,
    .last_cmplx_result = 0,
    .memory_register = 0,
    .cmplx_memory_register = 0,
    .debug_mode = false,
    .history_file = NULL
};

/* Function prototypes */
void initialize_calculator();
void cleanup_calculator();
void display_main_menu();
void run_basic_calculator();
void run_scientific_calculator();
void run_programmer_calculator();
void run_unit_converter();
void run_graphing_calculator();
void show_history();
void save_history_to_file();
void load_history_from_file();
void clear_history();
void show_help();
void toggle_angle_mode();
void toggle_number_base();
void toggle_number_mode();
void memory_operations();
void variable_operations();
void statistical_calculations();
double evaluate_expression(const char *expr);
cmplx evaluate_complex_expression(const char *expr);
void add_to_history(const char *expr, double result, cmplx cmplx_result);
void print_result(double result, cmplx cmplx_result);
void print_complex_number(cmplx num);
void print_welcome();
void print_debug_info();
int get_user_input(char *buffer, size_t size);
void handle_error(const char *message);
void convert_temperature();
void convert_length();
void convert_weight();
void print_number_in_base(double num);
void remove_spaces(char* str);
void initialize_variables();
double get_variable_value(char name);
cmplx get_complex_variable(char name);
void set_variable(char name, double value);
void set_complex_variable(char name, cmplx value);
void plot_function(const char* expr);
void show_variables();
void process_command(const char* input);
bool is_reserved_word(const char* word);
void print_graph_border();
void print_graph_axis();

/**
 * @brief Main program entry point
 */
int main() {
    initialize_calculator();
    print_welcome();
    
    while (true) {
        display_main_menu();
        
        char input[20];
        if (get_user_input(input, sizeof(input)) {
            handle_error("Invalid input");
            continue;
        }

        if (strcmp(input, "0") == 0) break;

        process_command(input);
    }

    cleanup_calculator();
    return EXIT_SUCCESS;
}

/**
 * @brief Initialize calculator state and load history
 */
void initialize_calculator() {
    initialize_variables();
    load_history_from_file();
    
    // Initialize complex memory
    calc.cmplx_memory_register = 0 + 0*I;
    calc.last_cmplx_result = 0 + 0*I;
}

/**
 * @brief Clean up resources before exit
 */
void cleanup_calculator() {
    save_history_to_file();
    if (calc.history_file) fclose(calc.history_file);
}

/**
 * @brief Initialize variable storage
 */
void initialize_variables() {
    for (int i = 0; i < MAX_VARS; i++) {
        calc.variables[i].name = 'a' + i;
        calc.variables[i].value = 0;
        calc.variables[i].cmplx_value = 0 + 0*I;
        calc.variables[i].is_complex = false;
    }
}

/**
 * @brief Save calculation history to file
 */
void save_history_to_file() {
    FILE* f = fopen(HISTORY_FILE, "w");
    if (!f) {
        handle_error("Could not save history");
        return;
    }
    
    for (int i = 0; i < calc.history_count; i++) {
        fprintf(f, "%ld|%s|%f|%f|%f\n",
                calc.history[i].timestamp,
                calc.history[i].expression,
                calc.history[i].result,
                creal(calc.history[i].cmplx_result),
                cimag(calc.history[i].cmplx_result));
    }
    
    fclose(f);
}

/**
 * @brief Load calculation history from file
 */
void load_history_from_file() {
    FILE* f = fopen(HISTORY_FILE, "r");
    if (!f) return;
    
    char line[MAX_EXPR_LEN + 100];
    while (fgets(line, sizeof(line), f)) {
        char* parts[5];
        char* token = strtok(line, "|");
        int i = 0;
        
        while (token && i < 5) {
            parts[i++] = token;
            token = strtok(NULL, "|");
        }
        
        if (i == 5) {
            Calculation c;
            c.timestamp = atol(parts[0]);
            strncpy(c.expression, parts[1], MAX_EXPR_LEN);
            c.result = atof(parts[2]);
            c.cmplx_result = atof(parts[3]) + atof(parts[4])*I;
            add_to_history(c.expression, c.result, c.cmplx_result);
        }
    }
    
    fclose(f);
}

/**
 * @brief Process user commands
 */
void process_command(const char* input) {
    switch (input[0]) {
        case '1': run_basic_calculator(); break;
        case '2': run_scientific_calculator(); break;
        case '3': run_programmer_calculator(); break;
        case '4': run_unit_converter(); break;
        case '5': show_history(); break;
        case '6': show_help(); break;
        case '7': memory_operations(); break;
        case '8': toggle_angle_mode(); break;
        case '9': toggle_number_base(); break;
        case 'a': toggle_number_mode(); break;
        case 'b': variable_operations(); break;
        case 'c': statistical_calculations(); break;
        case 'g': run_graphing_calculator(); break;
        case 'd': calc.debug_mode = !calc.debug_mode; 
                 printf("Debug mode %s\n", calc.debug_mode ? "ON" : "OFF");
                 break;
        default: handle_error("Invalid choice");
    }
}

/**
 * @brief Displays the main menu
 */
void display_main_menu(void) {
    printf("\n=== MAIN MENU ===\n");
    printf("1. Basic Calculator\n");
    printf("2. Scientific Calculator\n");
    printf("3. Programmer Calculator\n");
    printf("4. Unit Converter\n");
    printf("5. View History\n");
    printf("6. Help\n");
    printf("7. Memory Operations\n");
    printf("8. Toggle Angle Mode (%s)\n", 
           calc.angle_mode == DEG ? "DEG" : 
           calc.angle_mode == RAD ? "RAD" : "GRAD");
    printf("9. Toggle Number Base (%s)\n",
           calc.num_base == DECIMAL ? "DEC" :
           calc.num_base == HEX ? "HEX" :
           calc.num_base == OCTAL ? "OCT" : "BIN");
    printf("a. Toggle Number Mode (%s)\n",
           calc.num_mode == REAL_MODE ? "REAL" : "COMPLEX");
    printf("b. Variable Operations\n");
    printf("c. Statistical Calculations\n");
    printf("g. Graphing Calculator\n");
    printf("d. Toggle Debug Mode\n");
    printf("0. Exit\n");
}

/**
 * @brief Runs the basic calculator mode
 */
void run_basic_calculator(void) {
    printf("\n=== BASIC CALCULATOR ===\n");
    printf("Supports +, -, *, /, %%, ^ (power)\n");
    printf("Variables: a-z (use 'b' to manage)\n");
    printf("Enter 'back' to return, 'help' for help\n");

    while (true) {
        char input[MAX_EXPR_LEN];
        printf("\n>> ");
        if (get_user_input(input, sizeof(input)) != 0) {
            handle_error("Input error");
            continue;
        }

        if (strcmp(input, "back") == 0) return;
        if (strcmp(input, "help") == 0) {
            printf("BASIC CALCULATOR HELP:\n");
            printf("- Operators: +, -, *, /, %%, ^\n");
            printf("- Constants: pi, e, ans (last result)\n");
            printf("- Variables: a-z (lowercase letters)\n");
            printf("- Commands: back, help, clear\n");
            continue;
        }

        if (strcmp(input, "clear") == 0) {
            clear_history();
            continue;
        }

        double result;
        cmplx cmplx_result;
        
        if (calc.num_mode == REAL_MODE) {
            result = evaluate_expression(input);
            calc.last_result = result;
            add_to_history(input, result, 0 + 0*I);
            print_result(result, 0 + 0*I);
        } else {
            cmplx_result = evaluate_complex_expression(input);
            calc.last_cmplx_result = cmplx_result;
            add_to_history(input, creal(cmplx_result), cmplx_result);
            print_result(0, cmplx_result);
        }
    }
}

/**
 * @brief Runs the scientific calculator mode
 */
void run_scientific_calculator(void) {
    printf("\n=== SCIENTIFIC CALCULATOR ===\n");
    printf("Current angle mode: %s\n", 
           calc.angle_mode == DEG ? "DEG" : 
           calc.angle_mode == RAD ? "RAD" : "GRAD");
    printf("Functions: sin, cos, tan, asin, acos, atan\n");
    printf("          sinh, cosh, tanh, log, ln, sqrt, exp\n");
    printf("Enter 'mode' to switch angle units, 'back' to return\n");

    while (true) {
        char input[MAX_EXPR_LEN];
        printf("\n>> ");
        if (get_user_input(input, sizeof(input)) != 0) {
            handle_error("Input error");
            continue;
        }

        if (strcmp(input, "back") == 0) return;
        if (strcmp(input, "mode") == 0) {
            toggle_angle_mode();
            continue;
        }

        double result;
        cmplx cmplx_result;
        
        if (calc.num_mode == REAL_MODE) {
            result = evaluate_expression(input);
            calc.last_result = result;
            add_to_history(input, result, 0 + 0*I);
            print_result(result, 0 + 0*I);
        } else {
            cmplx_result = evaluate_complex_expression(input);
            calc.last_cmplx_result = cmplx_result;
            add_to_history(input, creal(cmplx_result), cmplx_result);
            print_result(0, cmplx_result);
        }
    }
}

/**
 * @brief Runs the programmer calculator mode
 */
void run_programmer_calculator(void) {
    printf("\n=== PROGRAMMER CALCULATOR ===\n");
    printf("Current base: %s\n", 
        calc.num_base == DECIMAL ? "DEC" :
        calc.num_base == HEX ? "HEX" :
        calc.num_base == OCTAL ? "OCT" : "BIN");
    
    printf("Operators: & | x ~ << >>\n");
    printf("Commands: base, help, back\n");

    while (true) {
        char input[MAX_EXPR_LEN];
        printf("\n>> ");
        if (get_user_input(input, sizeof(input)) != 0) {
            handle_error("Input error");
            continue;
        }

        if (strcmp(input, "back") == 0) return;
        if (strcmp(input, "help") == 0) {
            printf("PROGRAMMER HELP:\n");
            printf("Operators: & (AND), | (OR), x (XOR), ~ (NOT)\n");
            printf("Shifts: << (left), >> (right)\n");
            printf("base - Switch number base\n");
            printf("show - Display last result in all bases\n");
            continue;
        }

        if (strcmp(input, "base") == 0) {
            toggle_number_base();
            continue;
        }

        if (strcmp(input, "show") == 0) {
            printf("DEC: %.0f\n", calc.last_result);
            printf("HEX: %lX\n", (long)calc.last_result);
            printf("OCT: %lo\n", (long)calc.last_result);
            printf("BIN: ");
            print_number_in_base(calc.last_result);
            continue;
        }

        double result = evaluate_expression(input);
        calc.last_result = result;
        add_to_history(input, result, 0 + 0*I);
        print_result(result, 0 + 0*I);
    }
}

/**
 * @brief Runs the graphing calculator mode
 */
void run_graphing_calculator(void) {
    printf("\n=== GRAPHING CALCULATOR ===\n");
    printf("Enter function of x (e.g., 'sin(x)', 'x^2')\n");
    printf("Type 'back' to return\n");
    
    while (true) {
        char input[MAX_EXPR_LEN];
        printf("\nEnter function: ");
        if (get_user_input(input, sizeof(input))) {
            handle_error("Input error");
            continue;
        }

        if (strcmp(input, "back") == 0) return;
        
        plot_function(input);
    }
}

/**
 * @brief Plot a function in ASCII art
 */
void plot_function(const char* expr) {
    double x_min = -10.0, x_max = 10.0;
    double y_min = -10.0, y_max = 10.0;
    
    printf("\nPlotting: %s\n", expr);
    
    char graph[GRAPH_HEIGHT][GRAPH_WIDTH];
    memset(graph, ' ', sizeof(graph));
    
    // Draw axes
    int x_axis = GRAPH_HEIGHT / 2;
    int y_axis = GRAPH_WIDTH / 2;
    
    for (int i = 0; i < GRAPH_WIDTH; i++) graph[x_axis][i] = '-';
    for (int i = 0; i < GRAPH_HEIGHT; i++) graph[i][y_axis] = '|';
    graph[x_axis][y_axis] = '+';
    
    // Plot function
    for (int col = 0; col < GRAPH_WIDTH; col++) {
        double x = x_min + (x_max - x_min) * col / GRAPH_WIDTH;
        char temp_expr[MAX_EXPR_LEN];
        snprintf(temp_expr, sizeof(temp_expr), "x=%f;%s", x, expr);
        
        double y = evaluate_expression(temp_expr);
        
        if (!isnan(y) && !isinf(y)) {
            int row = GRAPH_HEIGHT - (int)((y - y_min) * GRAPH_HEIGHT / (y_max - y_min));
            if (row >= 0 && row < GRAPH_HEIGHT) {
                graph[row][col] = '*';
            }
        }
    }
    
    // Print graph with border
    print_graph_border();
    for (int i = 0; i < GRAPH_HEIGHT; i++) {
        printf("| ");
        for (int j = 0; j < GRAPH_WIDTH; j++) {
            putchar(graph[i][j]);
        }
        printf(" |\n");
    }
    print_graph_border();
    
    // Print scale information
    printf("X range: %.1f to %.1f\n", x_min, x_max);
    printf("Y range: %.1f to %.1f\n", y_min, y_max);
}

/**
 * @brief Print graph border
 */
void print_graph_border() {
    printf("+");
    for (int i = 0; i < GRAPH_WIDTH + 2; i++) printf("-");
    printf("+\n");
}

/**
 * @brief Perform statistical calculations
 */
void statistical_calculations() {
    printf("\n=== STATISTICAL CALCULATIONS ===\n");
    printf("Enter numbers separated by spaces (e.g., '1 2 3 4 5')\n");
    printf("Type 'back' to return\n");
    
    while (true) {
        char input[MAX_EXPR_LEN];
        printf("\nEnter data: ");
        if (get_user_input(input, sizeof(input))) {
            handle_error("Input error");
            continue;
        }

        if (strcmp(input, "back") == 0) return;
        
        double numbers[100];
        int count = 0;
        char* token = strtok(input, " ");
        
        while (token && count < 100) {
            numbers[count++] = atof(token);
            token = strtok(NULL, " ");
        }
        
        if (count == 0) {
            handle_error("No numbers entered");
            continue;
        }
        
        // Calculate statistics
        double sum = 0, min = numbers[0], max = numbers[0];
        for (int i = 0; i < count; i++) {
            sum += numbers[i];
            if (numbers[i] < min) min = numbers[i];
            if (numbers[i] > max) max = numbers[i];
        }
        
        double mean = sum / count;
        
        // Variance
        double variance = 0;
        for (int i = 0; i < count; i++) {
            variance += pow(numbers[i] - mean, 2);
        }
        variance /= count;
        
        // Sort for median
        for (int i = 0; i < count-1; i++) {
            for (int j = 0; j < count-i-1; j++) {
                if (numbers[j] > numbers[j+1]) {
                    double temp = numbers[j];
                    numbers[j] = numbers[j+1];
                    numbers[j+1] = temp;
                }
            }
        }
        
        double median;
        if (count % 2 == 0) {
            median = (numbers[count/2 - 1] + numbers[count/2]) / 2.0;
        } else {
            median = numbers[count/2];
        }
        
        printf("\nStatistics:\n");
        printf("Count: %d\n", count);
        printf("Sum: %.4f\n", sum);
        printf("Mean: %.4f\n", mean);
        printf("Median: %.4f\n", median);
        printf("Min: %.4f\n", min);
        printf("Max: %.4f\n", max);
        printf("Variance: %.4f\n", variance);
        printf("Std Dev: %.4f\n", sqrt(variance));
    }
}

/**
 * @brief Runs the unit converter mode
 */
void run_unit_converter(void) {
    printf("\n=== UNIT CONVERTER ===\n");
    printf("1. Temperature\n");
    printf("2. Length\n");
    printf("3. Weight\n");
    printf("0. Back\n");

    char choice[10];
    get_user_input(choice, sizeof(choice));

    switch (choice[0]) {
        case '1': convert_temperature(); break;
        case '2': convert_length(); break;
        case '3': convert_weight(); break;
        case '0': return;
        default: handle_error("Invalid choice");
    }
}

/**
 * @brief Converts between temperature units
 */
void convert_temperature(void) {
    printf("\n=== TEMPERATURE CONVERSION ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("0. Back\n");

    char choice[10];
    get_user_input(choice, sizeof(choice));

    double temp;
    printf("Enter temperature: ");
    if (scanf("%lf", &temp) != 1) {
        handle_error("Invalid temperature input");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    while (getchar() != '\n'); // Clear input buffer

    switch (choice[0]) {
        case '1':
            printf("%.2f°C = %.2f°F\n", temp, (temp * 9/5) + 32);
            break;
        case '2':
            printf("%.2f°F = %.2f°C\n", temp, (temp - 32) * 5/9);
            break;
        case '3':
            printf("%.2f°C = %.2fK\n", temp, temp + 273.15);
            break;
        case '4':
            printf("%.2fK = %.2f°C\n", temp, temp - 273.15);
            break;
        case '0':
            return;
        default:
            handle_error("Invalid choice");
    }
}

/**
 * @brief Converts between length units
 */
void convert_length(void) {
    printf("\n=== LENGTH CONVERSION ===\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("0. Back\n");

    char choice[10];
    get_user_input(choice, sizeof(choice));

    double length;
    printf("Enter length: ");
    if (scanf("%lf", &length) != 1) {
        handle_error("Invalid length input");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    while (getchar() != '\n'); // Clear input buffer

    switch (choice[0]) {
        case '1':
            printf("%.2f meters = %.2f feet\n", length, length * 3.28084);
            break;
        case '2':
            printf("%.2f feet = %.2f meters\n", length, length / 3.28084);
            break;
        case '3':
            printf("%.2f km = %.2f miles\n", length, length * 0.621371);
            break;
        case '4':
            printf("%.2f miles = %.2f km\n", length, length / 0.621371);
            break;
        case '0':
            return;
        default:
            handle_error("Invalid choice");
    }
}

/**
 * @brief Converts between weight units
 */
void convert_weight(void) {
    printf("\n=== WEIGHT CONVERSION ===\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("0. Back\n");

    char choice[10];
    get_user_input(choice, sizeof(choice));

    double weight;
    printf("Enter weight: ");
    if (scanf("%lf", &weight) != 1) {
        handle_error("Invalid weight input");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    while (getchar() != '\n'); // Clear input buffer

    switch (choice[0]) {
        case '1':
            printf("%.2f kg = %.2f lbs\n", weight, weight * 2.20462);
            break;
        case '2':
            printf("%.2f lbs = %.2f kg\n", weight, weight / 2.20462);
            break;
        case '3':
            printf("%.2f g = %.2f oz\n", weight, weight * 0.035274);
            break;
        case '4':
            printf("%.2f oz = %.2f g\n", weight, weight / 0.035274);
            break;
        case '0':
            return;
        default:
            handle_error("Invalid choice");
    }
}

/**
 * @brief Shows calculation history
 */
void show_history(void) {
    printf("\n=== CALCULATION HISTORY ===\n");
    if (calc.history_count == 0) {
        printf("No history available\n");
        return;
    }

    for (int i = 0; i < calc.history_count; i++) {
        char time_str[20];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", 
                localtime(&calc.history[i].timestamp));
        printf("%d: [%s] %s = ", i+1, time_str, calc.history[i].expression);
        
        if (calc.history[i].num_mode == CMPLX_MODE) {
            print_complex_number(calc.history[i].cmplx_result);
        } else {
            printf("%.4f\n", calc.history[i].result);
        }
    }
}

/**
 * @brief Clears calculation history
 */
void clear_history(void) {
    calc.history_count = 0;
    printf("History cleared.\n");
}

/**
 * @brief Shows help information
 */
void show_help(void) {
    printf("\n=== HELP SYSTEM ===\n");
    printf("GENERAL COMMANDS:\n");
    printf("back   - Return to previous menu\n");
    printf("help   - Show this help\n");
    printf("clear  - Clear calculation history\n\n");
    
    printf("SCIENTIFIC FUNCTIONS:\n");
    printf("sin(x), cos(x), tan(x) - Trigonometric\n");
    printf("asin(x), acos(x), atan(x) - Inverse trig\n");
    printf("sinh(x), cosh(x), tanh(x) - Hyperbolic\n");
    printf("log(x) - Base-10 logarithm\n");
    printf("ln(x)  - Natural logarithm\n");
    printf("sqrt(x) - Square root\n");
    printf("exp(x)  - Exponential function\n\n");
    
    printf("PROGRAMMER FUNCTIONS:\n");
    printf("& (AND), | (OR), x (XOR), ~ (NOT)\n");
    printf("<< (left shift), >> (right shift)\n\n");
    
    printf("STATISTICAL FUNCTIONS:\n");
    printf("Mean, median, variance, standard deviation\n");
    printf("Min, max, sum of data sets\n\n");
    
    printf("UNIT CONVERSIONS:\n");
    printf("Temperature: Celsius ↔ Fahrenheit ↔ Kelvin\n");
    printf("Length: Meters ↔ Feet, Kilometers ↔ Miles\n");
    printf("Weight: Kilograms ↔ Pounds, Grams ↔ Ounces\n\n");
    
    printf("GRAPHING:\n");
    printf("Plots functions of x in ASCII art\n");
    printf("Example: sin(x), x^2, exp(-x)\n");
}

/**
 * @brief Toggles between degree and radian modes
 */
void toggle_angle_mode(void) {
    calc.angle_mode = (calc.angle_mode + 1) % 3;
    const char* modes[] = {"DEG", "RAD", "GRAD"};
    printf("Angle mode set to %s\n", modes[calc.angle_mode]);
}

/**
 * @brief Toggles between number bases
 */
void toggle_number_base(void) {
    calc.num_base = (calc.num_base + 1) % 4;
    const char *base_name[] = {"Decimal", "Hexadecimal", "Octal", "Binary"};
    printf("Number base set to %s\n", base_name[calc.num_base]);
}

/**
 * @brief Toggles between real and complex number modes
 */
void toggle_number_mode(void) {
    calc.num_mode = (calc.num_mode == REAL_MODE) ? CMPLX_MODE : REAL_MODE;
    printf("Number mode set to %s\n", 
           calc.num_mode == REAL_MODE ? "REAL" : "COMPLEX");
}

/**
 * @brief Performs memory operations
 */
void memory_operations(void) {
    printf("\n=== MEMORY OPERATIONS ===\n");
    printf("Current memory: ");
    if (calc.num_mode == REAL_MODE) {
        printf("%.4f\n", calc.memory_register);
    } else {
        print_complex_number(calc.cmplx_memory_register);
    }
    printf("1. Store to memory\n");
    printf("2. Recall from memory\n");
    printf("3. Add to memory\n");
    printf("4. Subtract from memory\n");
    printf("5. Clear memory\n");
    printf("0. Back\n");

    char choice[10];
    get_user_input(choice, sizeof(choice));

    switch (choice[0]) {
        case '1': 
            if (calc.num_mode == REAL_MODE) {
                calc.memory_register = calc.last_result;
            } else {
                calc.cmplx_memory_register = calc.last_cmplx_result;
            }
            break;
        case '2': 
            if (calc.num_mode == REAL_MODE) {
                calc.last_result = calc.memory_register;
                printf("Recalled: %.4f\n", calc.last_result);
            } else {
                calc.last_cmplx_result = calc.cmplx_memory_register;
                printf("Recalled: ");
                print_complex_number(calc.last_cmplx_result);
            }
            break;
        case '3': 
            if (calc.num_mode == REAL_MODE) {
                calc.memory_register += calc.last_result;
            } else {
                calc.cmplx_memory_register += calc.last_cmplx_result;
            }
            break;
        case '4': 
            if (calc.num_mode == REAL_MODE) {
                calc.memory_register -= calc.last_result;
            } else {
                calc.cmplx_memory_register -= calc.last_cmplx_result;
            }
            break;
        case '5': 
            if (calc.num_mode == REAL_MODE) {
                calc.memory_register = 0;
            } else {
                calc.cmplx_memory_register = 0 + 0*I;
            }
            break;
        case '0': 
            return;
        default: 
            handle_error("Invalid choice");
    }
    printf("Memory updated: ");
    if (calc.num_mode == REAL_MODE) {
        printf("%.4f\n", calc.memory_register);
    } else {
        print_complex_number(calc.cmplx_memory_register);
    }
}

/**
 * @brief Variable operations menu
 */
void variable_operations() {
    printf("\n=== VARIABLE OPERATIONS ===\n");
    show_variables();
    printf("\n1. Set real variable\n");
    printf("2. Set complex variable\n");
    printf("3. Use in expression\n");
    printf("0. Back\n");
    
    char choice[10];
    get_user_input(choice, sizeof(choice));
    
    switch (choice[0]) {
        case '1': {
            char var_name;
            double value;
            printf("Enter variable name (a-z): ");
            if (scanf(" %c", &var_name) != 1 || !islower(var_name)) {
                handle_error("Invalid variable name");
                break;
            }
            printf("Enter value: ");
            if (scanf("%lf", &value) != 1) {
                handle_error("Invalid value");
                break;
            }
            set_variable(var_name, value);
            break;
        }
        case '2': {
            char var_name;
            double real, imag;
            printf("Enter variable name (a-z): ");
            if (scanf(" %c", &var_name) != 1 || !islower(var_name)) {
                handle_error("Invalid variable name");
                break;
            }
            printf("Enter real part: ");
            if (scanf("%lf", &real) != 1) {
                handle_error("Invalid real part");
                break;
            }
            printf("Enter imaginary part: ");
            if (scanf("%lf", &imag) != 1) {
                handle_error("Invalid imaginary part");
                break;
            }
            set_complex_variable(var_name, real + imag*I);
            break;
        }
        case '3':
            printf("Variables can be used in expressions by their names (a-z)\n");
            printf("Complex variables are automatically handled\n");
            break;
        case '0':
            return;
        default:
            handle_error("Invalid choice");
    }
}

/**
 * @brief Show all variables and their values
 */
void show_variables() {
    printf("\nVariables:\n");
    for (int i = 0; i < MAX_VARS; i++) {
        printf("%c = ", calc.variables[i].name);
        if (calc.variables[i].is_complex) {
            print_complex_number(calc.variables[i].cmplx_value);
        } else {
            printf("%.4f\n", calc.variables[i].value);
        }
    }
}

/**
 * @brief Set a real variable value
 */
void set_variable(char name, double value) {
    if (name < 'a' || name > 'z') {
        handle_error("Invalid variable name");
        return;
    }
    int index = name - 'a';
    calc.variables[index].value = value;
    calc.variables[index].is_complex = false;
    printf("Variable %c set to %.4f\n", name, value);
}

/**
 * @brief Set a complex variable value
 */
void set_complex_variable(char name, cmplx value) {
    if (name < 'a' || name > 'z') {
        handle_error("Invalid variable name");
        return;
    }
    int index = name - 'a';
    calc.variables[index].cmplx_value = value;
    calc.variables[index].is_complex = true;
    printf("Variable %c set to ", name);
    print_complex_number(value);
}

/**
 * @brief Get a real variable value
 */
double get_variable_value(char name) {
    if (name < 'a' || name > 'z') {
        handle_error("Invalid variable name");
        return 0;
    }
    int index = name - 'a';
    if (calc.variables[index].is_complex) {
        handle_error("Variable is complex");
        return 0;
    }
    return calc.variables[index].value;
}

/**
 * @brief Get a complex variable value
 */
cmplx get_complex_variable(char name) {
    if (name < 'a' || name > 'z') {
        handle_error("Invalid variable name");
        return 0 + 0*I;
    }
    int index = name - 'a';
    if (!calc.variables[index].is_complex) {
        return calc.variables[index].value + 0*I;
    }
    return calc.variables[index].cmplx_value;
}

/**
 * @brief Evaluates mathematical expressions
 */
double evaluate_expression(const char *expr) {
    char cleaned_expr[MAX_EXPR_LEN];
    strcpy(cleaned_expr, expr);
    remove_spaces(cleaned_expr);

    // Handle constants and variables
    if (strcmp(cleaned_expr, "pi") == 0) return PI;
    if (strcmp(cleaned_expr, "e") == 0) return EULER;
    if (strcmp(cleaned_expr, "ans") == 0) return calc.last_result;
    
    // Check for single variable
    if (strlen(cleaned_expr) == 1 && islower(cleaned_expr[0])) {
        return get_variable_value(cleaned_expr[0]);
    }

    // Simple two-operand evaluation
    double a, b;
    char op;
    if (sscanf(cleaned_expr, "%lf%c%lf", &a, &op, &b) == 3) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (b == 0) {
                    handle_error("Division by zero");
                    return NAN;
                }
                return a / b;
            case '%': return (int)a % (int)b;
            case '^': return pow(a, b);
            case '&': return (int)a & (int)b;
            case '|': return (int)a | (int)b;
            case 'x': return (int)a ^ (int)b;
            case '<': 
                if (strstr(cleaned_expr, "<<")) 
                    return (int)a << (int)b;
                break;
            case '>': 
                if (strstr(cleaned_expr, ">>")) 
                    return (int)a >> (int)b;
                break;
        }
    }

    // Handle scientific functions
    char func[10];
    double arg;
    if (sscanf(cleaned_expr, "%[^(](%lf)", func, &arg) == 2) {
        // Convert angle if needed
        if (calc.angle_mode == DEG && 
            (strcmp(func, "sin") == 0 || strcmp(func, "cos") == 0 || 
             strcmp(func, "tan") == 0 || strcmp(func, "asin") == 0 ||
             strcmp(func, "acos") == 0 || strcmp(func, "atan") == 0)) {
            arg = arg * PI / 180.0;
        } else if (calc.angle_mode == GRAD && 
            (strcmp(func, "sin") == 0 || strcmp(func, "cos") == 0 || 
             strcmp(func, "tan") == 0 || strcmp(func, "asin") == 0 ||
             strcmp(func, "acos") == 0 || strcmp(func, "atan") == 0)) {
            arg = arg * PI / 200.0;
        }

        if (strcmp(func, "sin") == 0) return sin(arg);
        if (strcmp(func, "cos") == 0) return cos(arg);
        if (strcmp(func, "tan") == 0) return tan(arg);
        if (strcmp(func, "asin") == 0) return asin(arg);
        if (strcmp(func, "acos") == 0) return acos(arg);
        if (strcmp(func, "atan") == 0) return atan(arg);
        if (strcmp(func, "sinh") == 0) return sinh(arg);
        if (strcmp(func, "cosh") == 0) return cosh(arg);
        if (strcmp(func, "tanh") == 0) return tanh(arg);
        if (strcmp(func, "log") == 0) return log10(arg);
        if (strcmp(func, "ln") == 0) return log(arg);
        if (strcmp(func, "sqrt") == 0) return sqrt(arg);
        if (strcmp(func, "exp") == 0) return exp(arg);
    }

    // Handle unary operators
    if (sscanf(cleaned_expr, "%c%lf", &op, &a) == 2) {
        if (op == '~') return ~(int)a;
    }

    handle_error("Invalid expression");
    return NAN;
}

/**
 * @brief Evaluates complex mathematical expressions
 */
cmplx evaluate_complex_expression(const char *expr) {
    char cleaned_expr[MAX_EXPR_LEN];
    strcpy(cleaned_expr, expr);
    remove_spaces(cleaned_expr);

    // Handle constants and variables
    if (strcmp(cleaned_expr, "pi") == 0) return PI + 0*I;
    if (strcmp(cleaned_expr, "e") == 0) return EULER + 0*I;
    if (strcmp(cleaned_expr, "ans") == 0) return calc.last_cmplx_result;
    if (strcmp(cleaned_expr, "i") == 0) return 0 + 1*I;
    
    // Check for single variable
    if (strlen(cleaned_expr) == 1 && islower(cleaned_expr[0])) {
        return get_complex_variable(cleaned_expr[0]);
    }

    // Complex number literal
    double real, imag;
    if (sscanf(cleaned_expr, "%lf+%lfi", &real, &imag) == 2) {
        return real + imag*I;
    }
    if (sscanf(cleaned_expr, "%lf-%lfi", &real, &imag) == 2) {
        return real - imag*I;
    }

    // Simple two-operand evaluation
    cmplx a, b;
    char op;
    if (sscanf(cleaned_expr, "%lf+%lfi%c%lf+%lfi", &real, &imag, &op, &b) == 4) {
        a = real + imag*I;
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (cabs(b) == 0) {
                    handle_error("Division by zero");
                    return NAN + NAN*I;
                }
                return a / b;
            case '^': return cpow(a, b);
        }
    }

    // Handle scientific functions
    char func[10];
    cmplx arg;
    if (sscanf(cleaned_expr, "%[^(](%lf+%lfi)", func, &real, &imag) == 3) {
        arg = real + imag*I;
        
        if (strcmp(func, "sin") == 0) return csin(arg);
        if (strcmp(func, "cos") == 0) return ccos(arg);
        if (strcmp(func, "tan") == 0) return ctan(arg);
        if (strcmp(func, "exp") == 0) return cexp(arg);
        if (strcmp(func, "log") == 0) return clog10(arg);
        if (strcmp(func, "ln") == 0) return clog(arg);
        if (strcmp(func, "sqrt") == 0) return csqrt(arg);
    }

    handle_error("Invalid complex expression");
    return NAN + NAN*I;
}

/**
 * @brief Adds an entry to the calculation history
 */
void add_to_history(const char *expr, double result, cmplx cmplx_result) {
    if (calc.history_count >= MAX_HISTORY) {
        // Shift history down
        for (int i = 0; i < MAX_HISTORY-1; i++) {
            strcpy(calc.history[i].expression, calc.history[i+1].expression);
            calc.history[i].result = calc.history[i+1].result;
            calc.history[i].cmplx_result = calc.history[i+1].cmplx_result;
            calc.history[i].timestamp = calc.history[i+1].timestamp;
            calc.history[i].num_mode = calc.history[i+1].num_mode;
        }
        calc.history_count--;
    }

    strncpy(calc.history[calc.history_count].expression, expr, MAX_EXPR_LEN-1);
    calc.history[calc.history_count].expression[MAX_EXPR_LEN-1] = '\0';
    calc.history[calc.history_count].result = result;
    calc.history[calc.history_count].cmplx_result = cmplx_result;
    calc.history[calc.history_count].timestamp = time(NULL);
    calc.history[calc.history_count].num_mode = calc.num_mode;
    calc.history_count++;
}

/**
 * @brief Prints a result in the appropriate format
 */
void print_result(double result, cmplx cmplx_result) {
    if (calc.num_mode == REAL_MODE) {
        switch (calc.num_base) {
            case DECIMAL:
                printf("Result: %.4f\n", result);
                break;
            case HEX:
                printf("Result: %lX\n", (long)result);
                break;
            case OCTAL:
                printf("Result: %lo\n", (long)result);
                break;
            case BINARY:
                printf("Result: ");
                print_number_in_base(result);
                break;
        }
    } else {
        printf("Result: ");
        print_complex_number(cmplx_result);
    }
}

/**
 * @brief Prints a complex number
 */
void print_complex_number(cmplx num) {
    double real = creal(num);
    double imag = cimag(num);
    
    if (imag == 0) {
        printf("%.4f\n", real);
    } else if (real == 0) {
        printf("%.4fi\n", imag);
    } else {
        printf("%.4f %c %.4fi\n", real, imag < 0 ? '-' : '+', fabs(imag));
    }
}

/**
 * @brief Prints a number in binary format
 */
void print_number_in_base(double num) {
    long n = (long)num;
    for (int i = sizeof(long)*8-1; i >= 0; i--) {
        printf("%ld", (n >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

/**
 * @brief Prints welcome message
 */
void print_welcome(void) {
    printf("\n================================\n");
    printf("   ENHANCED SMART CALCULATOR\n");
    printf("================================\n");
    printf("Features:\n");
    printf("- Basic & Scientific calculations\n");
    printf("- Programmer functions (bitwise, base conversion)\n");
    printf("- Graphing capabilities\n");
    printf("- Statistical calculations\n");
    printf("- Complex number support\n");
    printf("- Variable storage (a-z)\n");
    printf("- Calculation history\n");
    printf("Type 'help' in any mode for assistance\n\n");
}

/**
 * @brief Prints debug information
 */
void print_debug_info(void) {
    printf("\n=== DEBUG INFO ===\n");
    printf("Angle mode: %s\n", 
           calc.angle_mode == DEG ? "DEG" : 
           calc.angle_mode == RAD ? "RAD" : "GRAD");
    printf("Number base: %s\n", 
          calc.num_base == DECIMAL ? "DEC" :
          calc.num_base == HEX ? "HEX" :
          calc.num_base == OCTAL ? "OCT" : "BIN");
    printf("Number mode: %s\n",
          calc.num_mode == REAL_MODE ? "REAL" : "COMPLEX");
    printf("Last result: %.4f\n", calc.last_result);
    printf("Last complex result: ");
    print_complex_number(calc.last_cmplx_result);
    printf("Memory: %.4f\n", calc.memory_register);
    printf("Complex memory: ");
    print_complex_number(calc.cmplx_memory_register);
    printf("History entries: %d\n", calc.history_count);
    printf("Debug mode: %s\n", calc.debug_mode ? "ON" : "OFF");
}

/**
 * @brief Gets user input safely
 */
int get_user_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
    return 0;
}

/**
 * @brief Handles errors with descriptive messages
 */
void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    if (calc.debug_mode) {
        print_debug_info();
    }
}

/**
 * @brief Removes all spaces from a string
 */
void remove_spaces(char* str) {
    char* i = str;
    char* j = str;
    while (*j != '\0') {
        *i = *j++;
        if (*i != ' ') {
            i++;
        }
    }
    *i = '\0';
}

/**
 * @brief Checks if a word is a reserved keyword
 */
bool is_reserved_word(const char* word) {
    const char* reserved[] = {
        "sin", "cos", "tan", "asin", "acos", "atan",
        "sinh", "cosh", "tanh", "log", "ln", "sqrt",
        "exp", "pi", "e", "ans", "i", NULL
    };
    
    for (int i = 0; reserved[i] != NULL; i++) {
        if (strcmp(word, reserved[i]) == 0) {
            return true;
        }
    }
    return false;
}
