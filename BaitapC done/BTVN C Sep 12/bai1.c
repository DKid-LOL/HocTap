#include <stdio.h>

int main() {
    int n, i;
    long long int fibonacci[100];

    printf("Nhap so luong so trong day Fibonacci: ");
    scanf("%d", &n);

    fibonacci[0] = 1;
    fibonacci[1] = 1;

    for (i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Hiển thị dãy Fibonacci
    printf("Day Fibonacci: ");
    for (i = 0; i < n; i++) {
        printf("%lld ", fibonacci[i]);
    }

    return 0;
}
