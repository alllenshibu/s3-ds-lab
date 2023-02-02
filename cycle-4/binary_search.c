#include <stdio.h>

int read_array(int a[], int n)
{
    printf("Enter the elements: ");
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
}

int binary_search(int a[], int first, int last, int key)
{
    int mid, flag = 0;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (a[mid] == key)
            printf("Element found at pos %d", mid);
        else if (a[mid] > key)
            binary_search(a, first, mid - 1, key);
        else
            binary_search(a, mid + 1, last, key);
        flag = 1;
        break;
    }
    if (!flag)
        printf("Element not found");
}

int main()
{
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    read_array(a, n);
    printf("Enter the number to search for: ");
    scanf("%d", &key);
    binary_search(a, 0, n - 1, key);
}
