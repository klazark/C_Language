#include<stdio.h>

int main() {
    int k, n;
    int number;
    int count = 0;
    int digits;
    int temp;
    
    // Въвеждане на k (броят цифри)
    scanf("%d", &k);
    
    // Въвеждане на n (броят числа)
    scanf("%d", &n);
    
    // Въвеждане и проверка на n на брой числа
    for (int i = 0; i < n; i++) {
        scanf("%d", &number);
        
        // Преброяване на цифрите в числото
        digits = 0;
        temp = number;
        
        // Ако числото е 0, то има 1 цифра
        if (temp == 0) {
            digits = 1;
        } else {
            // Преброяване на цифрите чрез деление на 10
            while (temp != 0) {
                digits++;
                temp = temp / 10;
            }
        }
        
        // Проверка дали числото има точно k цифри
        if (digits == k) {
            count++;
        }
    }
    
    // Извеждане на резултата
    printf("%d\n", count);
    
    return 0;
}
