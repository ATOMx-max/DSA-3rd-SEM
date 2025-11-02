#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
struct node *searchR(struct node *r,int key)
{
    if(r==NULL)return NULL;
    else if (key==r->data)return r;
    else if (key<r->data)
    {
        return searchR(r->lchild,key);
    }
    else
    {
        return searchR(r->rchild,key);
    }
}
int search(int key)
{
    if(root==NULL)return 0;
    struct node *temp=root;
    while(temp!=NULL)
    {
        if(key==temp->data)return 1;
        else if(key<temp->data)
        {
            temp=temp->lchild;
        }
        else
        {
            temp=temp->rchild;
        }
    }
    return 0;
}
int smallestR(struct node *r)
{
    if(r==NULL)return INT_MAX;
    else if(r->lchild==NULL)return r->data;
    else
    {
        return smallestR(r->lchild);
    }
}
int smallest(struct node *r)
{
    if (r==NULL)return INT_MAX;
    while(r!=NULL)
    {
        if(r->lchild==NULL)
        {
            return r->data;
        }
        else{
            r=r->lchild;
        }
    }
}
int largest(struct node *r)
{
    if (r==NULL)return INT_MIN;
    else if(r->rchild==NULL) return r->data;
    else
        return largest(r->rchild);
}
int total_node(struct node *r)
{
    if(r==NULL)return 0;
    else{
        return total_node(r->lchild)+total_node(r->rchild)+1;
    }
}
int In_node(struct node *r)
{
    if(r==NULL)return 0;
    else if (r->lchild!=NULL && r->rchild!=NULL)
    {
        return(In_node(r->lchild)+In_node(r->rchild)+1);
    }
    return In_node(r->lchild)+In_node(r->rchild);
}
int hight(struct node *r)
{
    if(r==NULL)return -1;
    int lh=hight(r->lchild);
    int rh=hight(r->rchild);
    return(1+(lh>rh?lh:rh));
}
struct node * minVN(struct node *r)
{
    if(r==NULL)return r;
    while(r->lchild!=NULL)
    {
        r=r->lchild;
    }
    return r;
}
struct node * delete(struct node *r,int key)
{
    if(r==NULL) return r;
    if(key<r->data)
    {
        r->lchild=delete(r->lchild,key);
    }
    else if(key>r->data)
    {
        r->rchild=delete(r->rchild,key);
    }
    else//equal
    {
        if(r->lchild==NULL && r->rchild==NULL)
        {
            free(r);
            return NULL;
        }
        if(r->lchild==NULL)
        {
            struct node * temp=r->rchild;
            free(r);
            return temp;
        }
        if(r->rchild==NULL)
        {
            struct node * temp=r->lchild;
            free(r);
            return temp;
        }
        struct node *temp=minVN(r->rchild);
        r->data=temp->data;
        r->rchild=delete(temp->rchild,temp->data);
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
    delete(root,30);
    printf("\n");
    preorder(root);
    /*
    struct node *temp=searchR(root,90);
    printf("\n%u",temp);
    temp=searchR(root,200);
    printf("\n%u",temp);
    int ans=search(45);
    printf("\n%d",ans);
    printf("\n%d",smallestR(root));
    printf("\n%d",smallest(root));
    printf("\n%d",largest(root));
    printf("\n%d",total_node(root));
    printf("\n%d",In_node(root));
    printf("\n%d",hight(root));*/

    return 0;
}