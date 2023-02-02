#include <stdio.h>

void print_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void merge_sort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        print_array(A, high + 1);
        merge(A, mid, low, high);
    }
}

int main()
{
    int n, A[100];
    printf("Enter the number of elements of the array ");
    scanf("%d", &n);
    printf("Enter the elements ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("The input array is \n");
    print_array(A, n);
    printf("\n");
    merge_sort(A, 0, n - 1);
    printf("\nThe sorted array is \n");
    print_array(A, n);
    return 0;
}