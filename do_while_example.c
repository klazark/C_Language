#include <stdio.h>

int main(void) {
    int n = 0;
    int sum = 0;

    printf("This program demonstrates a do-while loop.\n");

    do {
        printf("Enter a positive number (0 to stop): ");
        if (scanf("%d", &n) != 1) return 1;
        sum += n;
    } while (n != 0);

    printf("Sum: %d\n", sum);
    return 0;
}
