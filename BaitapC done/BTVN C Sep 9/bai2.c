// Viết chương trình nhập vào số nguyên bất kỳ. Xuất màn hình ra value chẵn từ 0 đến giá trị vừa nhập.(các em làm theo 3 cách khác nhau.)
#include<stdio.h>

int main(){
    int a;
    int i = 0;
    printf("nhap so a ");
    scanf("%d" , &a);
    do
    {
        printf("%d " , i);
        i+=2;
    } while (i<=a);
    i = 0;
    printf("\n");
    while(i<=a){
        printf("%d " , i);
        i+=2;
    }
    printf("\n");
    for(i=0;i<=a;i+=2){
        printf("%d " , i);
    }
}
while (for (size_t i = 0; i < count; i++)
{
    /* code */
}
)
{
    /* code */
}





    