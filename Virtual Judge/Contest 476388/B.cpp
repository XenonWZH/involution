#include <cstdio>

typedef long long ll;
const ll MAXN = 1e6;

int main() {
    ll n, m;
    static ll trees[MAXN];

    scanf("%lld%lld", &n, &m);
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &trees[i]);
    }

    ll l = 0, r = 2e9;
    while (l < r) {
        ll mid = (l + r) >> 1;

        ll sum = 0;
        for (ll i = 0; i < n; i++) sum += trees[i] > mid ? trees[i] - mid : 0;

        if (sum < m) r = mid;
        else l = mid + 1;
    }

    printf("%lld\n", l - 1);

    return 0;
}