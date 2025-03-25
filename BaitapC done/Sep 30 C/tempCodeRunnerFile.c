#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    int year;
    char sex;
    char address[100];
    char hobby[100];
};

struct NhanVien {
    char name[100];
    struct Person person;
    char position[100];
    double salary;
};

#define MAX_EMPLOYEES 100

struct NhanVien danhSachNhanVien[MAX_EMPLOYEES];
int soLuongNhanVien = 0;

void NhapPerson(struct Person* p) {
    printf("Nhap nam sinh: ");
    scanf("%d", &p->year);
    printf("Nhap gioi tinh (M/F): ");
    scanf(" %c", &p->sex);
    printf("Nhap dia chi: ");
    scanf(" %[^\n]", p->address);
    printf("Nhap so thich: ");
    scanf(" %[^\n]", p->hobby);
}

void NhapNhanVien(struct NhanVien* nv) {
    printf("Nhap ten nhan vien: ");
    scanf(" %[^\n]", nv->name);
    NhapPerson(&nv->person);
    printf("Nhap vi tri: ");
    scanf(" %[^\n]", nv->position);
    printf("Nhap luong: ");
    scanf("%lf", &nv->salary);
}

void XuatPerson(struct Person p) {
    printf("Nam sinh: %d\n", p.year);
    printf("Gioi tinh: %c\n", p.sex);
    printf("Dia chi: %s\n", p.address);
    printf("So thich: %s\n", p.hobby);
}

void XuatNhanVien(struct NhanVien nv) {
    printf("Ten nhan vien: %s\n", nv.name);
    printf("Vi tri: %s\n", nv.position);
    printf("Luong: %.2lf\n", nv.salary);
    printf("Thong tin person:\n");
    XuatPerson(nv.person);
}

void XuatDanhSachNhanVien() {
    printf("Danh sach nhan vien:\n");
    for (int i = 0; i < soLuongNhanVien; i++) {
        printf("Nhan vien %d:\n", i + 1);
        XuatNhanVien(danhSachNhanVien[i]);
        printf("-------------------------------\n");
    }
}

void TimNguoiQueHaNoi() {
    printf("Nhung nguoi que Ha Noi:\n");
    for (int i = 0; i < soLuongNhanVien; i++) {
        if (strstr(danhSachNhanVien[i].person.address, "Ha Noi") != NULL) {
            XuatNhanVien(danhSachNhanVien[i]);
            printf("-------------------------------\n");
        }
    }
}

void ThemNhanVien(int viTri) {
    if (soLuongNhanVien >= MAX_EMPLOYEES) {
        printf("Danh sach nhan vien da day. Khong the them nhan vien moi.\n");
        return;
    }

    if (viTri < 0 || viTri > soLuongNhanVien) {
        printf("Vi tri them khong hop le.\n");
        return;
    }

    printf("Nhap thong tin cho nhan vien moi:\n");
    NhapNhanVien(&danhSachNhanVien[soLuongNhanVien]);

    for (int i = soLuongNhanVien; i > viTri; i--) {
        danhSachNhanVien[i] = danhSachNhanVien[i - 1];
    }

    soLuongNhanVien++;
    printf("Da them nhan vien moi vao vi tri %d.\n", viTri);
}

void SapXepNhanVienTheoNamSinh() {
    for (int i = 0; i < soLuongNhanVien - 1; i++) {
        for (int j = 0; j < soLuongNhanVien - i - 1; j++) {
            if (danhSachNhanVien[j].person.year > danhSachNhanVien[j + 1].person.year) {
                struct NhanVien temp = danhSachNhanVien[j];
                danhSachNhanVien[j] = danhSachNhanVien[j + 1];
                danhSachNhanVien[j + 1] = temp;
            }
        }
    }
}

int main() {
    int luaChon;
    do {
        printf("+----------------------------------------------------------------------------------------------+\n");
        printf("|                          KHONG KHO KHI TA BIET TU DUY                                        |\n");
        printf("|                 90%% THANH CONG PHU THUOC VAO SU CHAM CHI CAN CU                              |\n");
        printf("+----------------------------------------------------------------------------------------------+\n");
        printf("|              1. Input  |2. Output |3. Search |4. Add |5. Sort |6. End                        |\n");
        printf("+----------------------------------------------------------------------------------------------+\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (soLuongNhanVien < MAX_EMPLOYEES) {
                    printf("Nhap thong tin cho nhan vien:\n");
                    NhapNhanVien(&danhSachNhanVien[soLuongNhanVien]);
                    soLuongNhanVien++;
                } else {
                    printf("Danh sach nhan vien da day. Khong the them nhan vien moi.\n");
                }
                break;
            case 2:
                XuatDanhSachNhanVien();
                break;
            case 3:
                TimNguoiQueHaNoi();
                break;
            case 4:
                printf("Nhap vi tri muon them: ");
                int viTriThem;
                scanf("%d", &viTriThem);
                ThemNhanVien(viTriThem);
                break;
            case 5:
                SapXepNhanVienTheoNamSinh();
                printf("Da sap xep danh sach nhan vien theo nam sinh.\n");
                break;
            case 6:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 6);

    return 0;
}
