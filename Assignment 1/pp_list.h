#include <stdlib.h>
#include <stdio.h>

//Structure which is a node containing a data variable and pointer to next node
typedef struct node
{
    int data;
    struct node* next;
}new_node;

//Structure which contains the pointer to the head of the sequence and its size
typedef struct sequence
{
    struct node* head;
    int size;
}new_seq;

//Position acts as a datatype which is a pointer to a new node
typedef new_node* position;

// Function prototypes
void empty_list(new_seq* pp_list);
void insert_value(new_seq* pp_list, new_node* position, int value);
void delete_value(new_seq* pp_list, new_node* position);
int retrieve_value(new_seq* pp_list, new_node* position);
void input_sequence(new_seq* pp_list);
void output_sequence(new_seq* pp_list);
new_node* first_position(new_seq* pp_list);
new_node* next_position(new_node* pp_lsit);

//Empties the list O(1)

void empty_list(new_seq* pp_list)
{
    pp_list->head->next = NULL;
    pp_list->size = 0;
}

//Inserts a value at the given position in the list O(1)

void insert_value(new_seq* pp_list, new_node* position, int value)
{
    pp_list->size++;
    new_node* temp = (new_node*)malloc(sizeof(new_node));
    temp->data = value;
    temp->next = position->next;
    position->next = temp;
 
}

//Deletes a value at the given position in the list O(1)

void delete_value(new_seq* pp_list, new_node* position)
{
    pp_list->size--;
    new_node* temp = position->next;
    position->next = temp->next;
    free(temp);
}

//Retrieves a value at the given position from the list O(1)

int retrieve_value(new_seq* pp_list, new_node* position)
{
    return position->next->data;
}

//Takes the input from the user and fills the list

void input_sequence(new_seq* pp_list)
{
    pp_list->head = (new_node*)malloc(sizeof(new_node));
    new_node* temp = pp_list->head;
    
    printf("Input the sequence: ");
    for (int i = 1; i <= pp_list->size; i++)
    {
        new_node* temp2 = (new_node*)malloc(sizeof(new_node));
        temp->next = temp2;
        temp =temp->next;
        scanf("%d", &temp->data);
    }
    temp->next = NULL;
}

//Returns the address of the first element in the list

new_node* first_position(new_seq* pp_list)
{
    return pp_list->head;
}

//Returns the address of the element next to the given address

new_node* next_position(new_node* place)
{
    place = place->next;
    return place;
}

//Prints the sequence

void output_sequence(new_seq* pp_list)
{
    if(pp_list->size == 0)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Final Sequence is: ");
    new_node* temp = pp_list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

