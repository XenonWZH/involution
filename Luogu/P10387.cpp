#include <bits/stdc++.h>

typedef long long ll;
#define fi first
#define se second

int main() {
    int n;
    ll s;
    scanf("%d %lld", &n, &s);

    std::vector<std::pair<int, int>> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].se, &a[i].fi);
        sum += a[i].se;
    }

    std::sort(a.begin(), a.end());

    int bef = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (sum >= s) {
            ans += 1ll * s * (a[i].fi - bef);
            bef = a[i].fi;
            sum -= a[i].se;
        } else ans += 1ll * a[i].se * (a[i].fi - bef);
    }

    printf("%lld\n", ans);

    return 0;
}