# Algorithm for Queue using Linked List

## Step 1: Start

## Step 2: Define structure of node

-   Each node contains:
    -   `val` (integer data)
    -   `next` (pointer to next node)

## Step 3: Initialize

-   `front = NULL`
-   `rear = NULL`

## Step 4: Create Function

-   Input a value from user
-   Allocate memory for new node
-   Assign value and set `next = NULL`
-   Return pointer to new node

## Step 5: Insert Function

-   If `rear == NULL`:
    -   Create new node
    -   Set both `front` and `rear` to new node
-   Else:
    -   Create new node
    -   Link `rear->next` to new node
    -   Update `rear` to point to new node

## Step 6: Display Function

-   If `front == NULL`:
    -   Print "QUEUE IS EMPTY"
-   Else:
    -   Traverse from `front` to `rear` and print values

## Step 7: Dequeue Function

-   If `front == NULL`:
    -   Print "QUEUE IS EMPTY"
    -   Set `rear = NULL`
-   Else:
    -   Store `front` in `temp`
    -   Move `front` to `front->next`
    -   If `front == NULL`, set `rear = NULL`
    -   Free memory of `temp`

## Step 8: Main Menu

-   Repeat infinitely:
    -   1 → Insert element
    -   2 → Display queue
    -   3 → Dequeue element
    -   5 → Exit

## Step 9: Stop
