#include <stdio.h>

struct hocvien {
    char name[100];
    char classroom[20];
    char mshv[20];
    int year;
    char address[100];
    float PRE;
    float EPC;
};

int main() {
    struct hocvien hv;

    printf("Nhap thong tin hoc vien:\n");
    printf("Ho va ten: ");
    scanf("%s", hv.name);
    printf("Lop: ");
    scanf("%s", hv.classroom);
    printf("Ma so hoc vien: ");
    scanf("%s", hv.mshv);
    printf("Nam sinh: ");
    scanf("%d", &hv.year);
    printf("Dia chi: ");
    scanf("%s", hv.address);
    printf("Diem PRE: ");
    scanf("%f", &hv.PRE);
    printf("Diem EPC: ");
    scanf("%f", &hv.EPC);

    printf("\nThong tin hoc vien:\n");
    printf("Ho va ten: %s\n", hv.name);
    printf("Lop: %s\n", hv.classroom);
    printf("Ma so hoc vien: %s\n", hv.mshv);
    printf("Nam sinh: %d\n", hv.year);
    printf("Dia chi: %s\n", hv.address);
    printf("Diem PRE: %.2f\n", hv.PRE);
    printf("Diem EPC: %.2f\n", hv.EPC);

    return 0;
}
