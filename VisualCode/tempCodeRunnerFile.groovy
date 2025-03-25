#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess;
    int number;
    int attempts = 0;
    
    // Khởi tạo ngẫu nhiên số cần đoán từ 1 đến 100
    srand(time(NULL));
    number = rand() % 100 + 1;
    
    printf("Chào mừng bạn đến với trò chơi đoán số!\n");
    
    do {
        printf("Nhập một số từ 1 đến 100: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess > number) {
            printf("Số bạn đoán lớn hơn số cần tìm. Hãy thử lại!\n");
        } else if (guess < number) {
            printf("Số bạn đoán nhỏ hơn số cần tìm. Hãy thử lại!\n");
        } else {
            printf("Chúc mừng! Bạn đã đoán đúng số %d trong %d lần thử!\n", number, attempts);
        }
        
    } while (guess != number);
    
    return 0;
}
