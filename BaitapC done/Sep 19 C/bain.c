#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa struct NhanVien
struct NhanVien {
    char Ten[50];
    int MSNV;
    char ChucVu[50];
    float Luong;
    char SoThich[100];
    int NamSinh;
};

// Hàm kiểm tra năm sinh hợp lệ (trên 18 và dưới 50 so với năm 2022)
int KiemTraNamSinh(int namSinh) {
    int namHienTai = 2022;
    return (namHienTai - namSinh >= 18 && namHienTai - namSinh <= 50);
}

// Hàm so sánh Lương để sử dụng trong qsort
int SoSanhLuong(const void *a, const void *b) {
    struct NhanVien *nhanVienA = (struct NhanVien *)a;
    struct NhanVien *nhanVienB = (struct NhanVien *)b;
    if (nhanVienA->Luong < nhanVienB->Luong) return -1;
    if (nhanVienA->Luong > nhanVienB->Luong) return 1;
    return 0;
}

int main() {
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);

    // Cấp phát động mảng NhanVien
    struct NhanVien *nhanVienArr = (struct NhanVien *)malloc(n * sizeof(struct NhanVien));

    // Nhập thông tin cho từng nhân viên
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin cho nhan vien thu %d:\n", i + 1);
        printf("Ten: ");
        scanf("%s", nhanVienArr[i].Ten);

        int msnv;
        do {
            printf("MSNV (phai khac nhau): ");
            scanf("%d", &msnv);

            // Kiểm tra xem MSNV đã tồn tại chưa
            int msDaTonTai = 0;
            for (int j = 0; j < i; j++) {
                if (nhanVienArr[j].MSNV == msnv) {
                    msDaTonTai = 1;
                    break;
                }
            }
            
            if (msDaTonTai) {
                printf("MSNV da ton tai. Hay nhap lai.\n");
            } else {
                nhanVienArr[i].MSNV = msnv;
            }
        } while (msDaTonTai);

        printf("Chuc Vu: ");
        scanf("%s", nhanVienArr[i].ChucVu);

        printf("Luong: ");
        scanf("%f", &nhanVienArr[i].Luong);

        printf("So Thich: ");
        scanf("%s", nhanVienArr[i].SoThich);

        do {
            printf("Nam Sinh (tu 1900 den 2004): ");
            scanf("%d", &nhanVienArr[i].NamSinh);
        } while (!KiemTraNamSinh(nhanVienArr[i].NamSinh));
    }

    // Sắp xếp mảng theo Lương
    qsort(nhanVienArr, n, sizeof(struct NhanVien), SoSanhLuong);

    // In ra mảng sau khi sắp xếp
    printf("\nDanh sach nhan vien sau khi sap xep theo Luong:\n");
    for (int i = 0; i < n; i++) {
        printf("Ten: %s, MSNV: %d, Chuc Vu: %s, Luong: %.2f, So Thich: %s, Nam Sinh: %d\n",
               nhanVienArr[i].Ten, nhanVienArr[i].MSNV, nhanVienArr[i].ChucVu,
               nhanVienArr[i].Luong, nhanVienArr[i].SoThich, nhanVienArr[i].NamSinh);
    }

    // Đếm số nhân viên có cùng sở thích
    char sotochuc[100];
    printf("\nNhap so thich can dem: ");
    scanf("%s", sotochuc);
    int demSoThich = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(nhanVienArr[i].SoThich, sotochuc) == 0) {
            demSoThich++;
        }
    }
    printf("So nhan vien co cung so thich %s la: %d\n", sotochuc, demSoThich);

    // Tìm người có tuổi từ 20 đến 30 tuổi
    printf("\nNhung nhan vien co tuoi tu 20 den 30 tuoi:\n");
    int namHienTai = 2022;
    for (int i = 0; i < n; i++) {
        int tuoi = namHienTai - nhanVienArr[i].NamSinh;
        if (tuoi >= 20 && tuoi <= 30) {
            printf("Ten: %s, MSNV: %d, Chuc Vu: %s, Tuoi: %d\n",
                   nhanVienArr[i].Ten, nhanVienArr[i].MSNV, nhanVienArr[i].ChucVu, tuoi);
        }
    }

    // Thêm 2 phần tử vào vị trí bất kỳ
    int viTri1, viTri2;
    printf("\nNhap vi tri thu nhat can them (0-%d): ", n - 1);
    scanf("%d", &viTri1);
    printf("Nhap vi tri thu hai can them (0-%d): ", n - 1);
    scanf("%d", &viTri2);

    // Kiểm tra nếu viTri1 và viTri2 hợp lệ
    if (viTri1 >= 0 && viTri1 < n && viTri2 >= 0 && viTri2 < n) {
        // Nhập thông tin cho phần tử thứ nhất
        printf("\nNhap thong tin cho phan tu thu nhat:\n");
        printf("Ten: ");
        scanf("%s", nhanVienArr[viTri1].Ten);

        int msnv;
        do {
            printf("MSNV (phai khac nhau): ");
            scanf("%d", &msnv);

            // Kiểm tra xem MSNV đã tồn tại chưa
            int msDaTonTai = 0;
            for (int j = 0; j < n; j++) {
                if (j != viTri1 && nhanVienArr[j].MSNV == msnv) {
                    msDaTonTai = 1;
                    break;
                }
            }

            if (msDaTonTai) {
                printf("MSNV da ton tai. Hay nhap lai.\n");
            } else {
                nhanVienArr[viTri1].MSNV = msnv;
            }
        } while (msDaTonTai);

        printf("Chuc Vu: ");
        scanf("%s", nhanVienArr[viTri1].ChucVu);

        printf("Luong: ");
        scanf("%f", &nhanVienArr[viTri1].Luong);

        printf("So Thich: ");
        scanf("%s", nhanVienArr[viTri1].SoThich);

        do {
            printf("Nam Sinh (tu 1900 den 2004): ");
            scanf("%d", &nhanVienArr[viTri1].NamSinh);
        } while (!KiemTraNamSinh(nhanVienArr[viTri1].NamSinh));

        // Nhập thông tin cho phần tử thứ hai
        printf("\nNhap thong tin cho phan tu thu hai:\n");
        printf("Ten: ");
        scanf("%s", nhanVienArr[viTri2].Ten);

        do {
            printf("MSNV (phai khac nhau): ");
            scanf("%d", &msnv);

            // Kiểm tra xem MSNV đã tồn tại chưa
            int msDaTonTai = 0;
            for (int j = 0; j < n; j++) {
                if (j != viTri2 && nhanVienArr[j].MSNV == msnv) {
                    msDaTonTai = 1;
                    break;
                }
            }

            if (msDaTonTai) {
                printf("MSNV da ton tai. Hay nhap lai.\n");
            } else {
                nhanVienArr[viTri2].MSNV = msnv;
            }
        } while (msDaTonTai);

        printf("Chuc Vu: ");
        scanf("%s", nhanVienArr[viTri2].ChucVu);

        printf("Luong: ");
        scanf("%f", &nhanVienArr[viTri2].Luong);

        printf("So Thich: ");
        scanf("%s", nhanVienArr[viTri2].SoThich);

        do {
            printf("Nam Sinh (tu 1900 den 2004): ");
            scanf("%d", &nhanVienArr[viTri2].NamSinh);
        } while (!KiemTraNamSinh(nhanVienArr[viTri2].NamSinh));

        // In ra mảng sau khi thêm
        printf("\nDanh sach nhan vien sau khi them phan tu:\n");
        for (int i = 0; i < n; i++) {
            printf("Ten: %s, MSNV: %d, Chuc Vu: %s, Luong: %.2f, So Thich: %s, Nam Sinh: %d\n",
                   nhanVienArr[i].Ten, nhanVienArr[i].MSNV, nhanVienArr[i].ChucVu,
                   nhanVienArr[i].Luong, nhanVienArr[i].SoThich, nhanVienArr[i].NamSinh);
        }
    } else {
        printf("Vi tri khong hop le.\n");
    }

    // Giải phóng bộ nhớ
    free(nhanVienArr);

    return 0;
}
