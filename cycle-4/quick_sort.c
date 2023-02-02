#include <stdio.h>

int n;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        print_array(array, n);

        quick_sort(array, low, pi - 1);

        quick_sort(array, pi + 1, high);
    }
}

int main()
{
    int i;
    printf("enter size of array:");
    scanf("%d", &n);
    int data[n];
    printf("enter elements:");
    for (i = 0; i < n; i++)

        scanf("%d", &data[i]);

    printf("Unsorted Array\n");
    print_array(data, n);
    printf("Intermediate array\n");

    quick_sort(data, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    print_array(data, n);
}
