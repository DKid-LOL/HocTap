#include <stdio.h>

int main() {
    double in = 8.6;
    float fl = 10.5;
    double db = 15;

    if ((5 + (6 - 8) < in && fl < db) || !(in < 8)) {
        printf("Chuong trinh vao bt 1\n");
    }
    if (4 - 5 * 4 + 2 < in || fl < db && 8 / 4 < db / in) {
        printf("Chuong trinh vao bt 2\n");
    }
    if (!(7 * 6 - 40 / 10 < 30 && in - 10 > db)) {
        printf("Chuong trinh vao bt 3\n");
    }
    if (in == 20) {
        printf("Chuong trinh vao bt 4\n");
    }
    else {
        printf("Chuong trinh vao bt 5\n");
    }
    return 0;
}