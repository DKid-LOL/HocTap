#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void xoa_man_hinh() {
    system("cls");
}

int main() {
    int chon;
    int* mang = NULL;
    int soLuong = 0;

    while (1) {
        printf("+----------------------------------------------------------------------------------------------+\n");
        printf("|                          KHONG KHO KHI TA BIET TU DUY                                        |\n");
        printf("|               90%% THANH CONG PHU THUOC VAO SU CHAM CHI CAN CU                                |\n");
        printf("+----------------------------------------------------------------------------------------------+\n");
        printf("|                  1. NhapDuLieu |2. Xuly |3. Timkiem |4. Thoat                                |\n");
        printf("+----------------------------------------------------------------------------------------------+\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("Nhap so luong phan tu: ");
                scanf("%d", &soLuong);
                if (soLuong > 0) {
                    mang = (int*)malloc(soLuong * sizeof(int));
                    if (mang == NULL) {
                        printf("Loi cap phat bo nho.\n");
                        return 1;
                    }
                    printf("Nhap gia tri cho cac phan tu theo thang diem 20:\n");
                    for (int i = 0; i < soLuong; i++) {
                        printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
                        scanf("%d", &mang[i]);
                    }
                    printf("Da nhap du lieu xong.\n");
                } else {
                    printf("So luong phan tu phai lon hon 0.\n");
                }
                break;
            case 2:
                if (mang != NULL) {
                    int max = INT_MIN;
                    int min = INT_MAX;
                    for (int i = 0; i < soLuong; i++) {
                        if (mang[i] > max) {
                            max = mang[i];
                        }
                        if (mang[i] < min) {
                            min = mang[i];
                        }
                    }
                    printf("Gia tri lon nhat: %d\n", max);
                    printf("Gia tri nho nhat: %d\n", min);
                } else {
                    printf("Ban chua nhap du lieu. Vui long chon muc NhapDuLieu truoc.\n");
                }
                break;
            case 3:
                if (mang != NULL) {
                    int max = INT_MIN;
                    int max_index = -1;
                    int nearest = INT_MAX;
                    for (int i = 0; i < soLuong; i++) {
                        if (mang[i] > max) {
                            max = mang[i];
                            max_index = i;
                        }
                    }
                    for (int i = 0; i < soLuong; i++) {
                        if (i != max_index && abs(max - mang[i]) < abs(max - nearest)) {
                            nearest = mang[i];
                        }
                    }
                    printf("Phan tu co gia tri gan nhat voi gia tri lon nhat: %d\n", nearest);
                } else {
                    printf("Ban chua nhap du lieu. Vui long chon muc NhapDuLieu truoc.\n");
                }
                break;
            case 4:
                if (mang != NULL) {
                    free(mang);
                }
                printf("Chuong trinh ket thuc.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }

        printf("Ban co muon quay lai menu hay khong? (yes/i do, no/i don't): ");
        char traLoi[10];
        scanf("%s", traLoi);
        if (traLoi[0] == 'n' || traLoi[0] == 'N' || traLoi[0] == '0') {
            break;
        } else if (traLoi[0] == 'x' || traLoi[0] == 'X') {
            xoa_man_hinh();
        }
    }

    return 0;
}
