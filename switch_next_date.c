// Задача: Въвежда се дата - ден и месец (цели числа) за 2026 год.
// Да се изведе следващата дата (ден и месец като цели числа).

#include<stdio.h>

int main() {
    int day, month;
    int next_day, next_month;
    
    printf("Въведете ден: ");
    scanf("%d", &day);
    
    printf("Въведете месец: ");
    scanf("%d", &month);
    
    // Проверка за валидност на датата
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Невалидна дата!\n");
        return 1;
    }
    
    // Определяне на броя дни в месеца (2026 не е високосна година)
    int days_in_month;
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days_in_month = 31;
            break;
        case 4: case 6: case 9: case 11:
            days_in_month = 30;
            break;
        case 2:
            days_in_month = 28; // 2026 не е високосна година
            break;
        default:
            days_in_month = 0;
            break;
    }
    
    // Проверка дали денят е валиден за дадения месец
    if (day > days_in_month) {
        printf("Невалидна дата! В месец %d има само %d дни.\n", month, days_in_month);
        return 1;
    }
    
    // Изчисляване на следващата дата
    if (day < days_in_month) {
        // Не сме на последния ден от месеца
        next_day = day + 1;
        next_month = month;
    } else {
        // Последен ден от месеца - преминаваме към следващия месец
        next_day = 1;
        if (month < 12) {
            next_month = month + 1;
        } else {
            // Последен ден от годината - преминаваме към 1 януари
            next_month = 1;
        }
    }
    
    printf("Следващата дата е: %d.%d.2026\n", next_day, next_month);
    
    return 0;
}