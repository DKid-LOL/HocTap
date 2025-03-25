#include <stdio.h>
//Viết chương trình C để nhập một số nguyên bất kỳ từ bàn phím và in kết quả ra màn hình để nói cho người dùng biết số đó là lớn hay nhỏ hơn 100.
int main(){
    int a;
    printf("nhap so nguyen a: ");
    scanf("%d" , &a);
    if ( a < 100)
        printf("so nguyen a nho hon 100");
    if ( a > 100)
            printf("so nguyen a lon hon 100");
}