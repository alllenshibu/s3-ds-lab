#include <stdio.h>

#define MAX_QUEUE_SIZE 10

typedef struct
{
    int data;
    int priority;
} element;

void enqueue(element *queue, int size, int data, int priority, int *front, int *rear)
{
    if (*front == size - 1)
    {
        printf("Queue is full");
        return;
    }

    if (*front == -1)
    {
        *front = 0;
        *rear = 0;
        queue[*rear].data = data;
        queue[*rear].priority = priority;
        return;
    }

    int current_pos = *rear;
    while (current_pos >= *front && queue[current_pos].priority < priority)
    {
        queue[current_pos + 1] = queue[current_pos];
        current_pos--;
    }
    queue[current_pos + 1].data = data;
    queue[current_pos + 1].priority = priority;

    (*rear)++;
}

int dequeue(element *queue, int size, int *front, int *rear)
{
    if (*front == *rear || *front == -1)
    {
        printf("Queue is empty");
        return (int)NULL;
    }

    return queue[(*front)++].data;
}

int peek(element *queue, int size, int *front, int *rear)
{
    if (*front == *rear || *front == -1)
    {
        printf("Queue is empty");
        return (int)NULL;
    }

    return queue[*front].data;
}

int main()
{
    element queue[MAX_QUEUE_SIZE];
    int front = -1, rear = -1;

    enqueue(queue, MAX_QUEUE_SIZE, 1, 1, &front, &rear);
    enqueue(queue, MAX_QUEUE_SIZE, 3, 3, &front, &rear);
    enqueue(queue, MAX_QUEUE_SIZE, 5, 5, &front, &rear);
    enqueue(queue, MAX_QUEUE_SIZE, 2, 2, &front, &rear);

    for (int i = front; i <= rear; i++)
        printf("%d: %d\n", queue[i].data, queue[i].priority);

    printf("%d\n", dequeue(queue, MAX_QUEUE_SIZE, &front, &rear));

    printf("After dequeue\n");
    for (int i = front; i <= rear; i++)
        printf("%d: %d\n", queue[i].data, queue[i].priority);
}