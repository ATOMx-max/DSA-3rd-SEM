#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10
char stack[MAX];
int top=-1;
bool empty()
{
    return (top==-1);
}
bool full()
{
    return(top==MAX-1);
}
void push(char c)
{
    stack[++top]=c;
}
char peek()
{
    return stack[top];
}
char pop()
{
    return stack[top--];
}
int main()
{
    FILE *file;
    char myString[100];
    file=fopen("index.c","r");
    if (file==NULL)
    {
        printf("Error:File not oppend\n");
    }
    else
    {
        int i=0;
        while(1)
        {
            char ch=fgetc(file);
            //printf("%c",ch);
            if (ch==EOF) break;
            if (ch=='('||ch=='{'||ch=='[') push(ch);
            else if (ch==')'||ch=='}'||ch==']')
            {
                if(ch==')')
                {
                    if(peek()!='(')
                    {
                        printf("Unbalanced");
                        exit(0);
                    }
                }
                else if(ch=='}')
                {
                    if(peek()!='{')
                    {
                        printf("Unbalanced");
                        exit(0);
                    }
                }
                else if(ch==']')
                {
                    if(peek()!='[')
                    {
                        printf("Unbalanced");
                        exit(0);
                    }
                }
                pop();
            }
        }
        if(empty())
        {
            printf("Ballance\n");
        }
        fclose(file);
    }
}