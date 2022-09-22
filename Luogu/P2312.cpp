#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 100;
const int MOD = 998244353;

inline long long read() {
    long long x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x * 10 + (ch - '0')) % MOD;
        ch = getchar();
    }
    return x * w;
}

int main() {
    int n, m;
    static long long a[MAXN + 1];

    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) a[i] = read();

    static std::vector<int> ans;
    for (int i = 1; i <= m; i++) {
        long long res = 0, p = 1;
        for (int j = 0; j <= n; j++) {
            res = (res + (a[j] * p) % MOD) % MOD;
            p = (p * i) % MOD;
        }

        if (res == 0) ans.push_back(i);
    }

    printf("%zu\n", ans.size());
    for (int each : ans) printf("%d\n", each);

    return 0;
}