#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
struct Node {
    int val;
    struct Node *next;
};
struct Node *top;
bool is_empty(struct Node *top)
{
    if(top==NULL)return 1;
    return 0;
}

//this function create a node
//check the node is created or not 
//if yes then take input of value and assine it in the current->val and current->next=NULL
struct Node * create_node()
{
    struct Node *current;
    current=(struct Node *)malloc(sizeof(struct Node));
    if (current==NULL)
    {
        printf("Mamory is full..\n");
        exit(0);
    }
    int val;
    printf("Enter the value:");
    scanf("%d",&val);
    current->val=val;
    current->next=NULL;
    return current;
}
//insert element
//if stack is empty then it only call create node function
//if not then it call create node function and store it in temp
//then change temp->next to top and cange the top to temp address
struct Node * insert(struct Node *stack_top)
{
    //in stack fist in fist out 
    //so insert from the front
    if(is_empty(stack_top))
    {
        stack_top=create_node();
        return stack_top;
    }
    struct Node *temp;
    temp=create_node();
    temp->next=stack_top;
    stack_top=temp;
    return stack_top;

}
//display the element without effecting the data
void display(struct Node *stack_top)
{
    if(is_empty(stack_top))
    {
        printf("Stack is empty\n");return;
    }
    struct Node * temp=stack_top;
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
//display using reccursion
void rec_display(struct Node *stack_top)
{
    if (stack_top == NULL)
    {
        return;
    }
    printf("%d\t",stack_top->val);
    rec_display(stack_top->next);
}

struct Node * pop(struct Node * stack_top)
{
    if(is_empty(stack_top))
    {
        printf("stack is empty");
        return stack_top;
    }
    struct Node * temp=stack_top;
    //it also for 1 node
    stack_top=temp->next;
    free(temp);
    return stack_top;
}
int peek(struct Node *stack_top)
{
    if(is_empty(stack_top))
    {
        printf("stack  is empty.\n");
        return INT_MIN;//return int value
    }
    int value=stack_top->val;
    return value;
}
int main() {
    int cho;
    printf("\n=========== Linked List Menu ===========\n");
    printf("1) Insert\n");
    printf("2) Display\n");
    printf("3) POP\n");
    printf("4) PEEK\n");
    printf("5) Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1: top=insert(top); break;
            case 2: display(top); break;
            case 3: top=pop(top); break;
            case 4:printf("Peeked value is:%d\n",peek(top)); break;
            case 5: printf("Exiting..\n"); exit(0);
            default: printf("Please enter correct input\n");
        }
    }
    return 0;
}