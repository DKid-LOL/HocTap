#include <stdio.h>
// cau a
int main(){
    char ten[100];
    float diemToan,diemVan,diemAnh;
    int tuoi,mshv;
    printf("ten : ");
    gets(ten);
    printf("\ntuoi :");
    scanf("%d" , &tuoi);
    printf("\nmshv :");
    scanf("%d" , &mshv);
    printf("\ndiem toan :");
    scanf("%f" , &diemToan);
    printf("\ndiem van :");
    scanf("%f" , &diemVan);
    printf("\ndiem anh :");
    scanf("%f" , &diemAnh);
    // Cau b
    float diemTB;
    diemTB = (diemToan + diemVan + diemAnh)/3;
    printf("\nDiem trung binh cac mon = %f ", diemTB);
    // cau c
    if (diemTB > 8 && diemToan > 6.5 && diemVan > 6.5 && diemAnh > 6.5){
        printf("\nXep loai Gioi");
    }
    else if (( 6 > diemTB <= 8) && diemToan < 6.5 && diemVan < 6.5 && diemAnh < 6.5){
        printf("\nXep loai Kha");
    }
    else if ( 5 < diemTB <= 6){
        printf("\nXep loai TB");
    }
    else if(diemTB <=5){
        printf("\nXep loai Kem");
    }
}