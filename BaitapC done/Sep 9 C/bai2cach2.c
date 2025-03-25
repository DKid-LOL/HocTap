/*B2: Viết chương trình nhập từ người dùng:
   nếu user nhập 1 thì hiển thị: "Hom nay la tu 2".
   nếu user nhập 2 thì hiển thị: "Hom nay la tu 3".
   nếu user nhập 3 thì hiển thị: "Hom nay la tu 4".
   ......
   nếu user nhập 7 thì hiển thị: "Hom nay la tu cn".
   nếu giá trị ngoài thì hiển thị: "Ngay nghi".
theo 2 cách if-else, switch().

cách2 switch */
#include<stdio.h>
int main(){
    int a = 0;
    while(a!=999){


    printf("\nnhap gia tri : ");
    scanf("%d" , &a);
    switch (a){
        case 1:
            printf("Hom nay la thu 2");
            break;
        case 2:
            printf("Hom nay la thu 3");
            break;
        case 3:
            printf("Hom nay la thu 4");
            break;
        case 4:
            printf("Hom nay la thu 5");
            break;
        case 5:
            printf("Hom nay la thu 6");
            break;
        case 6:
            printf("Hom nay la thu 7");
            break;
        case 7:
            printf("Hom nay la thu cn");
            break;

        default:
            printf("Ngay nghi");
            break;
        }
    }
}