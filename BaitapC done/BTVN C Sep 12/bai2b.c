#include <stdio.h>

int main() {
    int soHang, i, j;

    printf("Nhap so hang: ");
    scanf("%d", &soHang);

    for (i = soHang; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
