    #include<stdio.h>
    #include<stdbool.h>
    #include<stdlib.h>
    #include<string.h>
    #define MAX 40
    char stack[MAX];
    int top=-1;
    //char output[MAX];
    //define structure
    struct element
    {
        char str[MAX];
    };
    struct element output[MAX];


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

    int is_opperent(int i,char infix[])
    {
        if(infix[i]>='a' && infix[i]<='z') return 1;
        else if (infix[i]>='A' && infix[i]<='Z') return 1;
        else if (infix[i]>='0' && infix[i]<='9') return 2;
        else return 0;
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
                //checking for multuple degit number
                if(is_opperent(i,infix)==2)
                {
                    int t=0;
                    char tem[MAX]="";
                    while(is_opperent(i,infix)==2)
                    {
                        tem[t++]=infix[i];
                        i++;
                    }
                    tem[t]='\0';
                    strcpy(output[op++].str,tem);
                }
                else
                {
                    strcpy(output[op++].str,infix[i++]);
                }
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
                    strcpy(output[op++].str,pop());//append
                    //output[op++]=pop();
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
                        strcpy(output[op++].str,pop());
                        //output[op]=pop();
                    }
                    push(infix[i]);
                }
                //right shift opperaction
                else if (infix[i]=='^')
                {
                    while(!empty() && prec(infix[i])<prec(peek()) && peek()!='(')
                    {
                        strcpy(output[op++].str,pop());
                        //output[op++]=pop();
                    }
                    push(infix[i]);
                }
                i=i+1;
            }
        }
        while(!empty())
        {
            strcpy(output[op++].str,pop());
            //output[op++]=pop();//till stack empty
        }
        strcpy(output[op].str,'\0');
    }

    //EVALUTING POSTFIX
    int main()
    {
        char infix[MAX];
        printf("Enter the Infix expraction:");
        scanf("%s",infix);
        printf("INFIX EXPRACTION:%s\n",infix);
        postfix(infix);
        printf("POSTFIX EXPRACTION:");
        for (int j = 0; output[j].str[0] != '\0'; j++) 
        {
            printf("%s ", output[j].str);
        }
        printf("\n");  
        return 0;
    }