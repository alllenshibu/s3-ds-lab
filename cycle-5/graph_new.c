#include <stdio.h>

#define MAX_NODES 25

int adjacency_matrix[MAX_NODES][MAX_NODES];
int q[MAX_NODES], visited[MAX_NODES], stack[MAX_NODES];
int top = -1, front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == MAX_NODES - 1)
    {
        printf("Queue overflow");
        return;
    }
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}

int dequeue()
{
    int k;
    if ((front > rear) || (front == -1))
        return 0;
    else
    {
        k = q[front++];
        return k;
    }
}

void push_to_stack(int item)
{
    if (top == MAX_NODES - 1)
    {
        printf("Stack overflow ");
        return;
    }
    else
        stack[++top] = item;
}

int pop_from_stack()
{
    int k;
    if (top == -1)
        return 0;
    else
    {
        k = stack[top--];
        return k;
    }
}

void bfs(int s, int n)
{
    int p;
    enqueue(s);
    visited[s] = 1;
    p = dequeue();
    if (p != 0)
        printf("%d ", p);
    while (p != 0)
    {
        for (int i = 1; i <= n; i++)
            if ((adjacency_matrix[p][i] != 0) && (visited[i] == 0))
            {
                enqueue(i);
                visited[i] = 1;
            }
        p = dequeue();
        if (p != 0)
            printf("%d ", p);
    }
    for (int i = 1; i <= n; i++)
        if (visited[i] == 0)
            bfs(i, n);
}

void dfs(int s, int n)
{
    int k;
    push_to_stack(s);
    visited[s] = 1;
    k = pop_from_stack();
    if (k != 0)
        printf("%d ", k);
    while (k != 0)
    {
        for (int i = 1; i <= n; i++)
            if ((adjacency_matrix[k][i] != 0) && (visited[i] == 0))
            {
                push_to_stack(i);
                visited[i] = 1;
            }
        k = pop_from_stack();
        if (k != 0)
            printf("%d ", k);
    }
    for (int i = 1; i <= n; i++)
        if (visited[i] == 0)
            dfs(i, n);
}

int main()
{
    int n, s;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: ");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adjacency_matrix[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    printf("BFS: ");
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    bfs(s, n);
    printf("\n");
    printf("DFS: ");
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    dfs(s, n);
    printf("\n");
}