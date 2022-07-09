#include <bits/stdc++.h>

const long long MAXN = 10000000;

int num[MAXN + 10], ans[MAXN + 10];

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

bool is7(int n) {
    while (n > 0) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

void solve(int x) {
    for (int i = 1; i <= x; ++i) {
        if (num[i] != -1) continue;

        if (is7(i)) {
            num[i] = 0;
            for (long long j = 2 * i; j < MAXN + 10; j += i) {
                num[j] = 0;
            }
        } else
            num[i] = 1;
    }
    for (int i = x + 1; num[i] != 1; ++i) {
        if (num[i] == 0) continue;
        if (is7(i)) {
            num[i] = 0;
            for (int j = 2 * i; j < MAXN + 10; j += i) {
                num[j] = 0;
            }
        } else {
            num[i] = 1;
            break;
        }
    }
}

void output() {
    int aaa = MAXN + 1;
    for (int i = MAXN; i > 0; i--) {
        if (num[i] == 1) aaa = i;
        ans[i] = aaa;
    }
}

int main() {
    int t;
    t = read();

    static int in[200000], mx = 0;
    memset(num, -1, sizeof(num));

    for (int i = 0; i < t; ++i) {
        in[i] = read();
        if (in[i] > mx) mx = in[i];
    }

    solve(mx);
    output();

    for (int i = 0; i < t; ++i) {
        if (num[in[i]] == 0) puts("-1");
        else printf("%d\n", ans[in[i] + 1]);
    }

    return 0;
}