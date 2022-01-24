#include <cstdio>
#include <cstring>

const int MAXN = 500000;

int c[MAXN + 1], n;

inline int lowbit(int x) {
    return x & -x;
}

inline void add(int x, int k) {
    while (x <= n) {
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}

inline int getsum(int x) {
    int ans = 0;
    while (x >= 1) {
        ans = ans + c[x];
        x = x - lowbit(x);
    }
    return ans;
}

int main() {
    int m;
    memset(c, 0, sizeof(c));

    scanf("%d%d", &n, &m);

    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        add(i, x);
    }

    while (m--) {
        int m, x, y;
        scanf("%d%d%d", &m, &x, &y);

        if (m == 1) add(x, y);
        else printf("%d\n", getsum(y) - getsum(x - 1));
    }

    return 0;
}