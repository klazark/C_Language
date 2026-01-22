#include <stdio.h>

// int main(void) {
//     int grade = 75;
    
//     if (grade >= 76) {
//         printf("✅ Положена оценка!\n");
//     } else {
//         printf("❌ Неположена оценка.\n");
//     }
    
//     return 0;
// }

int main(void) {
    int countdown = 5;
  
    while (countdown > 0) {
        printf("Остават: %d\n", countdown);
        countdown = countdown - 1;  // Намаляваме
    }
  
    printf("🚀 Старт!\n");
    return 0;
}