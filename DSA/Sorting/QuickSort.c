#include <stdio.h>
#include "arrayheader.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        printf("%d %d\n", pi, arr[pi]);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);

        // Print the array after this pass
        // printf("After pass: ");
        // for (int i = low; i < high; i++)
        // {
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");
    }
}

int main()
{
    // int n;

    // printf("Enter the number of elements: ");
    // scanf("%d", &n);

    // int *arr = createRandomArray(n);
    int arr[7] = {10, 8, 6, 4, 2, 1, 888};
    int n = 7;

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // free(arr);

    return 0;
}
