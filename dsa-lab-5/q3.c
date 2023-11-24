#include <stdio.h>

int findSmallest(const int *arr, int size)
{
    if (size <= 0)
    {
        return 0;
    }
    const int *ptr = arr;
    int smallest = *ptr;
    for (int i = 1; i < size; i++)
    {
        ptr++;

        if (*ptr < smallest)
        {
            smallest = *ptr;
        }
    }
    return smallest;
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers:\n", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int smallest = findSmallest(arr, size);
    printf("The smallest number in the array is: %d\n", smallest);
    return 0;
}
