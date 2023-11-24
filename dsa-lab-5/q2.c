#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int arr1[], int arr2[], int size1, int size2, int mergedArray[])
{
    for (int i = 0; i < size1; i++)
    {
        mergedArray[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++)
    {
        mergedArray[size1 + i] = arr2[i];
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    int arr1[size1];
    printf("Enter %d elements for the first array: ", size1);
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    int arr2[size2];
    printf("Enter %d elements for the second array: ", size2);
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];

    mergeArrays(arr1, arr2, size1, size2, mergedArray);
    printf("Merged 1 and 2 Array: ");
    for (int i = 0; i < mergedSize; i++)
    {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    mergeArrays(arr2, arr1, size2, size1, mergedArray);
    printf("Merged 2 and 1 Array: ");
    for (int i = 0; i < mergedSize; i++)
    {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    bubbleSort(mergedArray, mergedSize);
    printf("Merged and Sorted Array: ");
    for (int i = 0; i < mergedSize; i++)
    {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}
