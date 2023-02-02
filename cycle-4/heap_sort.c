#include <stdio.h>

void print_array(int arr[], int n)
{
    for (int m = 0; m < n; m++)
        printf("%d ", arr[m]);
    printf("\n");
}

void swap(int *p, int *q)
{

    int temp = *p;
    *p = *q;
    *q = temp;
}

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        print_array(arr, n);
    }
}

int main()
{
    int n, i;
    printf("Enter no of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter array elements:\n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &arr[j]);
    }
    printf("\nSorting using heap sort \n");
    heap_sort(arr, n);

    printf("\nSorted array is \n");
    print_array(arr, n);
}
