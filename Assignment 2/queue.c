#include "queue.h"

int main()
{
    new_queue* queue = (new_queue*)malloc(sizeof(new_queue));
    queue->queue_size = 0;
    queue->next = (new_node*)queue;
    input_queue(queue);
    output_queue(queue);
}