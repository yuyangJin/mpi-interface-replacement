#include <stdio.h>
#include <math.h>

int main() {
    int a = 1;
    double b = rand();
    double c = ( a + b ) / 2;
    double d = pow(c , 4);
    double e;
    for (int i = 0; i < 100; i ++) {
        e += d / i;
        d = d++;
    }
    printf("%d", e);
    double f;
    int N = e;
    for (int i = 0; i < N; i ++) {
        f += e / i;
    }
    printf("%d", f);
}