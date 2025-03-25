/*Bài 1: Viết chương trình khai báo mảng int có số lượng phần từ do người dùng nhập vào.
(y/c value nhập từ bàn phím.)
a. xuất ra giá trị vừa nhập.
b. xuất ra địa chỉ các phần tử.
c. xuất ra kích thước các phần tử.
d.Tìm max min trong mảng.
e.xuất ra giá trị phần tử thứ 5(nếu có).
f.Tính tổng giá trị trung bình và xuất ra màn hình.
g.Thay thế giá trị thứ 2 do người dùng nhập vào.
Xuất ra giá trị các ptu.*/
#include<stdio.h>
#include<string.h>

void main(){
    int a;
    printf("nhap so luong phan tu : ");
    scanf("%d" , &a);
    int arry[a];
    for (int b = 0; b < a ; b++){
        printf("nhap gia tri phan tu %d:  " , b + 1);
        scanf("%d" , &arry[b]);
    }
    printf("gia tri vua nhap : ");
    for (int b = 0; b < a ; b++){
        printf("\n%d" , arry[b]);
    }
    printf("\ndia chi vua nhap : ");
    for (int b = 0; b < a ; b++){
        printf("\n%d" , &arry[b]);
    }
    int kichthuoc;
    printf("\nkich thuoc phan tu : ");
    for (int b = 0; b < a ; b++){
    size_t kichthuoc = strlen(arry[b]);
        printf("chuoi %d:  %lu ky tu\n", b + 1, kichthuoc);
    }
}
    