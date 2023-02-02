#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 25


void push(int stack[], int size, int *top, int item) {
    if ((*top) == size) {
        printf("Error: stack overflow\n");
        return;
    }
    stack[++(*top)] = item;
}

int pop(int stack[], int size, int *top) {
    if ((*top) < 0) {
        printf("Error: stack underflow\n");
        return *top;
    }
    return stack[(*top)--];
}

int peek(int stack[], int size, int *top) {
    if ((*top) < 0) {
        printf("Error: stack underflow\n");
        return *top;
    }
    return stack[(*top)];
}

int is_empty(int stack[], int size, int *top) {
    if (*top == -1)
        return 1;
    return 0;
}

int is_full(int stack[], int size, int *top) {
    if (*top == size - 1)
        return 1;
    return 0;
}

void print_stack(int stack[], int size, int *top) {
    if (is_empty(stack, size, top)) {
        printf("Stack is empty\n");
        return;
    }
    // Formatting
    for (int i = 0; i <= *top; i++) {
        printf("| %d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int MAX_STACK_SIZE;
    printf("Enter stack size: ");
    scanf("%d", &MAX_STACK_SIZE);
    MAX_STACK_SIZE--;

    int s[MAX_STACK_SIZE];
    int top = -1;

    printf("Avialable operations are\n");
    printf("PUSH <value>\n");
    printf("POP\n");
    printf("PEEK\n");
    printf("EXIT\n");
    char ch[MAX_INPUT_SIZE];
    do {
        fgets(ch, MAX_INPUT_SIZE, stdin);

        // Push
        if (ch[0] == 'P' && ch[1] == 'U' && ch[2] == 'S' && ch[3] == 'H') {
            int value = 0;
            for (int i = 5; i < strlen(ch) - 1; i++)
                value = value * 10 + (ch[i] - '0');
            push(s, MAX_STACK_SIZE, &top, value);
            printf("-------------------------\n");
            print_stack(s, MAX_STACK_SIZE, &top);
        }
            // Pop
        else if (ch[0] == 'P' && ch[1] == 'O' && ch[2] == 'P') {
            int value = pop(s, MAX_STACK_SIZE, &top);
            print_stack(s, MAX_STACK_SIZE, &top);
            printf("-------------------------\n");
            printf("Popped value: %d\n", value);
        }
            // Peek
        else if (ch[0] == 'P' && ch[1] == 'E' && ch[2] == 'E' && ch[3] == 'K') {
            int value = peek(s, MAX_STACK_SIZE, &top);
            print_stack(s, MAX_STACK_SIZE, &top);
            printf("-------------------------\n");
            printf("Peeked value: %d\n", value);
        } else {
            printf("-------------------------\n");
            print_stack(s, MAX_STACK_SIZE, &top);
            printf("Invalid operation\n");
        }
    } while (strcmp(ch, "EXIT\n") != 0);

    return 1;
}
