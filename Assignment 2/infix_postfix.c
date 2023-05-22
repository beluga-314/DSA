#include "stack.h"

int main()
{
    //Initializing a new stack named 'stack'
    new_stack* stack = (new_stack*)malloc(sizeof(new_stack));
    stack->stack_size = 0; //make the size of the stack 0
    stack->next = (new_node*)stack; //typecast the next pointer of stack as a node pointer
    
    //infix to postfix

    int i = 0;
    char infix[1000];
    printf("Enter the infix notation: ");
    scanf("%s", infix);
    printf("Infix notation is: %s\n", infix);
    printf("Postfix notation is: %s\n", infix);
}