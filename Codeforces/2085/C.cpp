#include <bits/stdc++.h>

typedef long long ll;

void solve() {
    ll x, y;
    scanf("%lld %lld", &x, &y);

    ll ans = 0;
    int p = 0;
    for (int i = 0; (1ll << i) <= std::max(x, y); i++) {
        if ((((x >> i) & 1) && ((y >> i) & 1))) {
            bool con = true;
            ll tmp = 0;
            for (int j = i - 1; j >= 0; j--) {
                tmp += 1ll << j;
                if (((x >> j) & 1) ^ ((y >> j) & 1)) {
                    con = false;
                    break;
                }
            }
            if (con) {
                ans += 1ll << i;
                x += 1ll << i, y += 1ll << i;
            } else {
                ans += tmp;
                x += tmp, y += tmp;
            }
        }

        if ((x == y && x != 0) || ((1ll << i) <= std::min(x, y) && (1ll << (i + 1)) > std::max(x, y))) {
            puts("-1");
            return;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}