/*Bài 1:
Viết code
Xuất ra màn hình: 1 --> 10
theo 3 cách do while, while, for
Bài 2: 
Viết code
Nhập từ đúng nếu người dựng nhập: 1 ... Hôm nay thức 2
                                  2 ... Hôm nay thức 3
*/
#include <stdio.h>
//cách 1: do while
int main(){
    int a = 1;
    do{
        printf("\nGia tri cua a : %d  ", a);
        ++a;
    }while(a < 10);

    return 0;
}