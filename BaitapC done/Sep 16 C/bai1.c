#include <stdio.h>
#include <string.h>

struct hocvien {
    char name[30];
    char classroom[10];
    char mshv[10];
    int year;
    char address[30];
    float PRE;
    float EPC;
    char sothich[30];
};

typedef struct hocvien Hocvien;

void nhapHocVien(Hocvien *hv) {
    printf("Nhap ten: ");
    scanf("%s", hv->name);
    printf("Nhap lop: ");
    scanf("%s", hv->classroom);
    printf("Nhap ma so sinh vien: ");
    scanf("%s", hv->mshv);
    printf("Nhap nam sinh: ");
    scanf("%d", &hv->year);
    printf("Nhap dia chi: ");
    scanf("%s", hv->address);
    printf("Nhap diem PRE: ");
    scanf("%f", &hv->PRE);
    printf("Nhap diem EPC: ");
    scanf("%f", &hv->EPC);
    printf("Nhap so thich: ");
    scanf("%s", hv->sothich);
}

void xuatHocVien(Hocvien *hv) {
    printf("Ten: %s\n", hv->name);
    printf("Lop: %s\n", hv->classroom);
    printf("Ma so sinh vien: %s\n", hv->mshv);
    printf("Nam sinh: %d\n", hv->year);
    printf("Dia chi: %s\n", hv->address);
    printf("Diem PRE: %.2f\n", hv->PRE);
    printf("Diem EPC: %.2f\n", hv->EPC);
    printf("So thich: %s\n", hv->sothich);
}

int main() {
    int n;
    printf("Nhap so luong hoc vien: ");
    scanf("%d", &n);

    Hocvien hvArr[n];

    // Nhập thông tin cho mảng học viên
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho hoc vien thu %d:\n", i + 1);
        nhapHocVien(&hvArr[i]);
    }

    // 1. Xuất thông tin phần tử
    for (int i = 0; i < n; i++) {
        printf("Thong tin hoc vien thu %d:\n", i + 1);
        xuatHocVien(&hvArr[i]);
    }

    // 2. Tìm kiếm người có điểm PRE max và xuất ra thông tin người đó
    float maxPRE = hvArr[0].PRE;
    int indexMaxPRE = 0;
    for (int i = 1; i < n; i++) {
        if (hvArr[i].PRE > maxPRE) {
            maxPRE = hvArr[i].PRE;
            indexMaxPRE = i;
        }
    }
    printf("Hoc vien co diem PRE cao nhat:\n");
    xuatHocVien(&hvArr[indexMaxPRE]);

    // 3. Xuất ra màn hình có quê ở HaNoi và điểm TB > 7
    printf("Hoc vien co que o HaNoi va diem TB > 7:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(hvArr[i].address, "HaNoi") == 0 && (hvArr[i].PRE + hvArr[i].EPC) / 2 > 7) {
            xuatHocVien(&hvArr[i]);
        }
    }

    // 4. Tìm kiếm thông tin học viên theo tên
    char searchName[30];
    printf("Nhap ten hoc vien can tim kiem: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(hvArr[i].name, searchName) == 0) {
            printf("Thong tin hoc vien can tim:\n");
            xuatHocVien(&hvArr[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay hoc vien co ten \"%s\".\n", searchName);
    }

    // 5. Xuất ra màn hình số lượng người có cùng sở thích
    char searchSothich[30];
    printf("Nhap so thich can tim kiem: ");
    scanf("%s", searchSothich);
    int countSothich = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(hvArr[i].sothich, searchSothich) == 0) {
            countSothich++;
        }
    }
    printf("So luong hoc vien co cung so thich \"%s\": %d\n", searchSothich, countSothich);

    return 0;
}
