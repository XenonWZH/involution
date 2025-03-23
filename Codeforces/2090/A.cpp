#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    ll x, y, a;
    scanf("%lld %lld %lld", &x, &y, &a);

    a++;
    a %= x + y;
    if (a == 0) puts("YES");
    else if (a <= x) puts("NO");
    else puts("YES");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}