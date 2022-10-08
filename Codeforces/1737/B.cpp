#include <bits/stdc++.h>

inline void solve(){
    long long l, r;

    scanf("%lld %lld", &l, &r);
    l--;

    long long lres = 0;
    if (l > 0) {
        long long lsq = sqrt(l);
        lres += 3 * (lsq - 1) + 1;
        lres += (l - lsq * lsq) / lsq;
    }

    long long rres = 0;
    if (r > 0) {
        long long rsq = sqrt(r);
        rres += 3 * (rsq - 1) + 1;
        rres += (r - rsq * rsq) / rsq;
    }

    printf("%lld\n", rres - lres);
}

int main(){
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}