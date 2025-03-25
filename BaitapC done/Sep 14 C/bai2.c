#include <stdio.h>

int main() {
    int n;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu phai lon hon 0.\n");
        return 1;
    }

    int mang[n];
    int i, j;

    for (i = 0; i < n; i++) {
        printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);
        for (j = 0; j < i; j++) {
            if (mang[i] == mang[j]) {
                printf("Gia tri da ton tai trong mang. Hay nhap lai.\n");
                i--;
                break;
            }
        }
    }

    printf("Cac gia tri trong mang:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");

    int max = mang[0];
    int min = mang[0];
    for (i = 1; i < n; i++) {
        if (mang[i] > max) {
            max = mang[i];
        }
        if (mang[i] < min) {
            min = mang[i];
        }
    }
    printf("Gia tri lon nhat trong mang: %d\n", max);
    printf("Gia tri nho nhat trong mang: %d\n", min);

    int tong = 0;
    for (i = 0; i < n; i++) {
        tong += mang[i];
    }
    printf("Tong gia tri cac phan tu trong mang: %d\n", tong);

    int timSo;
    printf("Nhap so ban muon tim trong mang: ");
    scanf("%d", &timSo);
    int timThay = 0;
    for (i = 0; i < n; i++) {
        if (mang[i] == timSo) {
            timThay = 1;
            break;
        }
    }
    if (timThay) {
        printf("So %d ton tai trong mang.\n", timSo);
    } else {
        printf("So %d khong ton tai trong mang.\n", timSo);
    }

    return 0;
}
