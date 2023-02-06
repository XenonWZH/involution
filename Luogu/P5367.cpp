#include <bits/stdc++.h>

namespace XenonWZH {
    const int MAXN = 1000000;
    const int MOD = 998244353;

    struct BinaryIndexedTree {
        int a[MAXN + 1], n;

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
        int n;
        scanf("%d", &n);

        static int a[MAXN + 1];
        bit.init(n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            bit.update(a[i], 1);
        }

        static long long fac[MAXN + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;

        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans + (bit.query(a[i] - 1) * fac[n - i]) % MOD) % MOD;
            bit.update(a[i], -1);
        }

        printf("%lld\n", ans);

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}