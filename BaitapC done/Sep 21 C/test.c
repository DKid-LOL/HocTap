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
int ktraDiem(float diem){
    while (diem < 0 || diem > 20){
        float temp;
        printf("Vui long nhap lai.");
        printf("\nNhap lai: ");
        scanf("%f" , &temp);
        diem = temp;
    } return diem;
}
//in ra thông tin của học viên
void Inthongtinhocvien(hv *hvs, int n){
    printf("\nDanh sach hoc vien\n");
    for (int i = 0; i < n; i++){
        printf("Ho va Ten: %s\n" , hvs[i].name);
        printf("Class: %s\n" , hvs[i].class);
        printf("MSHV: %d\n" , hvs[i].mshv);
        printf("Diem PRE: %f\n" , hvs[i].diemPRE);
        printf("Diem EPC: %f\n" , hvs[i].diemEPC);
        printf("Year: %d\n" , hvs[i].year);
        printf("-------------------------------\n");
    }
}
//min
float TimMin(hv *hvs, int n){
    float min = hvs[0].diemPRE;
    for (int i = 0; i < n; i++){
        if (hvs[i].diemPRE < min){
            min = hvs[i].diemPRE;
        }
        if (hvs[i].diemEPC < min){
            min = hvs[i].diemEPC;
        }
    }
    return min;
}
//max
float TimMax(hv *hvs, int n){
    float max = hvs[0].diemPRE;
    for (int i = 0; i < n; i++){
        if (hvs[i].diemPRE > max){
            max = hvs[i].diemPRE;
        }
        if (hvs[i].diemEPC > max){
            max = hvs[i].diemEPC;
        }
    }
    return max;
}
void Sortmshv(hv *hvs, int n){
    for(int i = 0; i < n; i++){
        for (int j = i + 1; j < n;j++){
            if (hvs[i].mshv < hvs[j].mshv){
                struct hocvien temp = hvs[i];
                hvs[i] = hvs[j];
                hvs[j] = temp;
            }
        }
    }
}
void Timngtrecodiemmax(hv *hvs, int n){
    float diemMax = (hvs[0].diemPRE + hvs[0].diemEPC) / 2;

    for (int i = 0; i < n; i++){
        float diemTB = (hvs[i].diemPRE + hvs[i].diemEPC) / 2;
        if (diemTB > diemMax) {
            diemMax = diemTB;
        }
    }

    int young = 2022 - hvs[0].year;

    for (int i = 0; i < n; i++){
        int year = 2022 - hvs[i].year;
        float diemTB = (hvs[i].diemPRE + hvs[i].diemEPC) / 2;
        if (diemTB == diemMax) {
            if (year < young || (year == young && diemTB > diemMax)) {
                young = year;
            }
        }
    }
    
    printf("\nThong tin nguoi tre nhat co diem TB cao nhat: \n");
    for (int i = 0; i < n; i++){
        int year = 2022 - hvs[i].year;
        float diemTB = (hvs[i].diemPRE + hvs[i].diemEPC) / 2;   
        if (year == young && diemTB == diemMax){
            printf("Ho va Ten: %s\n" , hvs[i].name);
            printf("Class: %s\n" , hvs[i].class);
            printf("MSHV: %d\n" , hvs[i].mshv);     
            printf("diemTB: %2.f\n" , diemTB);
            printf("Year: %d\n" , hvs[i].year);
            printf("-------------------------------\n");             
        } 
    }
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
        float diem;
        printf("DiemPRE: ");
        scanf("%f" , &diem);
        hvs[i].diemPRE = ktraDiem(diem);
        printf("DiemEPC: ");
        scanf("%f", &diem); 
        hvs[i].diemEPC = ktraDiem(diem);
        printf("Year: ");
        scanf("%d", &hvs[i].year);     
    }
    //xuất thông tin học viên
        Inthongtinhocvien(hvs, n);
    // tìm min và max và xuất ra giá trị
    float maxDiem = TimMax(hvs, n);
    float minDiem = TimMin(hvs, n);
    printf("\nMax = %.2f\n" , maxDiem);
    printf("Min = %.2f\n" , minDiem);
    //sắp xếp lại danh sách HV
        Sortmshv(hvs, n);
        //in ra lại danh sách học viên đã sắp xếp
        printf("\ndanh sach hoc vien da duoc sap xep: \n");
        Inthongtinhocvien(hvs, n);
    //Xuất ra thông tin các hv có điểm TB > 15 và các môn < 12 diem
    printf("\nHoc vien co diem trung binh > 15 va cac mon < 12 diem\n");
    for (int i = 0; i < n; i++){
        float diemTB = (hvs[i].diemPRE + hvs[i].diemEPC) / 2;
        if (diemTB > 15 && hvs[i].diemPRE >= 12 && hvs[i].diemEPC >= 12){
            printf("Ho va Ten: %s\n" , hvs[i].name);
            printf("Class: %s\n" , hvs[i].class);
            printf("MSHV: %d\n" , hvs[i].mshv);     
            printf("diemTB: %2.f\n" , diemTB);
            printf("Year: %d\n" , hvs[i].year);
            printf("-------------------------------\n");               
        }
    }
    //Tìm người trẻ nhất có điểm TB cao nhất
    Timngtrecodiemmax(hvs, n);

    free(hvs);//giải phóng bộ nhớ
    return 0;
}
