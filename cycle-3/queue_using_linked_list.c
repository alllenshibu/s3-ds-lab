#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *create_node(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display() {
    struct node *ptr = head;
    printf("\n");
    if (ptr == NULL) {
        printf("queue is empty");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void add_element(int data) {
    struct node *ptr = head;
    struct node *newNode = create_node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void enqueue(int item) {
    add_element(item);
    printf("added %d", item);
}

void dequeue() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("queue is empty");
    } else {
        printf("dequeued %d", ptr->data);
        ptr = ptr->next;
        head = ptr;
    }
}

int main() {
    int i, op, element;
    printf("Choose Operation\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. Display\n");
    printf("Press any other key to exit\n");
    do {
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
