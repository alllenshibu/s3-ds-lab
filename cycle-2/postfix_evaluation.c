#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 50

void push(int stack[], int size, int *top, int item)
{
    if ((*top) == size)
    {
        printf("Error: stack overflow\n");
        return;
    }
    stack[++(*top)] = item;
}

int pop(int stack[], int size, int *top)
{
    if ((*top) < 0)
    {
        printf("Error: stack underflow\n");
        return *top;
    }
    return stack[(*top)--];
}

int peek(int stack[], int size, int *top)
{
    if ((*top) < 0)
    {
        printf("Error: stack underflow\n");
        return *top;
    }
    return stack[(*top)];
}

int is_empty(int stack[], int size, int *top)
{
    if (*top == -1)
        return 1;
    return 0;
}

int is_full(int stack[], int size, int *top)
{
    if (*top == size - 1)
        return 1;
    return 0;
}

void print_stack(int stack[], int size, int *top)
{
    if (is_empty(stack, size, top))
    {
        printf("Stack is empty\n");
        return;
    }
    // Formatting
    for (int i = 0; i <= *top; i++)
    {
        printf("| %d ", stack[i]);
    }
    printf("\n");
}

void str_rev(char *str)
{
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        char temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}

int main()
{
    char exp[MAX_EXPRESSION_LENGTH];
    printf("Enter the expression: ");
    fgets(exp, MAX_EXPRESSION_LENGTH, stdin);
    exp[strcspn(exp, "\n")] = 0;

    printf("POST for postfix\n");
    printf("PRE for prefix\n");
    char ch[5];
    scanf("%s", ch);

    if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
        str_rev(exp);

    printf("%s\n", exp);

    int ans = 0;
    int stack[MAX_EXPRESSION_LENGTH], top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {

        if (exp[i] == ' ')
            continue;

        if (exp[i] == '/')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
                ans = x / y;
            else
                ans = y / x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else if (exp[i] == '*')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            ans = y * x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else if (exp[i] == '+')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            ans = y + x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else if (exp[i] == '-')
        {
            int x = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            int y = pop(stack, MAX_EXPRESSION_LENGTH, &top);
            if (ch[0] == 'P' && ch[1] == 'R' && ch[2] == 'E')
                ans = x - y;
            else
                ans = y - x;
            push(stack, MAX_EXPRESSION_LENGTH, &top, ans);
        }
        else
            push(stack, MAX_EXPRESSION_LENGTH, &top, exp[i] - '0');
    }

    printf("Ans = %d\n", ans);

    return 0;
}
