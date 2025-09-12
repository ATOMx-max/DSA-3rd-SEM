//creating a link list of two node
//single link list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;//self reference pointer
};
//manualy
int main()
{   //if head is null link list is empty;
    //head:contain the address of the first node;
    //head is a pointer of same struct
    struct node *head=(struct node *)malloc(sizeof(struct node));//node 1
    //first allocate a single block and store the addres of the first node/block in head.
    //block contain val and next
    struct node *temp=head;//store the fist node address 
    //link node1 with node2
    temp->next=(struct node *)malloc(sizeof(struct node));//create node 2 and store the address in node1.next
    temp->next->next=NULL;//last node;
    //inserting value
    head->val=90;//value of node 1
    head->next->val=100;//value of node 2
    printf("node 1 value:%d\n",head->val);
    printf("node 2 value:%d\n",head->next->val);
    return 0;
}