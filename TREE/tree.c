#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* lchild;
    int data;
    struct node * rchild;
};
struct node *root=NULL;
//tree triversing process
//inorder
void inorder(struct node * r)
{
    if(r==NULL)return;
    else{
        inorder(r->lchild);
        printf("%3d",r->data);
        inorder(r->rchild);
    }
}
//preorder
void preorder(struct node * r)
{
    if(r==NULL)return;
    else{
        printf("%3d",r->data);
        preorder(r->lchild);
        preorder(r->rchild);
    }
}
void postorder(struct node * r)
{
    if(r==NULL)return;
    postorder(r->lchild);
    postorder(r->rchild);
    printf("%3d",r->data);
}
struct node *create(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("ERROR\n");
        exit(0);
    }
    temp->data=key;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
void insert(int key)
{
    if(root==NULL)
    {
        root=create(key);
        return;
    }
    struct node * temp=root,*parent=NULL;
    while(temp!=NULL)
    {
        parent=temp;
        if(key<temp->data)
        {
            temp=temp->lchild;
        }
        else if(key>temp->data)
        {
            temp=temp->rchild;
        }
        else return;//doublicate case do nathing 
    }
    if(key<parent->data)
    {
        parent->lchild=create(key);
    }
    else
    {
        parent->rchild=create(key);
    }
}
int main()
{
    insert(50);
    insert(40);
    insert(60);
    insert(30);
    insert(90);
    insert(45);
    preorder(root);


}