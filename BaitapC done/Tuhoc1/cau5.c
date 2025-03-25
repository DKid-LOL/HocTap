#include <stdio.h>
/*Viết chương trình nhập số từ bàn phím:
      - Nếu người dùng nhập vào số nguyên lẻ thì xuất ra màn hình:"Đây là số nguyên lẻ".
      - Nếu người dùng nhập vào số nguyên chẵn thì xuất ra màn hình:"Đây là số nguyên chẵn".*/
int main() {
    int a;

    printf("Nhap so nguyen a: ");
    scanf("%d", &a);

    if (a % 2 == 0) {
        printf("\nDay la so nguyen chan");
    } 
    else {
        printf("\nDay la so nguyen le");
    }
    return 0;
}
