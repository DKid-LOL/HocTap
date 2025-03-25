#include <stdio.h>
#include <math.h>

int main(){
    float a,b,c,nghiem1,nghiem2,nghiemKep;

    float delta;

    printf("a = ");
    scanf("%f", &a);
    printf("\nb = ");
    scanf("%f", &b);
    printf("\nc = ");
    scanf("%f", &c)

    delta = b * b - (4 * a * c);
    printf("delta = %f" , delta );
    if(delta > 0){
        nghiem1 = (-b + sqrt(delta))/(2*a);
        nghiem2 = (-b - sqrt(delta))/(2*a);
        printf("\nNghiem1 = %f" , nghiem1);
        printf("\nNghiem2 = %f" , nghiem2);
    }
    else if(delta < 0){
        printf("\nphuong trinh vo nghiem");
    }
    else {
        nghiem1 = - b/(2*a);
        printf("phuong trinh co nghiem kep : nghiem1 = %f" , nghiem1);
    }
    return 0;
}