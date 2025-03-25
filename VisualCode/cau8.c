#include <stdio.h>
//Viết một chương trình C để nhắc người dùng nhập 3 số nguyên tu ban phim và xuat ra man hinh giá trị lớn nhất.
int main(){
    int a,b,c;
    int max;
    printf("nhap so nguyen a : ");
    scanf("%d" , &a);
    printf("\nnhap so nguyen b : ");
    scanf("%d" , &b);
    printf("\nnhap so nguyen c : ");
    scanf("%d" , &c);
    if ( a > b && a > c) {max = a;}
    if ( b > a && b > c) {max = b;}
    if ( a < c && b < c) {max = c;}
    printf("max = %d " , max);   
    }