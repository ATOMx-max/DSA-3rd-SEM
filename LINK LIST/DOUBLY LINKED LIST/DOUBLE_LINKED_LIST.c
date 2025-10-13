#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    struct node *prv;
    int val;
    struct node *next;
};
struct node *head=NULL;
struct node *creat_node()
{
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Mamory is Full\n");
        exit(0);
    }
    int value;
    printf("Enter the value:");
    scanf("%d",&value);
    head->val=value;
    head->prv=NULL;
    head->next=NULL;
    return head;
}
struct node *insert_front(struct node *head)
{
    struct node *temp=creat_node();
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    temp->next=head;
    head->prv=temp;
    head=temp;
    return head;
}

void display(struct node * head)
{
    if(head==NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
        return;
    }
    while(head!=NULL)
    {
        printf("%d\t",head->val);
        head=head->next;
    }
    printf("\n");
}
struct node * insert_back(struct node *head)
{
    struct node * create=creat_node();
    struct node * temp=head;
    if(temp==NULL)
    {
        return create;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=create;
    create->prv=temp;
    return head;
}
int main() {
    int cho;
    printf("\n=========== Linked List Menu ===========\n");
    printf("1) Insert from front\n");
    printf("2) Insert from back\n");
    printf("4) Display\n");
    printf("5) Exite\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1: head=insert_front(head);break;
            case 2: head=insert_back(head);break;
            case 3: head=insert_middle(head);break;
            case 4: display(head);break;
            case 5: printf("Exiting..\n"); exit(0);
            default: printf("Please enter correct input\n");
        }
    }
    return 0;
}