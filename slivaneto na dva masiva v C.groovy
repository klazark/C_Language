Zadacha: Slivaneto na dva masiva v C
#include <stdio.h>
// Принтира масив от n елемента
void out(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Сортира масив от n елемента (Bubble Sort)
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Слива два сортирани масива a[] и b[] в result[]
void merge(int a[], int na, int b[], int nb, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }
    while (i < na) result[k++] = a[i++];
    while (j < nb) result[k++] = b[j++];
}
int main() {
    int a[] = {5, 2, 8};
    int b[] = {3, 7, 1};
    int merged[6];
    sort(a, 3);
    sort(b, 3);
    printf("Masiv A: ");  out(a, 3);
    printf("Masiv B: ");  out(b, 3);
    merge(a, 3, b, 3, merged);
    printf("Slqt masiv: "); out(merged, 6);
    return 0;
}