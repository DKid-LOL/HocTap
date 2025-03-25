#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa struct Nhân viên
struct NhanVien {
    char Ten[50];
    int MSNV;
    char ChucVu[50];
    float Luong;
    char SoThich[100];
    int NamSinh;
};

// Hàm kiểm tra năm sinh hợp lệ
int NamSinhHopLe(int namSinh) {
    int namHienTai = 2022;
    return (namHienTai - namSinh >= 18 && namHienTai - namSinh <= 50); 
}

// Hàm nhập thông tin cho một nhân viên
void NhapNhanVien(struct NhanVien *nv) {
    printf("Nhap ten: ");
    scanf("%s", nv->Ten);
    printf("Nhap MSNV (khac nhau): ");
    scanf("%d", &nv->MSNV);
    printf("Nhap chuc vu: ");
    scanf("%s", nv->ChucVu);
    printf("Nhap luong: ");
    scanf("%f", &nv->Luong);
    printf("Nhap so thich: ");
    scanf("%s", nv->SoThich);
    printf("Nhap nam sinh: ");
    scanf("%d", &nv->NamSinh);
}

// Hàm sắp xếp mảng theo lương
void SapXepLuong(struct NhanVien *dsNhanVien, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsNhanVien[i].Luong > dsNhanVien[j].Luong) {
                // Hoán đổi vị trí của hai nhân viên
                struct NhanVien temp = dsNhanVien[i];// temp là biến tạm
                dsNhanVien[i] = dsNhanVien[j];
                dsNhanVien[j] = temp;
            }
        }
    }
}

// Hàm in danh sách nhân viên có cùng sở thích
void NhanVienCoCungSoThich(struct NhanVien *dsNhanVien, int n) {
    char cungsothich[100];
    printf("Nhap so thich can tim: ");
    scanf("%s", cungsothich);
    
    printf("Danh sach nhan vien co so thich \"%s\":\n", cungsothich);// \"%s\ : \ đánh dấu kí tự " là kí tự bình thường trong chuỗi
    for (int i = 0; i < n; i++) {
        if (strcmp(dsNhanVien[i].SoThich, cungsothich) == 0) {
            printf("Ten: %s, MSNV: %d, Chuc vu: %s, Luong: %.2f, Nam sinh: %d\n",
                   dsNhanVien[i].Ten, dsNhanVien[i].MSNV, dsNhanVien[i].ChucVu,
                   dsNhanVien[i].Luong, dsNhanVien[i].NamSinh);
        }
    }
}

// Hàm in danh sách nhân viên có tuổi từ 20 đến 30
void NhanVienTu20Den30(struct NhanVien *dsNhanVien, int n) {
    int currentYear = 2022;
    printf("Danh sach nhan vien tu 20 den 30 tuoi:\n");
    for (int i = 0; i < n; i++) {
        int tuoi = currentYear - dsNhanVien[i].NamSinh;
        if (tuoi >= 20 && tuoi <= 30) {
            printf("Ten: %s, MSNV: %d, Chuc vu: %s, Luong: %.2f, Tuoi: %d\n",
                   dsNhanVien[i].Ten, dsNhanVien[i].MSNV, dsNhanVien[i].ChucVu,
                   dsNhanVien[i].Luong, tuoi);
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);

    // Cấp phát động mảng chứa các nhân viên
    struct NhanVien *dsNhanVien = (struct NhanVien *)malloc(n * sizeof(struct NhanVien));

    // Nhập thông tin cho từng nhân viên
    for (int i = 0; i < n; i++) {
        NhapNhanVien(&dsNhanVien[i]);
        // Kiểm tra MSNV đã tồn tại hay chưa
        for (int j = 0; j < i; j++) {
            if (dsNhanVien[i].MSNV == dsNhanVien[j].MSNV) {
                printf("MSNV da ton tai. Vui long nhap lai.\n");
                i--;
                break;
            }
        }
        // Kiểm tra năm sinh hợp lệ
        if (!NamSinhHopLe(dsNhanVien[i].NamSinh)) {
            printf("Nam sinh khong hop le. Vui long nhap lai.\n");
            i--;
        }
    }

    // Sắp xếp danh sách theo lương
    SapXepLuong(dsNhanVien, n);

    // In danh sách nhân viên đã sắp xếp
    printf("Danh sach nhan vien sau khi sap xep theo luong:\n");
    for (int i = 0; i < n; i++) {
        printf("Ten: %s, MSNV: %d, Chuc vu: %s, Luong: %.2f, So thich: %s, Nam sinh: %d\n",
               dsNhanVien[i].Ten, dsNhanVien[i].MSNV, dsNhanVien[i].ChucVu,
               dsNhanVien[i].Luong, dsNhanVien[i].SoThich, dsNhanVien[i].NamSinh);
    }

    // In danh sách nhân viên có cùng sở thích
    NhanVienCoCungSoThich(dsNhanVien, n);

    // In danh sách nhân viên có tuổi từ 20 đến 30
    NhanVienTu20Den30(dsNhanVien, n);

    // Giải phóng bộ nhớ sau khi sử dụng xong
    free(dsNhanVien);

    return 0;
}
