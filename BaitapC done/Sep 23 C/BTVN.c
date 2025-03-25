/*Bài này các em phải 2 cách local variable and global variable.

Bai 2:tao struct hocvien voi cac thuoc tinh sau: name, class, mshv, diemPre,diemEPC,sothich.Viet chuong trinh nhap mang kieu du lieu struct.(luu y dung cap phat dong, tao ra cac functions)
a, Viet chuong trinh nhap gia tri tu ban phim.
  diem so theo  thang diem  20, mshv ko duoc trung nhau.
b, Xuat ra gia tri cac phan tu trong mang.
d,  Nguoi dung nhap 2 gia tri bat ky(int), tim max min epc,pre trong khoang 2 gia tri vua nhap.
e, viet chuong trinh sap xep cac phan tu  giam  dan theo name.
h,Dem bao nhieu ban co cung so thich va hien ten nhung ban do.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Định nghĩa struct HocVien
struct HocVien {
    char name[50];
    char class[10];
    char mshv[10];
    float diemPre;
    float diemEPC;
    char sothich[100];
};

// Khai báo một mảng chứa thông tin học viên (biến global)
struct HocVien *hocvien = NULL;
int numHocVien = 0; // Số lượng học viên hiện tại trong mảng

// Hàm nhập thông tin của một học viên từ bàn phím
void nhapHocVien() {
    struct HocVien hv;

    printf("Nhap ten: ");
    scanf("%s", hv.name);

    printf("Nhap lop: ");
    scanf("%s", hv.class);

    printf("Nhap ma so hoc vien: ");
    scanf("%s", hv.mshv);

    // Kiểm tra xem mshv đã tồn tại chưa
    for (int i = 0; i < numHocVien; i++) {
        if (strcmp(hv.mshv, hocvien[i].mshv) == 0) {
            printf("Ma so hoc vien da ton tai. Vui long nhap lai.\n");
            return;
        }
    }

    printf("Nhap diem Pre: ");
    scanf("%f", &(hv.diemPre));

    printf("Nhap diem EPC: ");
    scanf("%f", &(hv.diemEPC));

    printf("Nhap so thich: ");
    scanf("%s", hv.sothich);

    numHocVien++;

    // Cấp phát động thêm một slot cho danh sách học viên
    hocvien = (struct HocVien *)realloc(hocvien, numHocVien * sizeof(struct HocVien));
    if (hocvien == NULL) {
        printf("Loi cap phat bo nho.\n");
        exit(1);
    }

    // Lưu thông tin học viên vào danh sách
    hocvien[numHocVien - 1] = hv;
}

// Hàm xuất thông tin của một học viên
void xuatHocVien(struct HocVien *hv) {
    printf("Ten: %s\n", hv->name);
    printf("Lop: %s\n", hv->class);
    printf("Ma so hoc vien: %s\n", hv->mshv);
    printf("Diem Pre: %.2f\n", hv->diemPre);
    printf("Diem EPC: %.2f\n", hv->diemEPC);
    printf("So thich: %s\n", hv->sothich);
}

// Hàm tìm giá trị lớn nhất và nhỏ nhất trong khoảng
void timMaxMinEPCPre(float a, float b) {
    float maxEPC = -1.0, minEPC = 21.0;
    float maxPre = -1.0, minPre = 21.0;

    for (int i = 0; i < numHocVien; i++) {
        if (hocvien[i].diemEPC >= a && hocvien[i].diemEPC <= b) {
            if (hocvien[i].diemEPC > maxEPC) {
                maxEPC = hocvien[i].diemEPC;
            }
            if (hocvien[i].diemEPC < minEPC) {
                minEPC = hocvien[i].diemEPC;
            }
        }
        if (hocvien[i].diemPre >= a && hocvien[i].diemPre <= b) {
            if (hocvien[i].diemPre > maxPre) {
                maxPre = hocvien[i].diemPre;
            }
            if (hocvien[i].diemPre < minPre) {
                minPre = hocvien[i].diemPre;
            }
        }
    }

    if (maxEPC != -1.0) {
        printf("Diem EPC lon nhat trong khoang [%f, %f]: %.2f\n", a, b, maxEPC);
    } else {
        printf("Khong co diem EPC trong khoang [%f, %f]\n", a, b);
    }

    if (minEPC != 21.0) {
        printf("Diem EPC nho nhat trong khoang [%f, %f]: %.2f\n", a, b, minEPC);
    } else {
        printf("Khong co diem EPC trong khoang [%f, %f]\n", a, b);
    }

    if (maxPre != -1.0) {
        printf("Diem Pre lon nhat trong khoang [%f, %f]: %.2f\n", a, b, maxPre);
    } else {
        printf("Khong co diem Pre trong khoang [%f, %f]\n", a, b);
    }

    if (minPre != 21.0) {
        printf("Diem Pre nho nhat trong khoang [%f, %f]: %.2f\n", a, b, minPre);
    } else {
        printf("Khong co diem Pre trong khoang [%f, %f]\n", a, b);
    }
}

// Hàm sắp xếp danh sách học viên giảm dần theo tên
void sapXepGiamDanTheoTen() {
    struct HocVien temp;
    for (int i = 0; i < numHocVien - 1; i++) {
        for (int j = i + 1; j < numHocVien; j++) {
            if (strcmp(hocvien[i].name, hocvien[j].name) < 0) {
                temp = hocvien[i];
                hocvien[i] = hocvien[j];
                hocvien[j] = temp;
            }
        }
    }
}

// Hàm đếm số học viên có cùng sở thích và hiển thị tên của họ
void demVaHienThiHocVienCungSoThich(char *sothich) {
    int count = 0;

    for (int i = 0; i < numHocVien; i++) {
        if (strcmp(hocvien[i].sothich, sothich) == 0) {
            count++;
            printf("Ten hoc vien co so thich '%s': %s\n", sothich, hocvien[i].name);
        }
    }

    if (count == 0) {
        printf("Khong co hoc vien nao co so thich '%s'\n", sothich);
    } else {
        printf("Tong so hoc vien co so thich '%s' la %d\n", sothich, count);
    }
}

int main() {
    int choice;
    float a, b;
    char sothich[100];

    while (1) {
        printf("\nMENU:\n");
        printf("1. Nhap thong tin hoc vien\n");
        printf("2. Xuat thong tin hoc vien\n");
        printf("3. Tim max min diem EPC va diem Pre trong khoang\n");
        printf("4. Sap xep giam dan theo ten\n");
        printf("5. Dem va hien thi hoc vien cung so thich\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapHocVien();
                break;
            case 2:
                for (int i = 0; i < numHocVien; i++) {
                    xuatHocVien(&hocvien[i]);
                }
                break;
            case 3:
                printf("Nhap hai gia tri a va b: ");
                scanf("%f %f", &a, &b);
                timMaxMinEPCPre(a, b);
                break;
            case 4:
                sapXepGiamDanTheoTen();
                printf("Danh sach sau khi sap xep:\n");
                for (int i = 0; i < numHocVien; i++) {
                    xuatHocVien(&hocvien[i]);
                }
                break;
            case 5:
                printf("Nhap so thich can tim: ");
                scanf("%s", sothich);
                demVaHienThiHocVienCungSoThich(sothich);
                break;
            case 6:
                free(hocvien); // Giải phóng bộ nhớ khi kết thúc chương trình
                printf("Ket thuc chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}

