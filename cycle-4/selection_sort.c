#include <stdio.h>

int main()
{
    int size, arr[50], i, j, temp, small, count = 0, index;
    printf("Enter size for Array: ");
    scanf("%d", &size);
    printf("Enter %d array elements: ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < (size - 1); i++)
    {
        small = arr[i];
        for (j = (i + 1); j < size; j++)
        {
            if (small > arr[j])
            {
                small = arr[j];
                count++;
                index = j;
            }
        }
        if (count != 0)
        {
            temp = arr[i];
            arr[i] = small;
            arr[index] = temp;
        }
        printf("\nStep %d: ", i + 1);
        for (j = 0; j < size; j++)
            printf("%d ", arr[j]);
        printf("\n");
        count = 0;
    }
    printf("\nArray after sorting is:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}