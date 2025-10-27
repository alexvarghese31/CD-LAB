#include <stdio.h>
#include <string.h>

int main() {
    char input[20], stack[20];
    int top = 0, i = 0; // 'top' is the index of the last element

    // Initialize stack with $
    stack[0] = '$';

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    // Continue parsing
    while (1) {
        // Print current stack and remaining input
        for (int j = 0; j <= top; j++)
            printf("%c", stack[j]);
        printf("\t\t%s\t\t", &input[i]);

        // --- REDUCE PHASE ---
        // Check for longest rules first

        // Rule 1: E+E → E
        if (top >= 2 && stack[top] == 'E' &&
            stack[top - 1] == '+' && stack[top - 2] == 'E') {
            top -= 2;
            stack[top] = 'E';
            printf("Reduce E+E→E\n");
        }

        // Rule 2: E*E → E
        else if (top >= 2 && stack[top] == 'E' &&
                 stack[top - 1] == '*' && stack[top - 2] == 'E') {
            top -= 2;
            stack[top] = 'E';
            printf("Reduce E*E→E\n");
        }

        // Rule 3: i → E
        else if (stack[top] == 'i') {
            stack[top] = 'E';
            printf("Reduce i→E\n");
        }

        // --- ACCEPT CONDITION ---
        else if (stack[top] == 'E' && stack[top - 1] == '$' && input[i] == '$') {
            printf("Accept\n");
            break;
        }

        // --- SHIFT OPERATION ---
        else if (input[i] != '\0') {
            stack[++top] = input[i++];
            printf("Shift\n");
        }

        // --- ERROR CONDITION ---
        else {
            printf("Error: Invalid input\n");
            break;
        }
    }

    return 0;
}
