#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int element)
{

    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = element;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = element;
        }
        printf("%d added to Queue\n", element);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int del = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        printf("%d removed from the Queue\n", del);
    }
}

void Front()
{
    if (front == rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front : %d\n", queue[front]);
    }
}

void Rear()
{
    if (front == rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Rear : %d\n", queue[rear]);
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i;
        printf("Queue :");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main()
{

    int option, data;
    printf("1: Enqueue\n");
    printf("2: Dequeue\n");
    printf("3: Front\n");
    printf("4: Rear\n");
    printf("5: Display\n");
    printf("6: exit\n");

    while (1)
    {
        printf("Choose a Option: ");
        scanf("%d", &option);

        switch (option)
        {

        case 1:
            printf("Enter the Element: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;
        case 3:
            Front();
            break;

        case 4:
            Rear();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nChoose a Valid Option\n");
            break;
        }
    }
}
