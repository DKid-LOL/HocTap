#include <stdio.h>

// Hàm tính tổng hai số
int tinhTong(int a, int b) {
    int tong = a + b; // Trả về giá trị tổng
}

int main() {
    int x = 5;
    int y = 3;

    int ketQua = tinhTong(x, y); // Gọi hàm tinhTong và lưu kết quả vào biến ketQua
    printf("Tổng của %d và %d là %d\n", x, y, ketQua);

    return 0;
}
