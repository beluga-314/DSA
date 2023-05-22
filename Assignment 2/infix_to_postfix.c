#include<stdio.h>
#include<ctype.h>

char stack[1000];
int top = -1;

int priority(char a){
    if (a == '(')                       // '(' is set as lowest priority because it should never be printed
        return 0;
    else if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
}

void push(char a){
    stack[++top] = a;
}

int pop(){
    if (top == -1)
        return -1;          //returning -1 means stack is already empty, so we cannot pop
    else{
        return stack[top--];
    }
}

int main(){
    char inf[1001];
    char *e, a;
    e = inf;
    printf("Enter infix expression: ");
    scanf("%1000s", inf);
    printf("Postfix Expression: ");
    
    while(*e != '\0'){
        if (isalnum(*e))                        // isalnum checks if char is alphanumeric (declared in <ctype.h> header)
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')'){
            while ((a = pop()) != '(')          // popping & printing everything till we reach '(', then popping '() without printing
                printf("%c", a);
        }
        else{
            // popping & printing every operator in stack whose precedence is greater than or equal to the given operator, & then pushing the given operator
            while (priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    //printing the last remaining operators in the stack
    while(top != -1)
        printf("%c", pop());
    printf("\n");
    return 0;
}