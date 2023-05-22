//UNCOMMENT THE HEADER REQUIRED AND COMMENT THE OTHERS

#include "array_list.h"
// #include "pp_list.h"
// #include "cp_list.h"

void remove_duplicates(new_seq* list);


int main()
{
    //Initialising list as a pointer to a new sequence

    new_seq* list = (new_seq*)malloc(sizeof(new_seq));

    //Obtaining size of the sequence from user

    printf("Size of the sequence: ");   
    scanf("%d", &list->size);
    
    //When list is empty

    if(list->size == 0)
    {
        printf("List is empty\n");
        return 1;
    }
    
    //Take the input and fill the sequence

    input_sequence(list);
 
  
    //Calling the function remove_duplicates 

    remove_duplicates(list);

    //Output the sequence

    output_sequence(list);
}

//Using O(n2) algorithm to remove the duplicates by comparisons
//First_position and next_position are used to find the position required for iterations

void remove_duplicates(new_seq* list)
{
    position place = first_position(list), temp_place;

    int check_value, i = 0, j, curr_value;

    //Fix 1 element and loop through all the others comparing with the fixed element
    //Delete if same
    //Position is incremented usind next_position function
    //Data retrieval is done using retrieve_value function
    
    while(i < list->size) 
    {
        check_value = retrieve_value(list, place);
        j = i + 1;
        temp_place = next_position(place);
        while(j < list->size) 
        {
            curr_value = retrieve_value(list, temp_place);
            if(curr_value == check_value) 
            {
                delete_value(list, temp_place);
            }
            else
            {
                j++;
                temp_place = next_position(temp_place);
            }
        }
        place = next_position(place);
        i++;
    }
}