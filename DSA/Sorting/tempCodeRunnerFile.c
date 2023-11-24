
    printf("Enter number of elements in array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i);
        scanf("%d", &arr[i]);
    }

    // int arr[] = {170, 45, 75, 90};
    // int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}