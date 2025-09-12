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