// Q1.2.3.4. 高精度四则运算1
// WzhDnwzWzh

#include <cstdio>

int la, a[1111], lb, b[1111], lc, c[1111], cc, d[2222], l, k;

void f(int x, int *y) {
    for (l = 0; l < x || y[l]; l++) {
        k = (y[l] % 10 + 10) % 10;
        y[l + 1] += (y[l] - k) / 10;
        y[l] = k;
    }
    while (!y[l] && l) l--;
}

void o() {
    for (int i = l; i >= 0; i--) printf("%d", d[i]);
    puts("");
}

void md() {
    for (int i = 0; i < la + lb; i++) d[i] = 0;
}

void add(int *x, int *y, int lx, int ly) {
    md();
    for (int i = 0; i < lx || i < ly; i++) d[i] = x[i] + y[i];
    f(lx > ly ? lx : ly, d);
    o();
}

void sub(int *x, int *y, int lx, int ly) {
    int p = 1;
    md();
    if (lx != ly)
        p = 1 - (lx < ly) * 2;
    if (lx == ly)
        for (int i = lx - 1; i >= 0; i--)
            if (x[i] != y[i]) {
                p = 1 - (x[i] < y[i]) * 2;
                break;
            }
    for (int i = 0; i < (~p ? lx : ly); i++) d[i] = (x[i] - y[i]) * p;
    if (!~p)
        printf("-");
    f(~p ? lx : ly, d);
    o();
}

void mul(int *x, int *y, int lx, int ly) {
    md();
    for (int i = 0; i < lx; i++)
        for (int j = 0; j < ly; j++) d[i + j] += x[i] * y[j];
    f(lx + ly - 1, d);
    o();
}

int main() {
    scanf("%d", &la);
    for (int i = la - 1; i >= 0; i--) scanf("%d", &a[i]);
    scanf("%d", &lb);
    for (int i = lb - 1; i >= 0; i--) scanf("%d", &b[i]);
    scanf("%d", &c[0]);

    cc = c[0];
    f(0, c);
    lc = l + 1;
    add(a, b, la, lb);
    add(a, c, la, lc);
    sub(a, b, la, lb);
    sub(b, c, lb, lc);
    mul(a, b, la, lb);
    mul(a, c, la, lc);
    md();

    k = 0;
    for (int i = lb - 1; i >= 0; i--) {
        k = k * 10 + b[i];
        d[i] = k / cc;
        k %= cc;
    }
    f(lb, d);
    o();

    return 0;
}