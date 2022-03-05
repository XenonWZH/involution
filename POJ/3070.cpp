#include <cstdio>
#include <cstring>
#include <algorithm>

int fib[1 + 1][2 + 1], x[2 + 1][2 + 1];

void init() {
    fib[1][1] = fib[1][2] = 1;
    x[1][1] = 0;
    x[1][2] = x[2][1] = x[2][2] = 1;
}

void mul(int a[][2 + 1], int ax, int ay, int b[][2 + 1], int bx, int by, int ans[][2 + 1], int mod) {
    int s1[2 + 1][2 + 1], s2[2 + 1][2 + 1];
    memcpy(s1, a, sizeof(int) * (ax + 1) * (ay + 1));
    memcpy(s2, b, sizeof(int) * (bx + 1) * (by + 1));

    for (int i = 1; i <= ax; i++) {
        for (int j = 1; j <= by; j++) {
            int sum = 0;
            for (int k = 1; k <= ay; k++) sum = (sum + s1[i][k] * s2[k][j]) % mod;
            ans[i][j] = sum;
        }
    }
}

void pow(int a[][2 + 1], int ax, int ay, int p, int ans[][2 + 1], int mod) {
    int s1[2 + 1][2 + 1];
    memcpy(s1, a, sizeof(int) * (2 + 1) * (2 + 1));
    memset(ans, 0, sizeof(int) * (2 + 1) * (2 + 1));
    for (int i = 1; i <= std::min(ax, ay); i++) ans[i][i] = 1;


    for (; p; p >>= 1) {
        if (p & 1) mul(ans, 2, 2, s1, 2, 2, ans, mod);
        mul(s1, 2, 2, s1, 2, 2, s1, mod);
    }
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == -1) break;
        if (n == 0) {
            printf("0\n");
            continue;
        }
        if (n == 1 || n == 2) {
            printf("1\n");
            continue;
        }
        if (n == 3) {
            printf("2\n");
            continue;
        }

        init();
        pow(x, 2, 2, n - 1, x, 10000);
        mul(fib, 1, 2, x, 2, 2, fib, 10000);

        printf("%d\n", fib[1][1]);
    }

    return 0;
}