#include <stdio.h>
void modify(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= 3;
    }
}

int main()
{
    int arr[10];
    printf("Enter 10 integers:\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    modify(arr, 10);
    printf("Modified array (each element multiplied by 3):\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
