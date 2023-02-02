#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    printf("Sorting using Insertion Sort :\n");
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, arr[100];
    printf("Enter number of elements :");
    scanf("%d", &n);
    printf("Enter %d integers for sorting :\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    printf("Sorted array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
