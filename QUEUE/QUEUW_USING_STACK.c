/*
===============================================================================
Program: Queue Implementation using Two Stacks
Author:  [Your Name]
Date:    [Date]
Language: C
===============================================================================

DESCRIPTION:
------------
This program demonstrates the implementation of a queue using two stacks.
The queue follows the FIFO (First-In-First-Out) principle, but stacks
are LIFO (Last-In-First-Out) structures. By using two stacks, we can
simulate queue operations.

APPROACH:
---------
- `stack1` is used to store new incoming elements.
- When deleting, elements are transferred from `stack1` to `stack2`,
- the front element is removed, and then elements are moved back.

OPERATIONS:
-----------
1. Insert (Enqueue)
2. Delete (Dequeue)
3. Display Queue
4. Exit

===============================================================================
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 10  // Maximum size of each stack

// ------------------------- GLOBAL VARIABLES -------------------------
int stack1[MAX]; // First stack for inserting new elements
int stack2[MAX]; // Second stack used temporarily for deletion
int top1 = -1;   // Top pointer for stack1
int top2 = -1;   // Top pointer for stack2

// ------------------------- UTILITY FUNCTIONS -------------------------

/*
 * Function: is_empty
 * ------------------
 * Checks if a stack is empty.
 *
 * top: index of the top element in the stack
 *
 * returns: true if stack is empty, false otherwise
 */
bool is_empty(int top) {
    return top == -1;
}

/*
 * Function: is_full
 * -----------------
 * Checks if a stack is full.
 *
 * top: index of the top element in the stack
 *
 * returns: true if stack is full, false otherwise
 */
bool is_full(int top) {
    return top == MAX - 1;
}

// ------------------------- STACK OPERATIONS -------------------------

/*
 * Function: insert
 * ----------------
 * Pushes a new element into the specified stack.
 *
 * stack: array representing the stack
 * top: pointer to the stack's top index
 */
void insert(int stack[MAX], int *top) {
    int element;
    if (is_full(*top)) {
        printf("ERROR: OVERFLOW\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d", &element);

    (*top)++;
    stack[*top] = element;
    printf("Element inserted successfully.\n");
}

/*
 * Function: pop
 * -------------
 * Removes the top element from the specified stack.
 *
 * stack: array representing the stack
 * top: pointer to the stack's top index
 */
void pop(int stack[MAX], int *top) {
    if (is_empty(*top)) {
        printf("ERROR: UNDERFLOW\n");
        return;
    }
    (*top)--; // Simply decrease top, discarding the element
    printf("Element removed successfully.\n");
}

// ------------------------- QUEUE OPERATIONS -------------------------

/*
 * Function: pop_in_QUE
 * --------------------
 * Deletes an element from the front of the queue.
 * Achieved by transferring elements from stack1 to stack2,
 * popping the top of stack2, then moving elements back.
 */
void pop_in_QUE() {
    // Step 1: Transfer elements from stack1 to stack2
    for (int i = top1; i >= 0; i--) {
        stack2[++top2] = stack1[i];
    }
    top1 = -1; // Clear stack1

    // Step 2: Remove the front element of the queue
    pop(stack2, &top2);

    // Step 3: Transfer elements back from stack2 to stack1
    for (int i = top2; i >= 0; i--) {
        stack1[++top1] = stack2[i];
    }
    top2 = -1; // Clear stack2
}

/*
 * Function: display
 * -----------------
 * Displays the current elements in the queue.
 */
void display() {
    if (is_empty(top1)) {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("QUEUE: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d\t", stack1[i]);
    }
    printf("\n");
}

// ------------------------- MAIN FUNCTION -------------------------

int main() {
    int choice;
    while (1) {
        // Display menu
        printf("\n--- MENU ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform selected operation
        switch (choice) {
            case 1:
                insert(stack1, &top1);
                break;
            case 2:
                pop_in_QUE();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
