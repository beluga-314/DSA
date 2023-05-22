#include<stdio.h>
#include<ctype.h>

int stack[50];
int top = -1;

void push(int a){
    stack[++top] = a;
}

int pop(){
    if (top == -1)
        return -1;              //returning -1 means stack is already empty, so we cannot pop
    else{
        return stack[top--];
    }
}

int main()
{
    char postfx[51];
    char *e;
    int n1, n2, num, flag = 0;
    printf("Enter the postfix expression (with spaces between each of the numbers and operators): ");
    gets(postfx);
    e = postfx;
    while((*e) != '\0')
    {
        if(isdigit(*e))
        {
            if(flag == 0){              //flag = 0 means previous character was NOT a digit
                push((*e)-'0');
            }

            //evaluating the entire number digit-by-digit
            else{
                num = pop()*10;
                num = num + ((*e) - '0');
                push(num);
            }
            
            flag = 1;                   //flag is made 1 once we encounter a digit
        }

        else if ((*e) == ' ')
            flag = 0;
        
        else                //case: an operator is encountered
        {
            flag = 0;

            //popping and storing the top two numbers from the stack
            n1 = pop();
            n2 = pop();

            //performing operation corresponding to respective operator
            switch(*e)
            {
                case '+':
                    push(n2 + n1);
                    break;

                case '-':
                    push(n2 - n1);
                    break;
                
                case '*':
                    push(n2 * n1);
                    break;
                
                case '/':
                    push(n2 / n1);
                    break;
            }
        }
        e++;
    }

    printf("%d\n\n", pop());            //printing the value obtained after evaluating the postfix expression

    return 0;
}