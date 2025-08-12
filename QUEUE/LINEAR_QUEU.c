// Linear Queue Implementation in C
// Author: [Souvik Sarkar]
// Description: This program implements a linear queue using an array with basic operations: 
// Insert (enqueue), Pop (dequeue), Peek, Display, and Exit.

#include <stdio.h>
#include <stdbool.h>

#define MAX 10  // Maximum size of the queue

// Global variables for the queue and pointers
int q[MAX];
int front = -1, rear = -1; // front points before the first element, rear points to the last element

// Function to check if the queue is full
bool is_full() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
bool is_empty() {
    if (front == rear) {   // If both are equal, queue has no elements
        rear = -1;         // Reset rear pointer
        front = -1;        // Reset front pointer
        return 1;          // Queue is empty
    }
    else return 0;
}

// Function to insert an element into the queue (enqueue)
void insert() {
    int item;
    if (is_full()) {   // Overflow condition
        printf("ERROR: Overflow\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &item);
    q[++rear] = item;  // Move rear ahead and insert
    printf("WORK DONE\n");
}

// Function to remove an element from the queue (dequeue)
void pop() {
    if (is_empty()) {  // Underflow condition
        printf("ERROR: Underflow\n");
        return;
    }
    front++; // Move front pointer to effectively remove the element
}

// Function to display all elements in the queue
void display() {
    if (is_empty()) { // If empty, nothing to display
        printf("QUEUE EMPTY\n");
        return;
    }
    printf("QUEUE is: ");
    for (int i = front + 1; i <= rear; i++) {
        printf("%d ", q[i]); // Print elements from front+1 to rear
    }
    printf("\n");
}

// Function to peek at the front element of the queue
void peek() {
    if (is_empty()) {
        printf("NO ELEMENT PRESENT\n");
        return;
    }
    printf("PEEK ELEMENT IS: %d\n", q[front + 1]);
}

// Main function to run menu-driven program
int main() {
    int select = 0;

    // Display menu
    printf("\t***********************************************************\n");
    printf("\t1) INSERT\n\t2) POP\n\t3) PEEK\n\t4) DISPLAY\n\t5) EXIT\n");
    printf("\t***********************************************************\n");

    // Loop until the user selects Exit (5)
    while (select != 5) {
        printf("ENTER: ");
        scanf("%d", &select);
        switch (select) {
            case 1: insert(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("THANK YOU.\n"); break;
            default: printf("Enter between (1-5)\n");
        }
    }
    return 0;
}
