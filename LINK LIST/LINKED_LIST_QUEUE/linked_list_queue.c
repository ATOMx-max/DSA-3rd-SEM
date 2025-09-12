//LINKED LIST USING QUEUE
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node 
{
    int val;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

struct node *create()
{
    int value;
    struct node * current=(struct node *)malloc(sizeof(struct node));
    if (current==NULL)
    {
        printf("Mamory is full..\n");
        exit(0);
    }
    printf("Enter the value:");
    scanf("%d",&value);
    current->val=value;
    current->next=NULL;
    return current;
}

void insert(struct node **rear,struct node **front)//pointer to a pointer or refference
//we have to pass address
{
    if(*rear==NULL)
    {
        *rear=create();
        //front pointing the first element 
        *front=*rear;
    }
    else
    {
    struct node *temp=create();
    (*rear)->next=temp;
    *rear=temp;
    }
}

void display(struct node *front)
{
    if(front==NULL)
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    while(front!=NULL)
    {
        printf("%d\t",front->val);
        front=front->next;
    }
    printf("\n");
}
//imp and little complex
void dequeue(struct node **front,struct node **rear)
{
    struct node *temp=*front;
    if(*front==NULL)
    {
        printf("QUEUE IS EMPTY\n");
        *rear=NULL;
    }
    else
    {
        *front=(*front)->next;
        //for one node now front =NULL but rear unchanged thats why have to change it
        //if not check cause dagling pointer
        if(*front==NULL)
        {
            *rear=NULL;
        }
        free(temp);
    }
}
int main() {
    int cho;
    printf("\n=========== Linked List Menu ===========\n");
    printf("1) Insert\n");
    printf("2) Display\n");
    printf("3) Dequeue\n");
    printf("5) Exite\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1: insert(&rear,&front);break;
            case 2: display(front);break;
            case 3: dequeue(&front,&rear);break;
            case 5: printf("Exiting..\n"); exit(0);
            default: printf("Please enter correct input\n");
        }
    }
    return 0;
}

