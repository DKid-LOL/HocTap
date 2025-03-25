#include <stdio.h>
//cách 1: do while
int main(){
    int a = 1;
    do{
        printf("\nGia tri cua a : %d  ", a);
        ++a;
    }while(a < 10);
printf("\n");
//cách 2: while
    a = 1;
    while (a<10){
        printf("\nGia tri cua a : %d" , a);
        ++a;
    }
    printf("\n");
//cách 3: for
        for (a=1;a<10;a++){
        printf("\nGia tri cua a : %d" , a);
    }
}

