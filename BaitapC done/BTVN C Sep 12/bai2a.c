#include <stdio.h>

int main() {
    int soHang, i, j;

    printf("Nhap so hang: ");
    scanf("%d", &soHang);

    for (i = 1; i <= soHang; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
