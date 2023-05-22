#include <stdlib.h>
#include <stdio.h>

//Structure which is a node containing a data variable and pointer to next node
typedef struct node
{
    int data;
    struct node* next;
}new_node;

//Structure which contains the head of the list and its size
typedef struct sequence
{
    struct node* head;
    int size;
}new_seq;

//Position acts as a datatype which is a pointer to a node
typedef new_node* position;

// Function prototypes
void empty_list(new_seq* cp_list);
void insert_value(new_seq* cp_list, new_node* position, int value);
void delete_value(new_seq* cp_list, new_node* position);
int retrieve_value(new_seq* cp_list, new_node* position);
void input_sequence(new_seq* cp_list);
void output_sequence(new_seq* cp_list);
new_node* first_position(new_seq* cp_list);
new_node* next_position(new_node* cp_list);

//Empties the list O(1)

void empty_list(new_seq* cp_list)
{
    cp_list->head->next = NULL;
    cp_list->size = 0;
}

//Inserts the value in the list at a given position O(1)

void insert_value(new_seq* cp_list, new_node* position, int value)
{
    int dummy;
    cp_list->size++;
    new_node* temp = (new_node*)malloc(sizeof(new_node));
    temp->data = value;
    temp->next = position->next;
    position->next = temp;
    dummy = temp->data;
    temp->data = position->data;
    position->data = dummy;
 
}

//Deletes an element at a given position of the list

void delete_value(new_seq* cp_list, new_node* position)
{
    if(position->next == NULL)
    {
        new_node* temp = cp_list->head;
        while(temp->next != position)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(position);
    }
    else
    {
        int dummy;
        new_node* temp = position->next;
        dummy = temp->data;
        temp->data = position->data;
        position->data = dummy;    
        position->next = temp->next;
        free(temp);
    }
    cp_list->size--;
    
}

//Retrieves a value from the given position of the list

int retrieve_value(new_seq* cp_list, new_node* position)
{
    return position->data;
}

//Takes the input from the user and fills the list

void input_sequence(new_seq* cp_list)
{
    cp_list->head = (new_node*)malloc(sizeof(new_node));
    new_node* temp = cp_list->head;
    
    printf("Input the sequence: ");
    for (int i = 1; i <= cp_list->size; i++)
    {
        new_node* temp2 = (new_node*)malloc(sizeof(new_node));
        temp->next = temp2;
        temp =temp->next;
        scanf("%d", &temp->data);
    }
    temp->next = NULL;
}

//Returns the pointer to the first element of the list

new_node* first_position(new_seq* cp_list)
{
    return cp_list->head->next;
}

//Returns the pointer to the position next to the given address

new_node* next_position(new_node* place)
{
    return place->next;
}

//Prints the sequence

void output_sequence(new_seq* cp_list)
{
    if(cp_list->size == 0)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Final Sequence is: ");
    new_node* temp = cp_list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}