#include <bits/stdc++.h>

typedef long long ll;

struct Node {
    ll t, y;
    int x;

    bool operator<(Node u) { return t > u.t; }
};

int main() {
    int n, m;
    ll k;
    scanf("%d %d %lld", &n, &m, &k);

    std::vector<Node> a(m + 1);
    for (int i = 1; i <= m; i++) scanf("%lld %d %lld", &a[i].t, &a[i].x, &a[i].y), a[i].y--;

    bool bre = true;
    for (int i = 2; i <= m; i++) if (a[i].x != a[i - 1].x) bre = false;
    if (bre) {
        puts("-1");
        return 0;
    }

    std::sort(a.begin() + 1, a.end());
    auto calc = [&](ll t, int i) -> ll { return (t + 1 - a[i].t) - a[i].y / k; };

    auto check = [&](ll t) -> bool {
        ll tt = t;
        std::vector<ll> res(m + 1), rm(n + 1);
        for (int i = 1; i <= m; i++) res[i] = calc(t, i);
        for (int i = 1; i <= m; i++) {
            if (rm[a[i].x] < res[i]) {
                if (a[i].t > tt) continue;
                if (t - a[i].t + 1 + rm[a[i].x] - res[i] < 0) return false;
                t += rm[a[i].x] - res[i];
                rm[a[i].x] = res[i];
            }
        }
        return true;
    };

    ll l = 0, r = 4e18 + 100;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    printf("%lld\n", l);

    return 0;
}