#include <stdio.h>

int main() {
    int in = 8.6;
    float fl = 10.5;
    double d = 15;

    if ((5 + (6 - 8) < in) && (fl < d) || !(in < 8)) {
        printf("Chuong trinh vao bt 1");
    }
    else if ((4 - 5 * 4 + 2 < in) || (fl < d && (8.0 / 4) < (d / in))) {
        printf("Chuong trinh vao bt 2");
    }
    else if (!(7 * 6 - 40 / 10 < 30 && (in - 10 > d))) {
        printf("Chuong trinh vao bt 3");
    }
    else {
        printf("Chuong trinh vao bt 4");
    }

    return 0;
}