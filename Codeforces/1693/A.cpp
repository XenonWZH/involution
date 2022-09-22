#include <cstdio>
#include <iostream>

const int MAXN = 2e5;

inline void solve() {
    int n;
    static long long a[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    while (a[n] == 0 && n > 0) n--;

    for (int i = 1; i <= n - 1; i++) a[i]--;
    for (int i = n; i > 1; i--) {
        if (a[i] >= 0) {
            puts("No");
            return;
        } else {
            a[i - 1] += a[i] + 1;
            a[i] = 0;
        }
    }

    if (a[1] == 0) puts("Yes");
    else puts("No");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}