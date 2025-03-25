// Viết chương trình nhập vào số nguyên bất kỳ. Xuất màn hình tổng giá trị số chẵn từ 0 đến giá trị vừa nhập .(các em làm theo 3 cách khác nhau.)
#include<stdio.h>

int main(){
    int a;
    int sum = 0;
    printf("nhap so a ");
    scanf("%d" , &a);
    while (a<0){
        printf("vui long nhap lai ");
        scanf("%d" , &a);
    }
    int i = 0;
    do
    {
        if (i%2==0){
        sum += i;
        }
        i++;
    } while (i<=a);
        printf("tong : %d" , sum);
    i = 0;
    sum = 0;
    while (i<=a){
        if (i%2==0){
            sum += i;
        }
        i++;
    }
        printf("\ntong : %d" , sum);
    sum = 0;
    for(i=0;i<=a;i++){
        if(i%2==0){
            sum +=i;
        }
    }
        printf("\ntong : %d" , sum);
    }
