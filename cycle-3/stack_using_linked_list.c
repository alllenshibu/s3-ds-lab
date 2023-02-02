#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 10

struct node
{
    int data;
    struct node *next;
};

struct node *new_stack()
{
    return (struct node *)malloc(sizeof(struct node));
}

void print(struct node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

void push(struct node **head, int item)
{
    if (*head == NULL)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = item;
        n->next = NULL;
        *head = n;
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = item;
        n->next = *head;
        *head = n;
    }
}

int pop(struct node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

int peek(struct node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return (*head)->data;
}

int main()
{
    struct node *stack = new_stack();
    stack->next = NULL;
    pop(&stack);
    char ch[MAX_INPUT_SIZE];
    printf("Avialable operations are\n");
    printf("PUSH <value>\n");
    printf("POP\n");
    printf("PEEK\n");
    printf("EXIT\n");
    do
    {
        fgets(ch, MAX_INPUT_SIZE, stdin);
        // Push
        if (ch[0] == 'P' && ch[1] == 'U' && ch[2] == 'S' && ch[3] == 'H')
        {
            int value = 0;
            for (int i = 5; i < strlen(ch) - 1; i++)
                value = value * 10 + (ch[i] - '0');
            push(&stack, value);
            printf("-------------------------\n");
            print(stack);
        }
        // Pop
        else if (ch[0] == 'P' && ch[1] == 'O' && ch[2] == 'P')
        {
            int value = pop(&stack);
            print(stack);
            printf("-------------------------\n");
            if (value != -1)
                printf("Popped value: %d\n", value);
        }
        // Peek
        else if (ch[0] == 'P' && ch[1] == 'E' && ch[2] == 'E' && ch[3] == 'K')
        {
            int value = peek(&stack);
            print(stack);
            printf("-------------------------\n");
            if (value != -1)
                printf("Peeked value: %d\n", value);
        }
        else
        {
            printf("-------------------------\n");
            print(stack);
            printf("Invalid operation\n");
        }
    } while (strcmp(ch, "EXIT\n") != 0);

    return 0;
}