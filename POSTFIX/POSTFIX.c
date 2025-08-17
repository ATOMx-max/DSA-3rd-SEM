    #include<stdio.h>
    #include<stdbool.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>
    #define MAX 40
    char stack[MAX];
    int top=-1;
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
                    char temp[2];
                    temp[0] = infix[i];
                    temp[1] = '\0';
                    strcpy(output[op++].str, temp);
                    i++;
                }
            }
            else if (infix[i]==' ')
            {
                i++;
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
                    char temp[2];
                    temp[0] = pop();   // get the character
                    temp[1] = '\0';
                    strcpy(output[op++].str,temp);
                    //strcpy(output[op++].str,c);//append
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
                        char temp[2];
                        temp[0] = pop();   // get the character
                        temp[1] = '\0';
                        strcpy(output[op++].str,temp);
                        //strcpy(output[op++].str,pop());
                        //output[op]=pop();
                    }
                    push(infix[i]);
                }
                //right shift opperaction
                else if (infix[i]=='^')
                {
                    while(!empty() && prec(infix[i])<prec(peek()) && peek()!='(')
                    {
                        char temp[2];
                        temp[0] = pop();   // get the character
                        temp[1] = '\0';
                        strcpy(output[op++].str,temp);
                        //output[op++]=pop();
                    }
                    push(infix[i]);
                }
                i=i+1;
            }
        }
        while(!empty())
        {
            char temp[2];
            temp[0] = pop();   // get the character
            temp[1] = '\0';
            strcpy(output[op++].str,temp);
        }
        output[op].str[0]='\0';//imp for evaluction check
    }
    //EVALUTING POSTFIX
    int eval_postfix()
    {
        int eval_stack[MAX];
        int eval_top=-1;
        for (int i=0;output[i].str[0]!='\0';i++)
        {
            if(isdigit(output[i].str[0]))
            {
                eval_stack[++eval_top]=atoi(output[i].str);
            }
            else{
                int op2=eval_stack[eval_top--];
                int op1=eval_stack[eval_top--];
                switch (output[i].str[0])
                {
                case '+':
                    eval_stack[++eval_top]=op1+op2;
                    break;
                case '-':
                    eval_stack[++eval_top]=op1-op2;
                    break;
                case '*':
                    eval_stack[++eval_top]=op1*op2;
                    break;
                case '/':
                    eval_stack[++eval_top]=op1/op2;
                    break;
                case '^':
                    printf("This ^ not programed exit...");
                    exit(1);
                    break;
                default: printf("Unknown operator\n"); exit(1);
                }
            }
        }
        return eval_stack[eval_top];
    }
    int main()
    {
        char infix[MAX];
        printf("Enter the Infix expraction:");
        scanf("%[^\n]s",infix);
        //fgets(infix,sizeof(infix),stdin);
        printf("INFIX EXPRACTION:%s\n",infix);
        postfix(infix);
        printf("POSTFIX EXPRACTION:");
        int flag=1;
        for (int j = 0; output[j].str[0] != '\0'; j++) 
        {
            if(!isdigit(output[j].str[0])||output[j].str[0]=='^')
            {
                flag=0;
            }
            printf("%s ", output[j].str);
        }
        if(flag)
        {
            int ip;
            printf("\nWant to evalute the postfix Expraction(y=1/n=0)");
            scanf("%d",&ip);
            if(ip==1)
            {
                printf("Evaluted postfix expraction is:%d",eval_postfix());
            }
        }
        printf("\n");  
        return 0;
    }