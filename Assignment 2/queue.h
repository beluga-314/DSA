#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int queue_size;
    struct node* next;
}new_queue;

typedef struct node
{
    int data;
    struct node* next;
}new_node;

void enqueue(new_queue* queue, int data);
int dequeue(new_queue* queue);
void input_queue(new_queue* queue);
void output_queue(new_queue*queue);




void enqueue(new_queue* queue, int data)
{
    new_node* temp = queue->next;
    while(temp->next!= (new_node*)queue)
    {
        temp = temp->next;
    }
    temp->next = (new_node*)malloc(sizeof(new_node));
    temp = temp->next;
    temp->data = data;
    temp->next = (new_node*)queue;
    queue->queue_size++;
}

int dequeue(new_queue* queue)
{
    if(queue->queue_size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    new_node* temp = queue->next;
    queue->next = temp->next;
    int deleted_value = temp->data;
    free(temp);
    queue->queue_size--;
    return deleted_value;
}

void input_queue(new_queue* queue)
{
    printf("Size of the Queue: ");
    scanf("%d", &queue->queue_size);
    if(queue->queue_size == 0)
    {
        return;
    }
    int i = 0, temp;
    printf("Enter %d inputs of the queue: ", queue->queue_size);
    while(i < queue->queue_size)
    {
        scanf("%d", &temp);
        enqueue(queue,temp);
        queue->queue_size--;
        i++;
    }
}

void output_queue(new_queue*queue)
{
    if(queue->queue_size == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is as follow:\n");
    int i = 0;
    new_node* temp = queue->next;
    while(i < queue->queue_size)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
}