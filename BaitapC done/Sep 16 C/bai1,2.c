/*Cho struct hocvien với properties: name, classroom, mshv, year,address, PRE,EPC, sothich.
Viết chương trình nhập 1 mảng data type struct hocvien biết sl nhập từ bàn phím.
1 , xuất ra thông tin phần tử.
2. Tìm kiếm người có điểm pre max và xuất ra thông tin người đó.
3. Xuất ra màn hình có quê ở HaNoi và điểm TB >7.
4.Tìm kiếm 1 thông tin học viên do người dùng nhập vào.
Hiển thị thông tin học viên đó nếu có và ngược lại.
5.Xuất ra màn hình số lượng người có cùng sở thích.*/

#include<stdio.h>
#include<string.h>

struct hocvien {
    char name[100];
    char classroom[100];
    char mshv[100];
    int year;
    char address[100];
    float PRE;
    float EPC;
    char sothich[100];
};
typedef struct hocvien hv;
hv a;
int main(){    
    printf("Nhap thong tin hoc vien");
    printf("\nTen hoc vien : ");
    scanf("%s" , &a.name);
    printf("\nLop : ");
    scanf("%s" , &a.classroom);
    printf("\nMSHV : ");
    scanf("%s" , &a.mshv);
    printf("\n nam sinh : ");
    scanf("%d", a.year);
    printf("dia chi: ");
    scanf("%s" , a.address);
    printf("mon PRE: ");
    scanf("%f" , &a.PRE);
}

