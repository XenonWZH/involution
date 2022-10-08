#include <bits/stdc++.h>

const int MAXN = 1e5;

void solve() {
    int n, r1, c1, r2, c2, r3, c3, x, y;
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &r1, &c1, &r2, &c2, &r3, &c3);
    scanf("%d %d", &x, &y);

    int r, c;
    if (r1 == r2) r = r3;
    if (r2 == r3) r = r1;
    if (r3 == r1) r = r2;
    if (c1 == c2) c = c3;
    if (c2 == c3) c = c1;
    if (c3 == c1) c = c2;

    if (std::abs(x - r) % 2 == 0 && std::abs(y - c) % 2 == 0) {
        puts("NO");
        return;
    }

    if (r1 == r2) r = r1;
    if (r2 == r3) r = r2;
    if (r3 == r1) r = r3;
    if (c1 == c2) c = c1;
    if (c2 == c3) c = c2;
    if (c3 == c1) c = c3;

    if (r == 1 && c == 1) {
        if (x == 1 || y == 1) puts("YES");
        else puts("NO");
        return;
    }

    if (r == n && c == 1) {
        if (x == n || y == 1) puts("YES");
        else puts("NO");
        return;
    }

    if (r == 1 && c == n) {
        if (x == 1 || y == n) puts("YES");
        else puts("NO");
        return;
    }

    if (r == n && c == n) {
        if (x == n || y == n) puts("YES");
        else puts("NO");
        return;
    }

    puts("YES");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}