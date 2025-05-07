#include <bits/stdc++.h>

namespace XenonWZH {
const int MAXN = 1e6;

int p[MAXN + 1], primes[MAXN + 1], cnt;

void euler() {
    p[0] = p[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (!p[i]) {
            p[i] = i;
            primes[++cnt] = i;
        }

        for (int j = 1; j <= cnt; j++) {
            if (1ll * i * primes[j] > MAXN) break;
            int t = i * primes[j];

            p[t] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    euler();

    int n;
    scanf("%d", &n);

    static int w[MAXN + 1], c[MAXN + 1];
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

    static std::pair<int, int> f[MAXN + 1][2];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = w[i], res = 0;
        while (j != 1) {
            if (f[p[j]][0].second == c[i]) res = std::max(res, f[p[j]][1].first);
            else res = std::max(res, f[p[j]][0].first);
            j /= p[j];
        }

        res++;
        ans = std::max(res, ans);

        j = w[i];
        while (j != 1) {
            if (f[p[j]][0].second == c[i]) {
                f[p[j]][0] = std::max(f[p[j]][0], std::make_pair(res, c[i]));
                if (f[p[j]][0] < f[p[j]][1]) std::swap(f[p[j]][0].first, f[p[j]][1].first), std::swap(f[p[j]][0].second, f[p[j]][1].second);
            } else if (f[p[j]][1].second == c[i]) {
                f[p[j]][1] = std::max(f[p[j]][1], std::make_pair(res, c[i]));
                if (f[p[j]][0] < f[p[j]][1]) std::swap(f[p[j]][0].first, f[p[j]][1].first), std::swap(f[p[j]][0].second, f[p[j]][1].second);
            } else {
                f[p[j]][1] = std::max(f[p[j]][1], std::make_pair(res, c[i]));
                if (f[p[j]][0] < f[p[j]][1]) std::swap(f[p[j]][0].first, f[p[j]][1].first), std::swap(f[p[j]][0].second, f[p[j]][1].second);
            }
            j /= p[j];
        }
    }

    printf("%d\n", ans);

    return 0;
}
};

int main() { return XenonWZH::main(); }