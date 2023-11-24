#include <stdio.h>
#include <stdlib.h>
#include "arrayheader.h"

void insertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = createRandomArray(n);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    insertionSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
