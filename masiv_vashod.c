/*
    Тази програма:
    - чете брой елементи `n` от потребителя
    - проверява дали `n` е положително число
    - чете `n` цели числа в масив
    - отпечатва елементите на масива на екрана
*/
#include <stdio.h>

int main()
{
    // Декларираме променлива за брой елементи
    int n;
    printf("Vuvedete broi elementi: ");
    scanf("%d", &n);

    // Условие: Проверяваме дали брой елементите е валиден (положителен)
    if (n <= 0)
    {
        printf("Greshka! Broyt elementi mora da e pozitiven!\n");
        return 1;
    }

    // Декларираме динамичен масив
    int masiv[n];

    // Въвеждаме елементите в масива
    printf("Vuvedete elementite:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d (index3 %d): ", i + 1, i);
        scanf("%d", &masiv[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int nn = masiv[i];
        for (int j = 0; j < n; j++)
        {
            int mm = masiv[j];
            if (nn < mm)
            {
                int temp = masiv[i];
                masiv[i] = masiv[j];
                masiv[j] = temp;
            }
        }
    }

    // Отпечатваме масива
    printf("\nMasivyt:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", masiv[i]);
    }
    printf("\n");

    return 0;
}
