#include <stdio.h>

#define MAX_QUEUE_SIZE 100

struct element
{
    int data;
    int priority;
};

void enqueue(struct element *queue, int size, int *pos, int data, int priority)
{
    if (*pos == size - 1)
    {
        printf("Queue is full");
        return;
    }
    (*(queue + *pos)).data = data;
    (*(queue + *pos)).priority = priority;

    int current_pos = *pos;

    while (current_pos > 0 && (*(queue + current_pos)).priority > (*(queue + (current_pos - 1) / 2)).priority)
    {

        struct element temp = *(queue + current_pos);
        *(queue + current_pos) = *(queue + (current_pos - 1) / 2);
        *(queue + (current_pos - 1) / 2) = temp;
        current_pos = (current_pos - 1) / 2;
    }

    (*pos)++;
}

int dequeue(struct element *queue, int *pos)
{
    if (*pos == 0)
    {
        printf("Queue is empty");
        return (int)NULL;
    }

    struct element temp = *queue;
    *queue = *(queue + *pos - 1);
    *(queue + *pos - 1) = temp;

    (*pos)--;

    int current_pos = 0;
    while (current_pos < *pos)
    {
        if ((*(queue + current_pos * 2 + 1)).priority > (*(queue + current_pos)).priority)
        {
            if (current_pos * 2 > *pos)
                break;
            if ((*(queue + current_pos * 2 + 1)).priority <= (*(queue + current_pos * 2 + 2)).priority)
            {
                struct element temp = *(queue + current_pos);
                *(queue + current_pos) = *(queue + current_pos * 2 + 2);
                *(queue + current_pos * 2 + 2) = temp;
                current_pos = current_pos * 2 + 2;
            }
            else if ((*(queue + current_pos * 2 + 1)).priority > (*(queue + current_pos * 2 + 2)).priority)
            {
                struct element temp = *(queue + current_pos);
                *(queue + current_pos) = *(queue + current_pos * 2 + 1);
                *(queue + current_pos * 2 + 1) = temp;
                current_pos = current_pos * 2 + 1;
            }
        }
        else
            break;
    }

    return (queue + *pos)->data;
}

int peek(struct element *queue, int *pos)
{
    if (*pos == 0)
    {
        printf("Queue is empty");
        return (int)NULL;
    }

    return queue->data;
}

int main()
{

    struct element queue[MAX_QUEUE_SIZE];
    int pos = 0;

    enqueue(queue, MAX_QUEUE_SIZE, &pos, 1, 1);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 5, 5);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 1, 1);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 8, 8);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 6, 6);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 2, 2);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 2, 2);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 13, 13);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 12, 12);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 11, 11);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 7, 7);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 2, 2);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 15, 15);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 3, 3);
    enqueue(queue, MAX_QUEUE_SIZE, &pos, 10, 10);

    for (int i = 0; i < pos; i++)
        printf("%d: %d\n", queue[i].data, queue[i].priority);

    printf("%d\n", dequeue(queue, &pos));

    printf("After dequeue\n");
    for (int i = 0; i < pos; i++)
        printf("%d: %d\n", queue[i].data, queue[i].priority);
    printf("%d\n", dequeue(queue, &pos));

    printf("After dequeue\n");
    for (int i = 0; i < pos; i++)
        printf("%d: %d\n", queue[i].data, queue[i].priority);
}
