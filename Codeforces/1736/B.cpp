#include <bits/stdc++.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    if (n == 1) {
        puts("YES");
        return;
    }

    std::vector<int> b(n + 1);
    b[0] = a[0];
    for (int i = 1; i < n; i++) b[i] = lcm(a[i], a[i - 1]);
    b[n] = a[n - 1];

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = gcd(b[i], b[i + 1]);

    for (int i = 0; i < n; i++) {
        if (a[i] != c[i]) {
            puts("NO");
            return;
        }
    }

    puts("YES");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}