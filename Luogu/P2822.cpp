#include <cstdio>
#include <iostream>

const int MAXN = 2e3;

int k;
long long C[MAXN + 1][MAXN + 1], cnt[MAXN + 1][MAXN + 1];

inline void prepare() {
    for (int i = 1; i <= MAXN; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % k;
        }

        for (int j = 1; j <= i; j++) {
            cnt[i][j] = cnt[i][j - 1];
            if (C[i][j] == 0) cnt[i][j]++;
        }
    }
}

int main() {
    int t;
    scanf("%d %d", &t, &k);

    prepare();

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int ans = 0;
        for (int i = 1; i <= n; i++) ans += cnt[i][std::min(i, m)];
        printf("%d\n", ans);
    }

    return 0;
}