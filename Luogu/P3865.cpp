#include <cstdio>
#include <iostream>

const int MAXN = 1e5;
const int LOG_MAXN = 17;

int n, m, a[MAXN + 1], st[MAXN + 1][LOG_MAXN + 1], logx[MAXN + 1];

inline void sparseTable() {
    for (int i = 1; i <= n; i++) {
        int t = 0;
        while ((1 << (t + 1)) <= i) t++;
        logx[i] = t;
    }

    for (int i = 1; i <= n; i++) st[i][0] = a[i];

    for (int j = 1; j <= logx[n]; j++) {
        for (int i = 1; i <= n; i++) {
            if (i + (1 << (j - 1)) <= n) st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            else st[i][j] = st[i][j - 1];
        }
    }
}

inline int rmq(int l, int r) {
    int t = logx[r - l];
    return std::max(st[l][t], st[r - (1 << t) + 1][t]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    sparseTable();

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", rmq(l, r));
    }

    return 0;
}