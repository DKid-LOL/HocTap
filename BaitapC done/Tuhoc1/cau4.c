// Cau 4: Viet chuong trinh khoi tao 2 bien kieu int, tinh tong ,hieu,thuong 2 bien do. xuat ra man hinh value, address,
//  kích thước data type (dung ham sizeof() ) của variable.
#include <stdio.h>

int main() {
    int a,b;
    printf("Nhap gia tri cho a: ");
    scanf("%d", &a);
    printf("Nhap gia tri cho b: ");
    scanf("%d", &b);

    int tong = a + b;
    int hieu = a - b;
    float thuong = (float)a / b;

    printf("\nGia tri cua a: %d", a);
    printf("\nDia chi cua a: %p", (void *)&a);
    printf("\nKich thuoc cua a: %lu byte", sizeof(a));

    printf("\nGia tri cua b: %d", b);
    printf("\nDia chi cua b: %p", (void *)&b);
    printf("\nKich thuoc cua b: %lu byte", sizeof(b));

    printf("\nTong: %d", tong);
    printf("\nHieu: %d", hieu);
    printf("\nThuong: %.2f", thuong);

    return 0;
}
