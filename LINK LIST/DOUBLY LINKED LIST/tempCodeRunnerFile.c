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