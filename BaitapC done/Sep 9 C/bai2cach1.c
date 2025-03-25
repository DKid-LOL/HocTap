/*B2: Viết chương trình nhập từ người dùng:
   nếu user nhập 1 thì hiển thị: "Hom nay la tu 2".
   nếu user nhập 2 thì hiển thị: "Hom nay la tu 3".
   nếu user nhập 3 thì hiển thị: "Hom nay la tu 4".
   ......
   nếu user nhập 7 thì hiển thị: "Hom nay la tu cn".
   nếu giá trị ngoài thì hiển thị: "Ngay nghi".
theo 2 cách if-else, switch().*/
#include<stdio.h>
int main(){
    int a;
    while(a!=999){
    printf("\nnhap gia tri a : ");
    scanf("%d" , &a);
    if (a == 1)
    {
        printf("Hom nay la thu 2");
    } else if (a == 2) {
        printf("Hom nay la thu 3");
    } else if (a == 3) {
        printf("Hom nay la thu 4");
    } else if (a == 4) {
        printf("Hom nay la thu 5");
    } else if (a == 5) {
        printf("Hom nay la thu 6");
    } else if (a == 6) {
        printf("Hom nay la thu 7");
    } else if (a == 7) {
        printf("Hom nay la cn");
    } else { 
        printf("Ngay nghi");
    }
}
}

