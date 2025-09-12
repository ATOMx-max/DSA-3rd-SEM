#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
struct Node {
    int val;
    struct Node *next;
};
struct Node *end=NULL;
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
    current->next=current;//for circular linked list
    return current;
}
//insert from back
struct Node *insert_back(struct Node*end)
{
    struct Node* temp=create_node();;
    if(end==NULL)
    {
        end=temp;
    }
    else
    {
        temp->next=end->next;
        end->next=temp;
        end=temp;
    }
    return end;
}
struct Node *insert_front(struct Node *end)
{
    struct Node * front=create_node();
    if(end==NULL)
    {
        end=front;
    }
    else
    {
        front->next=end->next;
        end->next=front;
    }
    return end;
}
void display(struct Node*end)
{
    if(end==NULL)
    {
        printf("CIRCULAR LINKED LIST IS EMPTY\n");
        return;
    }
    struct Node *front=end->next;//pointing the first element
    do
    {
        printf("%d\t",front->val);
        front=front->next;
    }while(front!=end->next);
    printf("\n");
}
struct Node *delete_front(struct Node*end)
{
    struct Node * temp;
    if(end==NULL)
    {
        printf("CIRCULAR LINKED LIST IS EMPTY\n");
        return NULL;
    }
    else if(end==end->next)//one node
    {
        free(end);
        end=NULL;
        return end;
    }
    temp=end->next;
    end->next=end->next->next;
    free(temp);
    return end;
}
struct Node * delete_back(struct Node *end)
{
    struct Node * temp;
    if(end==NULL)
    {
        printf("CIRCULAR LINKED LIST IS EMPTY\n");
        return NULL;
    }
    else if(end==end->next)//one node
    {
        free(end);
        end=NULL;
        return end;
    }
    temp=end->next;//fist element
    while(temp->next!=end)
    {
        temp=temp->next;
    }
    temp->next=end->next;
    free(end);
    end=temp;
    return end;
}
int main() {
    int cho;
    printf("\n=========== Linked List Menu ===========\n");
    printf("1) Insert from Back\n");
    printf("2) Insert from Front\n");
    printf("3) Delete from Front\n");
    printf("4) Delete from Back\n");
    printf("5) Display\n");
    printf("6) Exite\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1: end=insert_back(end);break;
            case 2: end=insert_front(end);break;
            case 3: end=delete_front(end);break;
            case 4: end=delete_back(end);break;
            case 5: display(end);break;
            case 6: printf("Exiting..\n"); exit(0);
            default: printf("Please enter correct input\n");
        }
    }
    return 0;
}