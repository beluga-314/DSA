#include <stdio.h>

//Function declarations

void input_array(int list[], int size);
void output_array(int list[], int size);
void max_heapify(int list[],int index, int heap_size);
void build_max_heap(int list[], int size);
void heap_sort(int list[], int size);
int parent(int i);
int left(int i);
int right(int i);
void swap(int* a, int* b);

int main()
{
    int size;

    //Asking the user for the size of the list

    printf("Size of the array: ");
    scanf("%d", &size);
    int array[size];
    input_array(array, size);
    heap_sort(array, size);
    output_array(array, size);
}

//Function that applies heapsort on the list

void heap_sort(int list[], int size)
{
    build_max_heap(list, size); //Build a heap first
    int heap_size = size, i = size;
    while(i > 1)
    {
        swap(&list[0],&list[heap_size - 1]); //swap the first element with last heap element
        heap_size = heap_size - 1; //remove the last element from heap
        max_heapify(list, 0, heap_size); //make the remaining heap a max heap
        i--;
    }
}

//Function that builds the max heap taking the list as argument

void build_max_heap(int list[], int size)
{
    int i = size / 2; //Apply max-heapify from bottom to top starting from the first non leaf node
    while( i >= 0)
    {
        max_heapify(list, i , size);
        i--;
    }
}

//Function that applies max_heapify on the list at the index passed.
//It makes the nodes below this node to have max heap property.

void max_heapify(int list[], int index, int heap_size)
{
    int l = left(index), r = right(index), largest;
    if(l < heap_size && list[l] > list[index]) //Find the largest of the parent and its children first
    {
        largest = l;
    }
    else
    {
        largest = index;
    }
    if(r < heap_size && list[r] > list[largest])
    {
        largest = r;
    }
    if( largest != index) //if the largest is not the parent, then swap it with the largest child
    {
        swap(&list[index], &list[largest]);
        max_heapify(list, largest, heap_size); //Apply max-heapify on the parent that is just swapped with largest child
    }
}

//Function that takes the inputs from user and builds the array

void input_array(int list[], int size)
{
    printf("Enter the elements of the array: ");
    int i = 0;
    while (i < size)
    {
        scanf("%d", &list[i]);
        i++;
    }
}

//Function that prints the list to the user

void output_array(int list[], int size)
{
    int i = 0;
    printf("Sorted list is as follows\n");
    while (i < size)
    {
        printf("%d ", list[i]);
        i++;
    }
    printf("\n");
}

//Function that swaps the values of two variables - pass by reference

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Function that returns the index of the left child of a given parent index in the heap

int left(int i)
{
    return 2 * i + 1;
}

//Function that returns the index of the right child of a given parent index in the heap

int right(int i)
{
    return 2 * i + 2;
}

//Function that returns the index of the parent of a given child index in the heap

int parent(int i)
{
    return (i - 1) / 2;
}