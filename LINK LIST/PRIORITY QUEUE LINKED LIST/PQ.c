#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * prev;
    int data;
    int pri;
    struct node *next;
};
struct node* head;
struct node * create()
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("FAIL\n");
        exit(0);
    }
    int data,pri;
    printf("Enter data:");
    scanf("%d",&data);
    temp->data=data;
    printf("Enter priority:");
    scanf("%d",&pri);
    temp->pri=pri;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void ineque()
{
    struct node * temp=head;
    struct node * curr=create();
    if(head==NULL)//empty condiction
    {
        head=curr;
        return;
    }
    if (curr->pri<=head->pri)//fist node
    {
        curr->next=head;
        head->prev=curr;
        head=curr;
        return;
    }
    while(temp->next!=NULL && curr->pri>=temp->next->pri)//start from second node
    {
        temp=temp->next;
    }
    
    if(temp->next==NULL)//last node
    {
        temp->next=curr;
        curr->prev=temp;
    }
    else //middle nodes
    {
        curr->next = temp->next;
        curr->prev = temp;
        temp->next->prev = curr;
        temp->next = curr;
    }
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("LINKED LIST IS EMPTY");
        return;
    }
    else if(temp->next==NULL)//single node
    {
        printf("Data:%d Pri:%d\t",temp->data,temp->pri);
        return;
    }
    while(temp!=NULL)
    {
        printf("Data:%d Pri:%d\t",temp->data,temp->pri);
        temp=temp->next;
    }
    printf("\n");
}
void deque()
{
    int key;
    printf("Enter the pri to delete:");
    scanf("%d",&key);
    struct node * temp=head;
    if(head==NULL)
    {
        printf("LINKED LIST IS EMPTY");
        return;
    }
    if(head->pri==key)//handeling first node
    {
        if(head->next==NULL)
        {
            free(temp);
            head=NULL;
            printf("Node with pri=%d deleted successfully.\n", key);
            return;
        }
        head=head->next;
        head->prev=NULL;
        free(temp);
        printf("Node with pri=%d deleted successfully.\n", key);
        return;
    }
    while(temp!=NULL && temp->pri!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Pri not in the linked list\n");
        return;
    }
    if(temp->next==NULL)//last node condiction
    {
        temp->prev->next=NULL;
        free(temp);
        printf("Node with pri=%d deleted successfully.\n", key);
        return;
    }
    //midle node
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    printf("Node with pri=%d deleted successfully.\n", key);
    return;
}

int main()
{
    int cho=1;
    do{
        printf("\n===========MENU=============\n0)Exite\n1)Create\n2)Insert\n3)Display\nEnter:");
        scanf("%d",&cho);
        switch(cho)
        {
            case 0:printf("THANK YOU\n");break;
            case 1:head=create();break;
            case 2:ineque();break;
            case 3:display();break;
            case 4:deque();break;
        }
    }while(cho);
    return 0;
}