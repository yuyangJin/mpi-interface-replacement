#include <stdio.h>
#include <math.h>

int main() {
    int a = 1;
    double b = rand();
    double c = ( a + b ) / 2;
    double d = pow(c , 4);
    double e;
    if (b > d) {
        e = b;
    } else {
        e = d;
    }
    printf("%d", e);
}