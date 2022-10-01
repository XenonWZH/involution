#include <cstdio>
#include <iostream>
#include <algorithm>

const int MAXN = 1e5;

void solve() {
    int n;
    static long long a[MAXN + 1], b[MAXN + 1];

    scanf("%d", &n);

    static long long c[MAXN + 1], d[MAXN + 1];
    int lc = 0, ld = 0;

    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        if (a[i] == 0)
            c[++lc] = b[i];
        else
            d[++ld] = b[i];
    }

    std::sort(c + 1, c + lc + 1);
    std::sort(d + 1, d + ld + 1);

    if (lc == n || ld == n) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) ans += b[i];
        printf("%lld\n", ans);
        return;
    }

    long long ans1 = c[1] + 2 * d[ld];
    int pc = lc, pd = ld - 1;
    bool flag = true;
    while (true) {
        if (flag) {
            if (pc <= 1) break;
            ans1 += 2 * c[pc--];
        } else {
            if (pd <= 0) break;
            ans1 += 2 * d[pd--];
        }
        flag ^= true;
    }
    if (pc <= 1)
        for (int i = 1; i <= pd; i++) ans1 += d[i];
    else
        for (int i = 2; i <= pc; i++) ans1 += c[i];

    long long ans2 = d[1] + 2 * c[lc];
    pc = lc - 1, pd = ld;
    flag = false;
    while (true) {
        if (flag) {
            if (pc <= 0) break;
            ans2 += 2 * c[pc--];
        } else {
            if (pd <= 1) break;
            ans2 += 2 * d[pd--];
        }
        flag ^= true;
    }
    if (pc <= 0)
        for (int i = 2; i <= pd; i++) ans2 += d[i];
    else
        for (int i = 1; i <= pc; i++) ans2 += c[i];

    printf("%lld\n", std::max(ans1, ans2));
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}