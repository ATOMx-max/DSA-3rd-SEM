# Linked List Implementation in C

This project demonstrates the implementation of a **singly linked list**
in C, including basic operations like insertion, deletion, traversal,
and finding the middle element.

------------------------------------------------------------------------

## 📌 Features Implemented

1.  **Create a linked list node**
2.  **Add element from the back**
3.  **Add element from the front**
4.  **Print linked list**
5.  **Find middle element (Tortoise-Hare algorithm)**
6.  **Delete element from back**
7.  **Delete element from front**
8.  **Delete element from any position**
9.  **Count total elements**
10. **Menu-driven program**

------------------------------------------------------------------------

## ⚙️ Functions Explained

### 1. `struct node* create_node()`

-   Creates a new node dynamically using `malloc`.
-   Takes user input for data and initializes `next = NULL`.

### 2. `void add_from_front()`

-   Creates a new node and adds it to the front of the list.
-   Updates `head` to the new node.

### 3. `void add_from_back()`

-   Traverses the linked list to the last node.
-   Adds the new node at the end.

### 4. `void print_link_list()`

-   Traverses and prints all nodes of the list.

### 5. `void middle_value_linklist()`

-   Uses **Tortoise-Hare algorithm** (slow and fast pointers).
-   Finds the middle element efficiently.

### 6. `void delete_from_back()`

-   Traverses to the second-last node.
-   Deletes the last node and frees memory.

### 7. `void delete_from_front()`

-   Updates `head` to the second node.
-   Deletes the first node.

### 8. `void delete_from_anyposiction()`

-   Deletes a node from a given position (by index).
-   Handles special case when position = 1 (front).

### 9. `int linked_list_counter()`

-   Counts total number of nodes in the linked list.

------------------------------------------------------------------------

## ▶️ Example Menu in `main()`

``` c
printf("\n===========Linked List Menu===========\n");
printf("1) Create linked list\n");
printf("2) Add Element from back\n");
printf("3) Add Element from front\n");
printf("4) Print linked list\n");
printf("5) Find Middle element\n");
printf("6) Delete element from back\n");
printf("7) Delete element from front\n");
printf("8) Delete element from any position\n");
printf("9) Total Element in linked list\n");
printf("10) Exit\n");
```

------------------------------------------------------------------------

## 🚀 How to Run

1.  Save the code in a file, e.g., `linked_list.c`.

2.  Compile using:

    ``` bash
    gcc linked_list.c -o linked_list
    ```

3.  Run the program:

    ``` bash
    ./linked_list
    ```

------------------------------------------------------------------------

## 📝 Notes

-   This is a **menu-driven program**.
-   Handles edge cases (empty list, deleting first/last node).
-   Demonstrates dynamic memory allocation with `malloc` and `free`.

------------------------------------------------------------------------

✅ **Author:** Linked List Implementation Example\
📅 **Created for Learning Purposes**
