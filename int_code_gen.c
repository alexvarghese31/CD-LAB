#include <stdio.h>
#include <string.h>

int main() {
    char expr[30];
    char result;
    char op1, op2;
    char temp = 't'; // We will use a single temporary variable 't'
    
    int found_mul = 0;
    int found_add = 0;
    int mul_pos = -1;
    int add_pos = -1;

    printf("Enter a simple expression (e.g., a=b+c*d or a=b*c+d): ");
    scanf("%s", expr);

    // Get the result variable (e.g., 'a' from "a=...")
    result = expr[0];

    // --- First Pass: Find the positions of operators ---
    // We loop through the string once to find what we're working with.
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '*') {
            found_mul = 1;
            mul_pos = i;
        }
        if (expr[i] == '+') {
            found_add = 1;
            add_pos = i;
        }
    }

    printf("\nIntermediate Code (Three-Address Code):\n");

    // --- Second Pass: Generate code based on precedence ---

    // Case 1: Both '+' and '*' exist
    // We must do '*' first!
    if (found_mul && found_add) {
        // Step 1: Generate code for the '*' operation
        op1 = expr[mul_pos - 1];
        op2 = expr[mul_pos + 1];
        printf("%c = %c * %c\n", temp, op1, op2);

        // Step 2: Generate code for the '+' operation,
        // using the temporary variable 't' as an operand.
        if (mul_pos < add_pos) {
            // Case: a=b*c+d. The '*' was on the left.
            // 't' becomes the left operand for '+'
            op1 = temp;
            op2 = expr[add_pos + 1];
        } else {
            // Case: a=b+c*d. The '*' was on the right.
            // 't' becomes the right operand for '+'
            op1 = expr[add_pos - 1];
            op2 = temp;
        }
        // Step 3: Assign the result of '+' to the final variable
        printf("%c = %c + %c\n", result, op1, op2);
    }
    // Case 2: Only '*' exists (e.g., a=b*c)
    else if (found_mul) {
        op1 = expr[mul_pos - 1];
        op2 = expr[mul_pos + 1];
        printf("%c = %c * %c\n", result, op1, op2);
    }
    // Case 3: Only '+' exists (e.g., a=b+c)
    else if (found_add) {
        op1 = expr[add_pos - 1];
        op2 = expr[add_pos + 1];
        printf("%c = %c + %c\n", result, op1, op2);
    }
    // Case 4: No operators (e.g., a=b)
    else {
        op1 = expr[2]; // Get the character after '='
        printf("%c = %c\n", result, op1);
    }

    return 0;
}
