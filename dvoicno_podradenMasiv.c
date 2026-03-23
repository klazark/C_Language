#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {3, 7, 11, 18, 24, 33, 47, 55, 61, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Masiv: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Vuvedete chislo za tursene: ");
    scanf("%d", &target);

    int index = binarySearch(arr, size, target);

    if (index != -1)
        printf("Namereno na indeks: %d\n", index);
    else
        printf("Chisloto ne e v masiva.\n");

    return 0;
}
