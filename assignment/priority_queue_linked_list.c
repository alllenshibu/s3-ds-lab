#include <stdio.h>
#include <Stdlib.h>

struct element
{
    int data;
    int priority;
    struct element *next;
};

struct element *create_new_element()
{
    struct element *e = (struct element *)malloc(sizeof(struct element));
    e->data = 0;
    e->priority = 0;
    e->next = NULL;
}

void enqueue(struct element **front, struct element **rear, int data, int priority)
{
    if (*front == NULL)
    {
        *front = create_new_element();
        (*front)->data = data;
        (*front)->priority = priority;
        *rear = *front;
        return;
    }

    struct element *new_element = create_new_element();
    new_element->data = data;
    new_element->priority = priority;

    if (priority < (*rear)->priority)
    {
        (*rear)->next = new_element;
        *rear = new_element;
        return;
    }

    struct element *temp = *front;

    while (temp->next != NULL && temp->next->priority > priority)
        temp = temp->next;

    new_element->next = temp->next;
    temp->next = new_element;
}

int dequeue(struct element **front, struct element **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty");
        return (int)NULL;
    }

    struct element *temp = *front;
    int data = temp->data;
    free(temp);
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;

    return data;
}

int peek(struct element *front, struct element *rear)
{

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return (int)NULL;
    }

    return front->data;
}

print(struct element **front, struct element **rear)
{
    struct element *temp = *front;
    while (temp != NULL)
    {
        printf("%d: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct element *front = NULL, *rear = NULL;

    printf("%d\n", peek(front, rear));

    enqueue(&front, &rear, 9, 10);
    enqueue(&front, &rear, 3, 6);
    enqueue(&front, &rear, 8, 9);
    enqueue(&front, &rear, 5, 8);
    enqueue(&front, &rear, 6, 7);

    print(&front, &rear);

    printf("%d\n", dequeue(&front, &rear));
    printf("%d\n", dequeue(&front, &rear));
    printf("%d\n", dequeue(&front, &rear));
    printf("%d\n", dequeue(&front, &rear));
    printf("%d\n", dequeue(&front, &rear));

    print(&front, &rear);
}