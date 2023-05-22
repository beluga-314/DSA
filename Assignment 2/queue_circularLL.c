#include<stdio.h>
#include<stdlib.h>

struct node{                //defining the structure of each node of linked list
    int data;
    struct node *next;
};

//in each of the following functions we are passing the head and tail pointers by reference 
//so that changes are reflected everywhere

//enqueue operation
void enqueue(struct node ** head, struct node ** tail, int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = data;
    if ((*head) == NULL){               //case: empty queue
        (*head) = temp;
        (*head) -> next = *head;
        (*tail) = temp;
    }
    else {
        temp -> next = *head;
        (*head) = temp;
        (*tail) -> next = *head;

    }
}

//dequeue operation
int dequeue(struct node ** head, struct node ** tail){
    if ((*head) == NULL){               //case: empty queue
        printf("Empty queue, so nothing to dequeue\n");
        return -1;
    }
    else if ((*head) == (*tail)){       //case: queue with a single job
        int a = (*head) -> data;
        (*head) = NULL;
        free(*tail);
        return a;
    }
    else {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp = (*head);
        while (temp -> next != *tail){
            temp = temp -> next;
        }
        int a = (*tail) -> data;
        (*tail) = temp;
        temp = (*tail) -> next;
        (*tail) -> next = ((*tail) -> next) -> next;
        free(temp);
        return a;

    }
}

//a function which displays all the jobs in the queue in order, starting from the latest job 
void display(struct node **head, struct node **tail){
    if ((*head) == NULL){                           //case: empty queue
        printf("Empty queue\n");
    }
    else if ((*head) == *tail){                     //case: queue with single job
        printf("%d\n", (*head) -> data);
    }
    else{
        struct node * temp = *head;
        while (temp != (*tail)){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("%d\n", temp -> data);
    }
}

int main(){
    struct node *head = NULL;
    struct node *tail = NULL;
    int choice;
    while (1){
        printf("1.Display the queue\n");
		printf("2.Enqueue\n");
		printf("3.Dequeue\n");
        printf("4.Quit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);
        int size;

        switch (choice){
            case 1:
                display(&head, &tail);
                printf("\n");
                break;
            case 2:
                printf("Enter number of elements you want to enqueue: ");
                scanf("%d", &size);
                if (size == 0) break;
                printf("Enter the %d numbers (separated by spaces): ", size);
                for (int i = 0; i < size; i++)
                {
                    int j;
                    scanf("%d", &j);
                    enqueue(&head, &tail, j);
                }
                printf("\n");
                break;
            case 3:
                printf("%d\n", dequeue(&head, &tail));
                printf("\n");
                break;
            case 4:
                exit(1);    
        }


    }
}

