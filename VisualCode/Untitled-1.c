#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    printf("Nhap he so a: ");
    scanf("%lf", &a);
    printf("Nhap he so b: ");
    scanf("%lf", &b);
    printf("Nhap he so c: ");
    scanf("%lf", &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Nghiem 1: %.2lf\n", root1);
        printf("Nghiem 2: %.2lf\n", root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Nghiem kep: %.2lf\n", root1);
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Nghiem 1: %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Nghiem 2: %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }

    return 0;
}
