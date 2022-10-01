#include <cstdio>
#include <iostream>

const int MAXN = 1e5;

void solve() {
    int n, k;
    static long long s[MAXN + 1], a[MAXN + 1];

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) s[i] = a[i] = 0;
    for (int i = n - k + 1; i <= n; i++) scanf("%lld", &s[i]);
    for (int i = n - k + 2; i <= n; i++) a[i] = s[i] - s[i - 1];
    if (n == 1 || k == 1) {
        puts("Yes");
        return;
    }
    if (n == 2) {
        if (k == 1)
            puts("Yes");
        else if (s[1] <= s[2] - s[1])
            puts("Yes");
        else
            puts("No");
        return;
    }
    for (int i = n - k + 3; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            puts("No");
            return;
        }
    }
    if (n == k && s[1] > a[2]) {
        puts("No");
        return;
    }
    if (a[n - k + 2] * (n - k + 1) < s[n - k + 1])
        puts("No");
    else
        puts("Yes");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}