#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define a structure to represent the queue
struct Queue
{
    int data[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue)
{
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue)
{
    return (queue->front == -1);
}

// Function to check if the queue is full
bool isFull(struct Queue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue (push) an element into the queue
void enqueue(struct Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->data[queue->rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Signifies an error or empty queue
    }
    else
    {
        int value = queue->data[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = queue->rear = -1; // Queue becomes empty
        }
        else
        {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return value;
    }
}

// Function to get the front element of the queue without dequeuing it
int front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1; // Signifies an error or empty queue
    }
    else
    {
        return queue->data[queue->front];
    }
}

int main()
{
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front of the queue: %d\n", front(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    if (isEmpty(&queue))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }

    return 0;
}
