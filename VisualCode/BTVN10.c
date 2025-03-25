#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HocVien {
    char name[50];
    char class[20];
    char mshv[20];
    char address[100];
    float diemPre;
    float diemEPC;
};

void nhapHocVien(struct HocVien *hv, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin hoc vien thu %d:\n", i + 1);
        printf("Ten: ");
        fflush(stdin);
        gets(hv[i].name);
        printf("Lop: ");
        fflush(stdin);
        gets(hv[i].class);
        printf("Ma so hoc vien: ");
        fflush(stdin);
        gets(hv[i].mshv);
        printf("Dia chi: ");
        fflush(stdin);
        gets(hv[i].address);
        printf("Diem Pre: ");
        scanf("%f", &hv[i].diemPre);
        printf("Diem EPC: ");
        scanf("%f", &hv[i].diemEPC);
    }
}

void xuatHocVien(struct HocVien *hv, int n) {
    for (int i = 0; i < n; i++) {
        printf("Thong tin hoc vien thu %d:\n", i + 1);
        printf("Ten: %s\n", hv[i].name);
        printf("Lop: %s\n", hv[i].class);
        printf("Ma so hoc vien: %s\n", hv[i].mshv);
        printf("Dia chi: %s\n", hv[i].address);
        printf("Diem Pre: %.2f\n", hv[i].diemPre);
        printf("Diem EPC: %.2f\n", hv[i].diemEPC);
    }
}

void timMaxMinDiem(struct HocVien *hv, int n) {
    float maxDiem = hv[0].diemPre;
    float minDiem = hv[0].diemPre;
    for (int i = 1; i < n; i++) {
        if (hv[i].diemPre > maxDiem) {
            maxDiem = hv[i].diemPre;
        }
        if (hv[i].diemPre < minDiem) {
            minDiem = hv[i].diemPre;
        }
    }
    printf("Diem cao nhat: %.2f\n", maxDiem);
    printf("Diem thap nhat: %.2f\n", minDiem);
}

void sapXepGiamDan(struct HocVien *hv, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(hv[i].mshv, hv[j].mshv) < 0) {
                struct HocVien temp = hv[i];
                hv[i] = hv[j];
                hv[j] = temp;
            }
        }
    }
}

void xuatDiemTBMon(struct HocVien *hv, int n) {
    for (int i = 0; i < n; i++) {
        float diemTB = (hv[i].diemPre + hv[i].diemEPC) / 2;
        if (diemTB > 15 && hv[i].diemPre >= 12 && hv[i].diemEPC >= 12) {
            printf("Hoc vien %s co diem trung binh %.2f\n", hv[i].name, diemTB);
        }
    }
}

void timHocVienHaNoi(struct HocVien *hv, int n) {
    for (int i = 0; i < n; i++) {
        if (strstr(hv[i].address, "Ha Noi") != NULL) {
            printf("Hoc vien %s que o Ha Noi\n", hv[i].name);
        }
    }
}

void timHocVienTreNhat(struct HocVien *hv, int n) {
    int index = 0;
    float maxDiemTB = (hv[0].diemPre + hv[0].diemEPC) / 2;
    for (int i = 1; i < n; i++) {
        float diemTB = (hv[i].diemPre + hv[i].diemEPC) / 2;
        if (diemTB > maxDiemTB) {
            maxDiemTB = diemTB;
            index = i;
        }
    }
    printf("Hoc vien tre nhat co diem trung binh cao nhat la %s\n", hv[index].name);
}

void luuFile(struct HocVien *hv, int n, char *tenFile) {
    FILE *file = fopen(tenFile, "wb");
    if (file == NULL) {
        printf("Khong the mo file\n");
        return;
    }
    fwrite(hv, sizeof(struct HocVien), n, file);
    fclose(file);
    printf("Luu file thanh cong\n");
}

void moFile(char *tenFile) {
    FILE *file = fopen(tenFile, "rb");
    if (file == NULL) {
        printf("Khong the mo file\n");
        return;
    }
    struct HocVien hv;
    while (fread(&hv, sizeof(struct HocVien), 1, file) > 0) {
        printf("Ten: %s\n", hv.name);
        printf("Lop: %s\n", hv.class);
        printf("Ma so hoc vien: %s\n", hv.mshv);
        printf("Dia chi: %s\n", hv.address);
        printf("Diem Pre: %.2f\n", hv.diemPre);
        printf("Diem EPC: %.2f\n", hv.diemEPC);
    }
    fclose(file);
}

int main() {
    int n;
    printf("Nhap so luong hoc vien: ");
    scanf("%d", &n);
    struct HocVien *hv = (struct HocVien *)malloc(n * sizeof(struct HocVien));
    nhapHocVien(hv, n);

    int choice;
    do {
        printf("\n");
        printf("1. Nhap gia tri tu ban phim\n");
        printf("2. Xuat ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri max min cac mon trong mang va xuat ra man hinh gia tri\n");
        printf("4. Sap xep cac phan tu giam dan theo mshv\n");
        printf("5. Xuat ra man hinh hoc vien co diem tb > 15 va cac mon khong duoi 12 diem\n");
        printf("6. Tim hoc vien que o Ha Noi va co diem tb > 13\n");
        printf("7. Tim hoc vien tre nhat co diem tb cao nhat\n");
        printf("8. Luu file o che do binary\n");
        printf("9. Mo file o che do binary\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapHocVien(hv, n);
                break;
            case 2:
                xuatHocVien(hv, n);
                break;
            case 3:
                timMaxMinDiem(hv, n);
                break;
            case 4:
                sapXepGiamDan(hv, n);
                break;
            case 5:
                xuatDiemTBMon(hv, n);
                break;
            case 6:
                timHocVienHaNoi(hv, n);
                break;
            case 7:
                timHocVienTreNhat(hv, n);
                break;
            case 8:
                char tenFile[50];
                printf("Nhap ten file: ");
                fflush(stdin);
                gets(tenFile);
                luuFile(hv, n, tenFile);
                break;
            case 9:
                char tenFileMo[50];
                printf("Nhap ten file can mo: ");
                fflush(stdin);
                gets(tenFileMo);
                moFile(tenFileMo);
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (choice != 0);

    free(hv);
    return 0;
}