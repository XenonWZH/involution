// Q2.1.4.2. 九连环
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

    int st;

    if (n % 2 == 1) st = 1;
    else st = 2;

    for (int i = st; i <= n; i += 2) {
        printf("%d off\n", i);

        if (i >= 2) f(i - 1, 0);
    }

    return 0;
}