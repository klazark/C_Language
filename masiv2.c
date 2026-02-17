#include <stdio.h>

/*
    Задача: Въведете масив. Намерете минимума и го разменете с втория елемент.
    После разменете втория елемент с първия (татък).
*/

int main()
{
    int n;
    // Прочитаме размера на масива
    printf("Въведете брой елементи: ");
    scanf("%d", &n);

    int masiv[n];

    // Прочитаме елементите на масива
    printf("Въведете елементите:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Елемент %d: ", i + 1);
        scanf("%d", &masiv[i]);
    }

    // Показваме исходния масив
    printf("\nИсходния масив:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", masiv[i]);
    }
    printf("\n");

    // Намираме минимума и неговия индекс
    int min = masiv[0];
    int min_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (masiv[i] < min)
        {
            min = masiv[i];
            min_index = i;
        }
    }

    printf("\nМинимум: %d на позиция %d\n", min, min_index);

    // Разменяме минимума с втория елемент (индекс 1)
    int temp = masiv[1];
    masiv[1] = masiv[min_index];
    masiv[min_index] = temp;

    // Показваме масива след размяната
    printf("\nМасив след размяната:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", masiv[i]);
    }
    printf("\n");

    return 0;
}