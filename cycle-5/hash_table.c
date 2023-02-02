#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct
{
    int data;
    int occupied;
} hashtable;

hashtable *create_new_hashtable()
{
    hashtable *h = (hashtable *)malloc(TABLE_SIZE * sizeof(hashtable));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        h[i].data = 0;
        h[i].occupied = 0;
    }
    return h;
}

int hash(int key)
{
    int hash = 0;
    int fold_sum = 0;
    while (key)
    {
        fold_sum += key % TABLE_SIZE;
        key /= TABLE_SIZE;
    }
    hash = fold_sum % TABLE_SIZE;

    return hash;
}

void insert(int key, hashtable h[])
{
    int value = hash(key);

    if (h[value].occupied)
    {
        int no_of_probes = 0;
        int start = value;
        printf("Collision at index %d, ", value);
        while (h[value].occupied)
        {

            value = (value + 1) % TABLE_SIZE;
            no_of_probes++;
            if (value == start)
            {
                printf("Table full\n");
                return;
            }
        }

        printf("No of probes: %d\n", no_of_probes);
        h[value].data = key;
        h[value].occupied = 1;
    }
    else
    {
        h[value].data = key;
        h[value].occupied = 1;
    }
}

void search(int key, hashtable h[])
{
    int value = hash(key);
    if (h[value].data == key && h[value].occupied)
        printf("Found at index %d\n", value);
    else
    {
        int start = value;
        while (h[value].data != key && h[value].occupied)
        {
            value = (value + 1) % TABLE_SIZE;
            if (value == start)
            {
                printf("Not found\n");
                return;
            }
        }
        if (h[value].data == key && h[value].occupied)
            printf("Found at index %d\n", value);
        else
            printf("Not found\n");
    }
}

void print(hashtable h[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
        if (h[i].occupied)
            printf("%d:\t%d\n", i, h[i]);
}

int main()
{
    hashtable *h = create_new_hashtable();
    int ch = 0;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("0. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int key;
            printf("Enter value: ");
            scanf("%d", &key);
            insert(key, h);
            break;
        }
        case 2:
            printf("--------HASH TABLE--------\n");
            print(h);
            printf("--------------------------\n");
            break;
        case 3:
        {
            int key;
            printf("Enter value: ");
            scanf("%d", &key);
            search(key, h);
            break;
        }
        case 0:
            exit(0);
        }
    }
}