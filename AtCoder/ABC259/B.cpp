#include <cstdio>
#include <cmath>
#include <iostream>

const double PI = 2 * acos(0);

int main() {
    int a, b, d;

    scanf("%d %d %d", &a, &b, &d);

    double ceta = d * PI / 180.0;

    printf("%.9lf %.9lf\n", a * cos(ceta) - b * sin(ceta), a * sin(ceta) + b * cos(ceta));

    return 0;
}