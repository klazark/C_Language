#include<stdio.h>

int main() {
    
    int n;
    
    printf("n = ");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("%d\n", i);
    }
    
    // Вариант 2: Със while цикъл
    
    int i = 1;
    while(i <= n) {
        printf("%d\n", i);
        i++;
    }
    
    
    // Вариант 3: Със do-while цикъл
    
    int i = 1;
    do {
        printf("%d\n", i);
        i++;
    } while(i <= n);
    
    
    return 0;
}
