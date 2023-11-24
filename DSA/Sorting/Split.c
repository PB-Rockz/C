#include <stdio.h>
#include "arrayheader.h"

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        printf("Left sub-array: ");
        for (int i = low; i <= mid; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Right sub-array: ");
        for (int i = mid + 1; i <= high; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = createRandomArray(n);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); 
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    free(arr); // Don't forget to free the allocated memory

    return 0;
}
