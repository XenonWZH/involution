// Q2.1.4.1. 灯泡
// WzhDnwzWzh

#include <cstdio>

int n;

void f(int k, int s) {
    if (k == 1) {
        printf(s ? "1 on\n" : "1 off\n");
        return;
    }
    f(k - 1, 1);
    printf(s ? "%d on\n" : "%d off\n", k);
    f(k - 1, 0);
}

int main() {
    scanf("%d", &n);

    f(n, 1);
    printf("%d off\n", n);

    return 0;
}