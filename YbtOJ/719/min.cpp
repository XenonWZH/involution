#include <cstdio>
#include <iostream>

const int MAXN = 1e6;

int main() {
#ifndef DBG
    freopen("min.in", "r", stdin);
    freopen("min.out", "w", stdout);
#endif

    int n, l;
    static int a[MAXN + 1];

    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    long long nowL = 0, nowR = 0, ans, mxL;
    int left = l, right = 2 * l;
    for (int i = 1; i <= l; i++) nowL += a[i];
    for (int i = l + 1; i <= 2 * l; i++) nowR += a[i];
    ans = nowL + nowR;
    mxL = nowL;

    while (right < n) {
        left++, right++;
        nowL += a[left] - a[left - l];
        mxL = std::max(nowL, mxL);
        nowR += a[right] - a[right - l];
        ans = std::max(ans, mxL + nowR);
    }

    printf("%lld\n", ans);

#ifndef DBG
    fclose(stdout);
    fclose(stdout);
#endif

    return 0;
}