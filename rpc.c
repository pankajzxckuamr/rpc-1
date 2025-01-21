#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_EXP_SIZE 100

// Stack structure
float calc_stack[MAX_STACK_SIZE];  
int top_index = -1;                

// Function to check if the stack is empty
int stack_is_empty(void) {
    return (top_index < 0);  
}

// Function to check if the stack is full
int stack_is_full(void) {
    return (top_index >= MAX_STACK_SIZE - 1);  
}

// Function to push a number onto the stack
void stack_push(float value) {
    if (!stack_is_full()) {  
        top_index++;  
        calc_stack[top_index] = value;  
    } else {
        printf("Error: Stack overflow!\n");
    }
}

// Function to pop a number from the stack
float stack_pop(void) {
    if (!stack_is_empty()) {
        float popped_value = calc_stack[top_index];  
        top_index--;  
        return popped_value;
    } else {
        printf("Error: Stack underflow!\n");
        return 0;
    }
}

// Function to perform addition
float add(float num1, float num2) {
    return num1 + num2;
}

// Function to perform subtraction
float subtract(float num1, float num2) {
    return num1 - num2;
}


// Function to perform multiplication
float multiply(float num1, float num2) {
    return num1 * num2;
}

// Function to perform division
float divide(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero!\n");
        return 0; 
    }
}


// Convert character to a digit
int convert_char_to_digit(char character) {
    if (isdigit(character)) {
        return character - '0';  // Convert char to corresponding digit
    }
    return -1;  // Return -1 if it's not a digit
}

// Main function to process the RPN expression
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        return 1;
    }

    // Process each argument as part of the RPN expression
    for (int i = 1; i < argc; i++) {
        char *current_arg = argv[i];

        if (isdigit(current_arg[0])) {
            // If the argument is a number, push it onto the stack
            float number = atof(current_arg);  
            stack_push(number);
        } else if (strcmp(current_arg, "+") == 0) {
            // Perform addition
            float operand2 = stack_pop();
            float operand1 = stack_pop();
            stack_push(add(operand1, operand2));
        } else if (strcmp(current_arg, "-") == 0) {
            // Perform subtraction
            float operand2 = stack_pop();
            float operand1 = stack_pop();
            stack_push(subtract(operand1, operand2));
        } else if (strcmp(current_arg, "*") == 0) {
            // Perform multiplication
            float operand2 = stack_pop();
            float operand1 = stack_pop();
            stack_push(multiply(operand1, operand2));
        } else if (strcmp(current_arg, "/") == 0) {
            // Perform subtraction
            float operand2 = stack_pop();
            float operand1 = stack_pop();
            stack_push(divide(operand1, operand2));
        }  else {
            printf("Error: Unknown operator: %s\n", current_arg);
        }
    }

    // The final result should be the only element left in the stack
    if (!stack_is_empty()) {
        printf("Result: %.2f\n", stack_pop());
    } else {
        printf("Error: No result found.\n");
    }

    return 0;
}
