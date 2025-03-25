// tao struct Persion voi cac thuoc tinh  so thich, tuoi, gioi tinh, address
// tao struct nv ten voi thuoc tinh persion, chuc vu, luong
// tao 1 menu 
// case 1 input case 2 output case 3 tim ng o hn case 4 tim ng theo year  case 5 sap xep mang theo nam sinh, case 6 luu file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct PERSION
struct Persion
{
    char sothich[100];
    int tuoi;
    char gioitinh[100];
    char address[100];
} ps;
//Struct Nhan vien
struct nhanvien
{
    char name[100];
    char chucvu[100];
    float luong;
} nv;
struct NhanVien *nhanvien = NULL;
//Input
void nhapNhanVien(){
    struct nv;
    struct ps;
    printf("\nNhap ten nhan vien: "); scanf("%s" , nv.name);
    printf("\nNhap tuoi: "); scanf("%d" , &ps.tuoi);
    printf("\nGioi tinh: "); scanf("%s" , ps.gioitinh);
    printf("\nSo thich: "); scanf("%s" , ps.sothich);
    printf("\nDia chi: "); scanf("%s" , ps.address);
    printf("\nChuc vu: "); scanf("%s" , nv.chucvu);
    printf("\nLuong: "); scanf("%f" , &nv.luong);
}
//Output
void xuatNhanVien(){
    printf("\nTen: %s\n" , nv.name);
    printf("\nTuoi: %d\n" , ps.tuoi);
    printf("\nGioi tinh: %s\n" , ps.gioitinh);
    printf("\nSo thich: %s\n" , ps.sothich);
    printf("\nDia chi: %s\n" , ps.address);
    printf("\nChuc vu: %s\n" , nv.chucvu);
    printf("\nLuong: %f\n" , nv.luong);
}
int main() {
    int choice;
    float a, b;
    char sothich[100];

    while (1) {
        printf("\nMENU:\n");
        printf("1. Nhap thong tin nhan vien\n");
        printf("2. Xuat thong tin nhan vien\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapNhanVien();
                break;
            case 2:
                xuatNhanVien();
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}

