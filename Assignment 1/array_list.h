#include <stdio.h>
#include <stdlib.h>

// Structure which has an array and size
typedef struct sequence
{
    int array[10000]; //Assuming the max size of the array as 10000
    int size;
} new_seq;

//Position is used in main as an integer datatype
typedef int position;


//Function prototypes
void empty_list(new_seq* arr_list);
void insert_value(new_seq* arr_list, int position, int value);
void delete_value(new_seq* arr_list, int position);
int retrieve_value(new_seq* arr_list, int position);
void input_sequence(new_seq* arr_list);
void output_sequence(new_seq* arr_list);
position first_position(new_seq* arr_list);
position next_position(position place);

//Makes the list empty O(1)

void empty_list(new_seq* arr_list)
{
    arr_list->size = 0;
}

//Inserts a value in the list at the given position O(n)

void insert_value(new_seq* arr_list, int position, int value)
{
    arr_list->size++;
    int i = arr_list->size;
    while(i > position)
    {
        arr_list->array[i] = arr_list->array[i - 1];
        i--;
    }
    arr_list->array[position] = value;
}

//Deletes the value in the list at a position O(n)

void delete_value(new_seq* arr_list, int position)
{
    for (int i = position; i < arr_list->size; i++)
    {
        arr_list->array[i] = arr_list->array[i + 1];
    }
    arr_list->size--;
}

//Retrieves the value from the list at a position O(1)

int retrieve_value(new_seq* arr_list, int position)
{
    return arr_list->array[position];
}

//Function used to fill the list with the inputs given by the user

void input_sequence(new_seq* arr_list)
{
    printf("Input the sequence: ");
    for (int i = 1; i <= arr_list->size; i++)
    {
        scanf("%d", &arr_list->array[i]);
    }
}

//Returns the first position of the list

position first_position(new_seq* arr_list)
{
    return 1;
}

//Returns the position next to the given position

position next_position(position place)
{
    return place + 1;
}

//Prints the sequence

void output_sequence(new_seq* arr_list)
{
    if(arr_list->size == 0)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Final Sequence is: ");
    for (int i = 1; i <= arr_list->size; i++)
    {
        printf("%d ", arr_list->array[i]);
    }
    printf("\n");
}