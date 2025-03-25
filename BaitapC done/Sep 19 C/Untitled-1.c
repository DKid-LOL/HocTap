/*viết chương trình khai báo 2 biến x,y và con trỏ ptr
xuất ra giá trị và địa chỉ của biến x,y ptr
Cho con trỏ ptr trỏ tới biến x xuất ra giá trị và địa chỉ của biến x ptr
Cho con trỏ ptr trỏ tới biến y xuất ra giá trị và địa chỉ của biến x ptr*/
#include<stdio.h>

void main(){
    int x,y;
    int *ptr = NULL;
    x = 10;
    y = 20;
    printf("Gia tri cua x : %d" , x);
    printf("\nDia chi cua x : %d" , &x);
    printf("\nGia tri cua y : %d" , y);
    printf("\nDia chi cua y : %d" , &y);
    printf("\nGia tri cua ptr : %d" , ptr);
    printf("\nDia chi cua ptr : %d" , &ptr);
    ptr = &x;
    printf("\nGia tri cua ptr : %d" , *ptr);
    printf("\nDia chi cua ptr : %d" , ptr);
    ptr = &y;
    printf("\nGia tri cua ptr : %d" , *ptr);
    printf("\nDia chi cua ptr : %d" , ptr);
}