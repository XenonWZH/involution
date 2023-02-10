#include <cstdio>
#include <cmath>
#include <map>

typedef long long ll;

namespace QPow {
    void solve(ll y, ll z, ll p) {
        ll ans = 1;
        for (; z; z >>= 1, y = y * y % p) if (z & 1) ans = ans * y % p;
        printf("%lld\n", ans);
    }
};

namespace Exgcd {
    ll exgcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, x, y);
        ll z = x;
        x = y, y = z - (a / b) * y;
        return d;
    }

    void solve(ll y, ll z, ll p) {
        ll a, b;
        ll d = exgcd(y, p, a, b);
        if (z % d != 0) puts("Orz, I cannot find x!");
        else printf("%lld\n", (a * (z / d) % p + p) % p);
    }
};

namespace BSGS {
    ll power(ll a, ll b, ll p) {
        ll ans = 1;
        for (; b; b >>= 1, a = a * a % p) if (b & 1) ans = ans * a % p;
        return ans;
    }

    void solve(ll y, ll z, ll p) {
        if (y % p == 0) {
            puts(z % p == 0 ? "1" : "Orz, I cannot find x!");
            return;
        }

        std::map<ll, ll> hash;
        y %= p;
        ll t = (ll)sqrt(p) + 1;
        for (int j = 0; j < t; j++) {
            ll val = z * power(y, j, p) % p;
            hash[val] = j;
        }
        y = power(y, t, p);
        if (y == 0) {
            puts(z == 0 ? "1" : "Orz, I cannot find x!");
            return;
        }
        for (int i = 0; i <= t; i++) {
            int val = power(y, i, p);
            int j = hash.find(val) == hash.end() ? -1 : hash[val];
            if (j >= 0 && i * t - j >= 0) {
                printf("%lld\n", i * t - j);
                return;
            }
        }
        puts("Orz, I cannot find x!");
    }
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    while (n--) {
        ll y, z, p;
        scanf("%lld %lld %lld", &y, &z, &p);

        if (k == 1) QPow::solve(y, z, p);
        else if (k == 2) Exgcd::solve(y, z, p);
        else BSGS::solve(y, z, p);
    }

    return 0;
}