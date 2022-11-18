#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        long long n, m;
        scanf("%lld %lld", &n, &m);

        int remain = 0;
        long long res = n;
        while (res % 2 == 0) remain++, res /= 2;
        while (res % 5 == 0) remain--, res /= 5;

        if (remain == 0) {
            long long tmp = pow(10, floor(log10(m)));
            printf("%lld\n", n * tmp * (m / tmp));
        } else if (remain > 0) {
            while (remain > 0 && m >= 5) remain--, m /= 5, n *= 5;
            long long tmp = pow(10, floor(log10(m)));
            printf("%lld\n", n * tmp * (m / tmp));
        } else {
            remain = -remain;
            while (remain > 0 && m >= 2) remain--, m /= 2, n *= 2;
            long long tmp = pow(10, floor(log10(m)));
            printf("%lld\n", n * tmp * (m / tmp));
        }
    }

    int main() {
        int t;

        scanf("%d", &t);

        while (t--) solve();

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}