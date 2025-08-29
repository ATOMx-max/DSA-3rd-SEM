#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
//define head globaly
struct node *head=NULL;
//crating function to create 1 node
struct node* create_node()
{   //it is better to declear the head globaly
    int item;
    struct node *head1=(struct node*)malloc(sizeof(struct node));//node is created
    if(head==NULL)//fixed it
    {
        head=head1;
    }
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
        temp=create_node();//node 2
        if(head->next==NULL)
        {
            head->next=temp;//next->node 1 address
        }
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


int main()
{
    head=create_node();//creating first node
    printf("Add node in a link list from back:\n");
    add_from_back();
    printf("Add node from front:\n");
    add_from_front();
    print_link_list();
    //calling middle element function
    middle_value_linklist();
    return 0;
}