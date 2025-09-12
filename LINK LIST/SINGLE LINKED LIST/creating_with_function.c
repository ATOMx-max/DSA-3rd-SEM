#include<stdio.h>
#include<stdlib.h>
//shorted inserction and reverse and also just print the rev
struct node
{
    int val;
    struct node *next;
};
//define head globaly
struct node *head=NULL;
//int counter=0;
//crating function to create 1 node
struct node* create_node()
{   //it is better to declear the head globaly
    int item;
    struct node *head1=(struct node*)malloc(sizeof(struct node));//node is created
    /*if(head==NULL)//fixed it
    {
        head=head1;
    }*/
    printf("Enter the element:");
    scanf("%d",&item);
    head1->val=item;
    head1->next=NULL;
    return head1;//return adress of node
}
//add element from front
void add_from_front()
{
    struct node* temp=head;//no change in head
    if(temp==NULL)
    {
        printf("Link List is empty\n");
        //temp=create_node();//creating first node
    }
    else
    {
        temp=create_node();//node 2
        temp->next=head;//next->node 1 address
        //making the node 2 node 1
        head=temp;
    }
}
//adding node from back
void add_from_back()
{
    struct node* temp=head;//no change in head
    if(temp==NULL)
    {
        printf("Link List is empty.\n");
        //temp=create_node();//creating first node
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;//next->node 1 address
        }
        struct node *newnode=create_node();
        temp->next=newnode;
    }
}
//printing of link list
void print_link_list()
{
    struct node* temp=head;//no change in head
    if(temp==NULL)
    {
        printf("Link List is empty.\n");
        //temp=create_node();//creating first node
    }
    printf("Element of link list:");
    while(temp!=NULL)
    {
        printf("%3d\t",temp->val);//printing each element of link list
        temp=temp->next;//itterating the hole link list
    }
    printf("\n");   
}
//finding middle element using two pointer
//Tortoise–Hare algorithm
void middle_value_linklist()
{
    struct node *temp=head;//backup
    struct node *fast=temp,*slow=temp;
    while(fast!=NULL && fast->next!=NULL)//as condiction are diffrent for odd and even
    {
        fast=fast->next->next;//fast move 2 step
        slow=slow->next;//move 1 setp
    }
    printf("The middle element is:%d\n",slow->val);
}
//deleteing element from back of the linked list
void delete_from_back()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Link list is empty");
        return;
    }
    else{
        if (temp->next==NULL)
        {
            free(temp);
            head=NULL;
            printf("Last node is deleted\n");
            return;
        }
        while(temp->next->next!=NULL)//imp logic
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        printf("Last node is deleted\n");
    }
}
//deleting element from the front of  the linked list
void delete_from_front()
{
    struct node *temp=head;
    if (head==NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    head=temp->next; //storing the adderes of next node as head
    free(temp);
    printf("Element delete from front succesfully..\n");
}
//total number of element in linked list
int linked_list_counter()
{
    int c=1;
    if(head==NULL)
    {
        return 0;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
//delete from any posiction
void delete_from_anyposiction()
{
    struct node *temp=head;
    if (head==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    print_link_list();
    printf("Enter the posiction of the element to delete:");
    int pos;
    scanf("%d",&pos);
    int length=linked_list_counter();
    if (pos>1 && pos<=length)
    {
        struct node *prev=NULL;
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;//linking with next node also delinking
        printf("%d is deleted from position %d\n", temp->val, pos);
        free(temp);
    }
    else if(pos==1)
    {
        delete_from_front();
    }
    else{
        printf("Please enter valid posiction.\n");
    }
}

void inset_short()
{
    if (head==NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp=head;
    //struct node *prv;
    struct node *create=create_node();
    if(create->val<head->val)//at first node
    {
        create->next=temp;
        head=create;
        return;
    }
    while(temp->next!=NULL && create->val>temp->next->val)
    {
        temp=temp->next;
    }
    create->next=temp->next;
    temp->next=create;
}


#include <stdio.h>
#include <stdlib.h>

int main() {
    int cho;

    do {
        printf("\n=========== Linked List Menu ===========\n");
        printf("1) Create linked list\n");
        printf("2) Add element at back\n");
        printf("3) Add element at front\n");
        printf("4) Print linked list\n");
        printf("5) Find middle element\n");
        printf("6) Delete element from back\n");
        printf("7) Delete element from front\n");
        printf("8) Delete element from any position\n");
        printf("9) Total elements in linked list\n");
        printf("10)Enter element in shorted way\n");
        printf("11) Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1: head = create_node(); break;
            case 2: add_from_back(); break;
            case 3: add_from_front(); break;
            case 4: print_link_list(); break;
            case 5: middle_value_linklist(); break;
            case 6: delete_from_back(); break;
            case 7: delete_from_front(); break;
            case 8: delete_from_anyposiction(); break;
            case 9: printf("Total elements in linked list: %d\n", linked_list_counter()); break;
            case 10:inset_short();break;
            case 11: printf("Exiting...\n"); exit(0);
            default: printf("Please enter a valid option (1–10).\n");
        }

    } while (cho != 11);

    return 0;
}
