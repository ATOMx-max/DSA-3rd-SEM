#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 40
char stack[MAX];
int top=-1;
char output[MAX];

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
    if(full())
    {
        printf("ERROR:STACK IS FULL");
        return;
    }
    stack[++top]=c;
}
char peek()
{
    if (empty())
    {
        printf("STACK IS EMPTY");
        exit(0);
    }
    else{
        return stack[top];
    }
}
char pop()
{
    if(empty())
    {
        printf("ERROR:STACK IS EMPTY");
        exit(0);
    }
    else
    {
        return stack[top--];
    }
}

bool is_opperent(int i,char infix[])
{
    if(infix[i]>='a' && infix[i]<='z') return true;
    else if (infix[i]>='A' && infix[i]<='Z') return true;
    else if (infix[i]>='0' && infix[i]<='9') return true;
    else return false;
}
bool is_ope(int i,char infix[])
{
    //true or false 
    return (infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^');
}
int prec(char ch)
{
    if (ch=='^') return 3;
    else if (ch=='*' || ch=='/') return 2;
    else if (ch=='+' || ch=='-') return 1;
    else return 0;
}
void postfix(char infix[])
{
    int i=0,op=0;
    while(infix[i]!='\0')
    {
        //checking opperent
        if (is_opperent(i,infix))
        {
            output[op]=infix[i];
            op=op+1;
            i=i+1;
        }
        //checking for bracket
        else if(infix[i]=='(')
        {
            push(infix[i]);//push to stack
            i=i+1;
        }
        else if (infix[i]==')')
        {
            while(stack[top]!='(')
            {
                output[op++]=pop();//append 
            }
            pop();//discart (
            i++;
        }
        //check for opperater
        else if (is_ope(i,infix))
        {
            if(empty())
            {
                push(infix[i]);

            }
            else if (peek()=='(')//stack to element is (
            {
                push(infix[i]);

            }
            //left shift
            else if (infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
            {
                while(!empty() && prec(infix[i])<=prec(peek()) && peek()!='(')
                {
                    output[op]=pop();
                    op=op+1;
                }
                push(infix[i]);
            }
            //right shift opperaction
            else if (infix[i]=='^')
            {
                while(!empty() && prec(infix[i])<prec(peek()) && peek()!='(')
                {
                    output[op++]=pop();
                }
                push(infix[i]);
            }
            i=i+1;
        }
    }
    while(!empty())
    {
        output[op++]=pop();//till stack empty
    }
    output[op]='\0';
}
int main()
{
    char infix[MAX];
    printf("Enter the Infix expraction:");
    scanf("%s",infix);
    printf("INFIX EXPRACTION:%s\n",infix);
    postfix(infix);
    printf("POSTFIX EXPRACTION:%s",output);
    return 0;
}