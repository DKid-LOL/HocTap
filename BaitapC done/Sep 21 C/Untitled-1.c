/*Bài 2:tao struct hocvien voi cac thuoc tinh sau: name, class, mshv, diemPre,diemEPC, year. Viet chương trinh nhap mang kieu du lieu struct.(luu y dung cap phát đồng)
a, Viết chương trình nhap data từ bàn phím.(diem so theo thang diem 20, mshv ko duoc trung nhau).
b, Xuất ra value phân tử trong mang.
d, tim gia tri max min cac mon trong mang và xuất ra man hinh gia tri max min.
e, viết chương trinh sap xec phan tu giam dan theo mshv.
f, Xuất ra màn hình có điểm tb> 15 và các môn học không dưới 12 điểm.
k, Tìm người trẻ nhất có điểm tb cao nhất. xuất ra màn hình.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct hocvien {
    char name[50];
    char class[20];
    int mshv;
    float diemPRE;
    float diemEPC;
    int year;
} hv;// gọi tên struct hocvien la hv
// Kiểm tra MSHV xem có trùng hay không 
int kiemtraMSHV(hv *hvs , int n, int mshv) {
    for (int i = 0; i < n; i++){
        if (hvs[i].mshv == mshv){
            return 1;
        }
    }
    return 0;
}
// Kiểm tra điểm với điều kiện
bool ktraDiem(float diem){
    return (diem > 0 && diem < 20);
}
int main(){
    int n;
    printf("Nhap so luong hoc vien: ");
    scanf("%d" , &n);

    hv *hvs = (hv *)malloc(n * sizeof(hv));
// nhập thông tin học viên
    for (int i = 0; i < n; i++){
        printf("\nNhap thong tin hoc vien %d: " , i + 1);
        printf("\nHo va ten: ");
        scanf("%s" , hvs[i].name);
        printf("Lop: ");
        scanf("%s" , hvs[i].class);

        int mshv;
        do{
            printf("MSHV (khong duoc trung): ");
            scanf("%d" , &mshv);

            if(kiemtraMSHV(hvs, i, mshv)){
                printf("MSHV trung lap. Vui long nhap lai.\n");
            } else{
                hvs[i].mshv = mshv;
            }
        } while (kiemtraMSHV(hvs, i, mshv));
        do{
            printf("DiemPRE: ");
            scanf("%f", &hvs[i].diemPRE);
            if (!ktraDiem(hvs[i].diemPRE)){
                printf("Vui long nhap lai.\n");
        }
        } while (!ktraDiem(hvs[i].diemPRE));

        do{
            printf("DiemEPC: ");
            scanf("%f", &hvs[i].diemEPC);
            if (!ktraDiem(hvs[i].diemEPC)){
                printf("Vui long nhap lai.\n");
        }
        } while (!ktraDiem(hvs[i].diemEPC));    
         printf("Year: ");
            scanf("%f", &hvs[i].year);     
    }

}