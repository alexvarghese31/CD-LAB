#include <stdio.h>

// Define the number of states in the NFA
#define NUM_STATES 5

/**
 * @brief Recursively finds the epsilon closure of a given state using DFS.
 * @param state The current state we are visiting.
 * @param closure_set An array (acting as a set) to store the result.
 * @param epsilon_transitions The NFA's transition table (adjacency matrix).
 */
void find_epsilon_closure(int state, int closure_set[NUM_STATES], int transitions[NUM_STATES][NUM_STATES]) {

    // 1. Add the current state to its own closure
    closure_set[state] = 1;

    // 2. Find all states reachable from 'state' via epsilon transitions
    for (int i = 0; i < NUM_STATES; i++) {

        // Check if an epsilon transition exists (transitions[state][i] == 1)
        // AND if we have not already visited that state (closure_set[i] == 0)
        if (transitions[state][i] == 1 && closure_set[i] == 0) {

            // 3. Recursively find the closure of the new state
            find_epsilon_closure(i, closure_set, transitions);
        }
    }
}

int main() {

    // Define the NFA's epsilon transitions (1 = epsilon move, 0 = no move)
    // This will be entered by the user at runtime.
    int epsilon_transitions[NUM_STATES][NUM_STATES];

    printf("Enter the epsilon transitions for %d states (1 for yes, 0 for no):\n", NUM_STATES);

    // Loop to get transitions from the user
    for (int i = 0; i < NUM_STATES; i++) {
        for (int j = 0; j < NUM_STATES; j++) {
            printf("  Transition from state %d to state %d: ", i, j);
            scanf("%d", &epsilon_transitions[i][j]);
        }
    }

    // Optional: Print the entered table to verify
    printf("\n--- Transition Table Entered ---\n");
    for (int i = 0; i < NUM_STATES; i++) {
        printf("  ");
        for (int j = 0; j < NUM_STATES; j++) {
            printf("%d ", epsilon_transitions[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------------\n\n");

    int start_state;
    printf("Enter the state to find epsilon closure for (0 to %d): ", NUM_STATES - 1);
    scanf("%d", &start_state);

    if (start_state < 0 || start_state >= NUM_STATES) {
        printf("Invalid state.\n");
        return 1; // Exit with an error
    }

    // Array to store the closure set.
    // 0 = not in set, 1 = in set.
    // We initialize it to all zeros.
    int closure_set[NUM_STATES] = {0};

    // Find the epsilon closure starting from the user's state
    find_epsilon_closure(start_state, closure_set, epsilon_transitions);

    // Print the resulting set
    printf("\nEpsilon closure of state %d is: { ", start_state);
    for (int i = 0; i < NUM_STATES; i++) {
        if (closure_set[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");

    return 0;
}
