#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int stack_size;
    struct node* next;
}new_stack;

typedef struct node
{
    char data;
    struct node* next;
}new_node;

void input_stack(new_stack* stack);
void output_stack(new_stack* stack);
void push(new_stack* stack, char data);
char pop(new_stack* stack);

void push(new_stack* stack, char data)
{
    new_node* temp = (new_node*)malloc(sizeof(new_node));
    temp->data = data;
    temp->next = stack->next;
    stack->next = temp;
    stack->stack_size++;
}

char pop(new_stack* stack)
{
    if(stack->stack_size == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    new_node* temp = stack->next;
    stack->next = temp->next;
    char deleted_value = temp->data;
    free(temp);
    stack->stack_size--;
    return deleted_value; 
}

void input_stack(new_stack* stack)
{
    int i = 0;
    char str[25];
    printf("Enter the expression and end with 'Enter key': ");
    scanf("%s", str);
    while(str[i] != '\0')
    {
        push(stack, str[i]);
        i++;
    }
}

void output_stack(new_stack*stack)
{
    if(stack->stack_size == 0)
    {
        printf("stack is empty\n");
        return;
    }
    printf("stack is as follow:\n");
    int i = 0;
    new_node* temp = stack->next;
    while(i < stack->stack_size)
    {
        printf("%c ", temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
}