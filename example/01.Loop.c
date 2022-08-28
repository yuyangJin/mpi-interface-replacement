#include <stdio.h>
#include <math.h>

int main() {
    int a = 1;
    double b = rand();
    double c = ( a + b ) / 2;
    double d = pow(c , 4);
    double e;
    for (int i = 0; i < 100; i ++) {
        for (int j = 0; j < i; j ++) {
            e += d / i+j;
            d = d++;
        }
    }
    printf("%d", e);
    double f;
    int N = e;
    for (int i = 0; i < N; i ++) {
        if (a > b || b < c && c == e)
            f += e / i;
        else
            f += i / e;
    }
    printf("%d", f);
}