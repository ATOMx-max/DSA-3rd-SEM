// Program: Circular Queue Implementation in C
// Author: [Souvik Sarkar]
// Description: This program demonstrates a circular queue using an array.
//              It supports insertion, deletion (pop), peeking at the front element,
//              and displaying all elements in the queue.

#include <stdio.h>
#include <stdbool.h>

#define MAX 10 // Maximum size of the queue array

// Queue array
int q[MAX];

// 'front' points to the position before the first element
// 'rear' points to the last inserted element
int front = 0, rear = 0;

// Function to check if the queue is full
bool is_full() {
    // Condition: next position of rear == front means queue is full
    return (rear + 1) % MAX == front;
}

// Function to check if the queue is empty
bool is_empty() {
    // Condition: front and rear being equal means queue is empty
    return front == rear;
}

// Function to insert an element into the circular queue
void insert() {
    int item;

    // Check for overflow
    if (is_full()) {
        printf("ERROR: Overflow - Queue is full\n");
        return;
    }

    // Take element input from user
    printf("Enter the element to insert: ");
    scanf("%d", &item);

    // Move rear to the next position (circular increment)
    rear = (rear + 1) % MAX;

    // Place the item in the queue
    q[rear] = item;

    printf("WORK DONE - %d inserted\n", item);
}

// Function to remove an element from the circular queue
void pop() {
    // Check for underflow
    if (is_empty()) {
        printf("ERROR: Underflow - Queue is empty\n");
        return;
    }

    // Move front to the next position (circular increment)
    front = (front + 1) % MAX;

    // Display the removed element
    printf("Removed element: %d\n", q[front]);
}

// Function to display the elements in the queue
void display() {
    // Check if the queue is empty
    if (is_empty()) {
        printf("QUEUE EMPTY\n");
        return;
    }

    printf("QUEUE is: ");

    // Print elements from front+1 to rear, handling wrap-around
    int i = (front + 1) % MAX;
    while (i != (rear + 1) % MAX) {
        printf("%d ", q[i]);
        i = (i + 1) % MAX; // Move to next position in a circular manner
    }

    printf("\n");
}

// Function to view the element at the front of the queue
void peek() {
    if (is_empty()) {
        printf("NO ELEMENT PRESENT\n");
        return;
    }

    // Peek is the element just after 'front'
    printf("PEEK ELEMENT IS: %d\n", q[(front + 1) % MAX]);
}

// Main function - Menu driven
int main() {
    int select = 0;

    printf("\t**************\n");
    printf("\tCircular Queue Menu\n");
    printf("\t1) INSERT\n\t2) POP\n\t3) PEEK\n\t4) DISPLAY\n\t5) EXIT\n");
    printf("\t**************\n");

    // Run the menu until the user selects Exit
    while (select != 5) {
        printf("ENTER: ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                insert();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("THANK YOU.\n");
                break;
            default:
                printf("Enter a valid choice between (1-5)\n");
        }
    }

    return 0;
}
