#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

const int MAXN = 2e5;
const int INF = (1ll << 30);

struct BinaryIndexedTree {
    int a[MAXN + 1];
    int n;

    void init(const int n) {
        memset(a, 0, sizeof(a));
        this->n = n;
    }

    static int lowbit(const int x) {
        return x & -x;
    }

    void update(const int pos, const int delta) {
        for (int i = pos; i <= n; i += lowbit(i)) a[i] += delta;
    }

    int query(const int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }
} bit;

int main() {
    int n, q;
    static long long a[MAXN + 1];

    scanf("%d %d", &n, &q);

    bit.init(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] < 0) bit.update(i, 1);
    }

    while (q--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int i;
            long long k;
            scanf("%d %lld", &i, &k);
            if (a[i] < 0) bit.update(i, -1);
            if (k < 0) bit.update(i, 1);
            a[i] = k;
        } else if (op == 2) {
            int l, r;
            scanf("%d %d", &l, &r);
            if ((bit.query(r) - bit.query(l - 1)) % 2 == 0) {
                long long res = 1;
                for (int i = l; i <= r; i++) {
                    res *= std::abs(a[i]);
                    if (res > INF) break;
                }
                if (res > INF) puts("Too large");
                else printf("%lld\n", res);
            } else {
                long long res = 1, ans = 1;
                for (int i = l; i <= r; i++) {
                    res *= a[i];
                    ans = std::max(ans, res);
                    if (ans > INF) break;
                    if (res < -INF && bit.query(r) - bit.query(i) > 0) {
                        ans = INF + 1;
                        break;
                    }
                    if (res < -INF && bit.query(r) - bit.query(i) == 0) break;
                }
                res = 1;
                for (int i = r; i >= l; i--) {
                    res *= a[i];
                    ans = std::max(ans, res);
                    if (ans > INF) break;
                    if (res < -INF && bit.query(i - 1) - bit.query(l - 1) > 0) {
                        ans = INF + 1;
                        break;
                    }
                    if (res < -INF && bit.query(i - 1) - bit.query(l - 1) == 0) break;
                }

                if (ans > INF) puts("Too large");
                else printf("%lld\n", ans);
            }
        }
    }
    return 0;
}