/*Viết chương trình hiển thi:

*
**
***
****
******/
#include<stdio.h>

int main(){
    int i;
    printf("i = ");
    scanf("%d" , &i);
    for (int a = 1; a<= i; a++){
        for (int b = 1; b <= a; b++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}