int main()
{
    int arr[10], n, i, j, store;
    printf("How many elements?: ");
    scanf("%d", &n);
    printf("Enter %d elements below\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; i < n; i++)
        {
            if (arr[i] > arr[j])
            {
                store = arr[j];
                arr[i] = arr[j];
                arr[j] = store;
            }
        }
    }
    printf("Sorted list:\n");
    for (i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}