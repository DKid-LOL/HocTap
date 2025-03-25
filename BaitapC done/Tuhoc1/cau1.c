#include<stdio.h>
/*Cau 1:Viet chuong trinh nhap diem cua mot hoc vien voi cac mon sau: ten , mshv, mon EPC, PRE, HTML, Python, java 
voi dk cac mon theo thang diem 20 tu ban phim.
     +)    Xuat ra man hinh diem cua cac mon.
     +)    Neu diem trung binh cac mon duoi 8d thi xep loai kem.
             Neu diem tb tu 8 den 13 d xep loai tb.
            Tu 13 den 16 d xep loai kha.
            con lai xep loai gioi.
        Xuat ra man hinh ten , diem tb, xep loai.*/
int main(){
    float EPC,PRE,HTML,python,java,diemTB;
    printf("Ten:Pham Hoang Anh");
    printf("\nMSHV: ");
    printf("\nmon EPC :");
    scanf("%f" , &EPC);
    while (EPC > 20){
        printf("Vui long nhap lai :");
        scanf("%f" , &EPC);
    }
    printf("\nmon PRE: ");
    scanf("%f" , &PRE);
    while (PRE > 20){
        printf("Vui long nhap lai :");
        scanf("%f" , &PRE);
    }
    printf("\nmon HTML: ");
    scanf("%f" , &HTML);
    while (HTML > 20){
        printf("Vui long nhap lai :");
        scanf("%f" , &HTML);
    }
    printf("\nmon Python: ");
    scanf("%f" , &python);
    while (python > 20){
        printf("Vui long nhap lai :");
        scanf("%f" , &python);
    }
    printf("\nmon Java: ");
    scanf("%f" , &java);
    while (java > 20){
        printf("Vui long nhap lai :");
        scanf("%f" , &java);
    }
    diemTB = (EPC + PRE + HTML + python + java)/5;
    printf("\nDiem TB: %f" , diemTB);
    if (diemTB < 8){
        printf("\nXep loai kem");
    }
    else if (8<=diemTB<=13){
        printf("\nXep loai TB");
    }
    else if (13<=diemTB<=16){
        printf("\nXep loai kha");
    }
    else {
        printf("\nXep loai gioi");
    }
}
