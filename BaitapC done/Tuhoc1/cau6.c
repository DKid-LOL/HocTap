#include <stdio.h>
// Viết chương trình khai báo 3 biến, value của 3 biến nhập từ bàn phím, Xuất ra màn hình giá tri max min trong 3 biến.
int main() {
    int a, b, c;

    printf("Bien a : ");
    scanf("%d", &a);

    printf("Bien b : ");
    scanf("%d", &b);

    printf("Bien c : ");
    scanf("%d", &c);

    int max = a;
    int min = a;

    if (b > max) {max = b;}
    if (c > max) {max = c;}
    if (b < min) {min = b;}
    if (c < min) {min = c;}

    printf("Max : %d\n", max);
    printf("Min : %d\n", min);

    return 0;
}
