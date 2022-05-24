#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 10000000;

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    static long long diff2[MAXN + 3];
    memset(diff2, 0, sizeof(diff2));

    for (int i = 0; i < m; i++) {
        int l, r;
        long long s, e;
        scanf("%d %d %lld %lld", &l, &r, &s, &e);

        if (l == r) {
            diff2[l] += s;
            diff2[r + 1] -= s + e;
            diff2[r + 2] += e;
        } else {
            long long d = (e - s) / (r - l);
            diff2[l] += s;
            diff2[l + 1] -= s - d;
            diff2[r + 1] -= e + d;
            diff2[r + 2] += e;
        }
    }

    static long long diff[MAXN + 1];
    diff[0] = 0;
    for (int i = 1; i <= n; i++) {
        diff[i] = diff2[i] + diff[i - 1];
    }

    long long sumXor = 0, maxN = 0, each = 0;
    for (int i = 1; i <= n; i++) {
        each += diff[i];
        sumXor ^= each;
        maxN = std::max(maxN, each);

#ifdef DBG
    printf("%lld ", each);
#endif
    }
#ifdef DBG
    putchar('\n');
#endif

    printf("%lld %lld\n", sumXor, maxN);

    return 0;
}