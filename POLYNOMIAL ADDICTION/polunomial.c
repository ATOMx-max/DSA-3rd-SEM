#include<stdio.h>
#include<stdlib.h>

struct node {
    int cof;
    int exp;
    struct node *next;
};

struct node *p1 = NULL;
struct node *p2 = NULL;
struct node *result = NULL;

// Create a new node
struct node *create(int cof, int exp) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("ERROR\n");
        exit(0);
    }
    temp->cof = cof;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

// Insert a term into the polynomial in descending order of exponent
void polynomial(struct node **head, int cof, int exp) {
    struct node *now = *head;
    struct node *prev = NULL;
    struct node *cur = create(cof, exp);

    if (*head == NULL) {
        *head = cur;
        return;
    }

    while (now != NULL && exp < now->exp) {
        prev = now;
        now = now->next;
    }

    if (now == *head) { // Insert at beginning
        cur->next = *head;
        *head = cur;
    } else if (now == NULL) { // Insert at end
        prev->next = cur;
    } else { // Insert in middle
        cur->next = now;
        prev->next = cur;
    }
}

// Display a polynomial
void display(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp != NULL) {
        if (temp != head && temp->cof > 0) printf("+");
        printf("%dX^%d", temp->cof, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
void add() {
    struct node *tp1 = p1;
    struct node *tp2 = p2;

    while (tp1 != NULL && tp2 != NULL) {
        if (tp1->exp > tp2->exp) {
            polynomial(&result, tp1->cof, tp1->exp);
            tp1 = tp1->next;
        } else if (tp2->exp > tp1->exp) {
            polynomial(&result, tp2->cof, tp2->exp);
            tp2 = tp2->next;
        } else { // Exponents equal
            polynomial(&result, tp1->cof + tp2->cof, tp1->exp);
            tp1 = tp1->next;
            tp2 = tp2->next;
        }
    }

    while (tp1 != NULL) {
        polynomial(&result, tp1->cof, tp1->exp);
        tp1 = tp1->next;
    }
    while (tp2 != NULL) {
        polynomial(&result, tp2->cof, tp2->exp);
        tp2 = tp2->next;
    }
}

// Free the memory of a polynomial
void freeList(struct node **head) {
    struct node *temp = NULL;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    int term1, term2, choice = 1;

    do {
        printf("Enter total terms of polynomial 1 and 2: ");
        scanf("%d %d", &term1, &term2);

        printf("Enter Polynomial 1:\n");
        for (int i = 0; i < term1; i++) {
            int cof, exp;
            printf("Term %d Coefficient and Exponent: ", i + 1);
            scanf("%d %d", &cof, &exp);
            polynomial(&p1, cof, exp);
        }

        printf("Enter Polynomial 2:\n");
        for (int i = 0; i < term2; i++) {
            int cof, exp;
            printf("Term %d Coefficient and Exponent: ", i + 1);
            scanf("%d %d", &cof, &exp);
            polynomial(&p2, cof, exp);
        }

        printf("Polynomial 1:\n");
        display(p1);
        printf("Polynomial 2:\n");
        display(p2);

        add();

        printf("Sum:\n");
        display(result);

        printf("\nWant to add more polynomials? (Yes=1 / No=Any key): ");
        scanf("%d", &choice);

        if (choice == 1) {
            freeList(&p1);
            freeList(&p2);
            freeList(&result);
        }

    } while (choice == 1);

    printf("\nThank you...\n");
    return 0;
}