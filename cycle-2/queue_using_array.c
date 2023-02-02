#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int size, front = -1, rear = -1;
int queue[MAX];

void enqueue(int item) {
    if (front == -1) {
        front = rear = 0;
        queue[rear++] = item;
        printf("added %d", item);
    } else if (rear == size) {
        printf("Queue is full");
    } else {
        queue[rear++] = item;
        printf("added %d", item);
    }
}

void display() {
    int i;
    if (front == rear) {
        printf("queue is empty");
        return;
    }
    for (i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
}

void dequeue() {
    if (front == rear) {
        printf("queue is empty");
        front = rear = -1;
    } else {
        printf("dequeued %d", queue[front++]);
    }
}

int main() {
    int op, element;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    do {
        printf("Choose Operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Press any other key to exit\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
                break;
        }
        printf("\n\n");
    } while (op <= 3);
}
