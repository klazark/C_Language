#include <stdio.h>
#define MAX_STUDENTS 30 // max_u
#define MAX_SUBJECTS 20 // max_p
int main()
{

    int n, m;
    int marks[MAX_STUDENTS][MAX_SUBJECTS];

    do
    {
        printf("n= (n<=%d):", MAX_STUDENTS);
        scanf("%d", &n);
    } while (n > MAX_STUDENTS || n < 1);

    do
    {
        printf("m= (m<=%d):", MAX_SUBJECTS);
        scanf("%d", &m);
    } while (m > MAX_SUBJECTS || m < 1);

    // Въвеждане на оценките
    int i, k;
    for (i = 0; i < n; i++)            // за всеки ученик
        for (k = 0; k < m; k++)        // за всеки предмет
            printf("%d", marks[i][k]); // отпечатай оценката
    do
    {
        printf("mark %d for student %d=", k + 1, i + 1);
        scanf("%d", &marks[i][k]);
    } while (marks[i][k] < 2 || marks[i][k] > 6);

    float avr_STUDENTS[MAX_STUDENTS]; // avr_u
    for (i = 0; i < n; i++)
    {
        avr_STUDENTS[i] = 0;
        for (k = 0; k < m; k++)
            avr_STUDENTS[i] = avr_STUDENTS[i] + marks[i][k]; // сумирай всички оценки на ученика i (от всички предмети)
        avr_STUDENTS[i] = avr_STUDENTS[i] / m;               // дели сумата на броя предмети m за да получиш средната оценка
    }
}
