#include <bits/stdc++.h>

namespace XenonWZH {
    const int MAXN = 2e5;

    int aa[MAXN + 1], t[MAXN + 1];
    long long ans;

    void merge(int ll, int rr) {
        if (rr - ll <= 1) return;
        int mid = ll + (rr - ll) / 2;
        merge(ll, mid);
        merge(mid, rr);
        int p = ll, q = mid, s = ll;
        while (s < rr) {
            if (p >= mid || (q < rr && aa[p] > aa[q])) {
                t[s++] = aa[q++];
                ans += mid - p;
            } else t[s++] = aa[p++];
        }
        for (int i = ll; i < rr; i++) aa[i] = t[i];
    }

    void solve() {
        int n;
        scanf("%d", &n);

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        std::vector<int> b(a), c(a);
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                b[i] = 1;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] == 1) {
                c[i] = 0;
                break;
            }
        }

        long long res = 0;
        for (int i = 0; i < n; i++) aa[i] = a[i];
        ans = 0;
        merge(0, n);
        res = std::max(res, ans);
        for (int i = 0; i < n; i++) aa[i] = b[i];
        ans = 0;
        merge(0, n);
        res = std::max(res, ans);
        for (int i = 0; i < n; i++) aa[i] = c[i];
        ans = 0;
        merge(0, n);
        res = std::max(res, ans);

        printf("%lld\n", res);
    }

    int main() {
        int t;

        scanf("%d", &t);

        while (t--) solve();

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}