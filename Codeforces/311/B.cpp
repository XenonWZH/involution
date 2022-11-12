#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    p = std::min(p, m);
    std::vector<int> d(n + 1);
    for(int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        d[i] = d[i - 1] + x;
    }

    std::vector<long long> a(m + 1);
    for(int i = 1; i <= m; i++) {
        int h, t;
        scanf("%d %d", &h, &t);
        a[i] = t - d[h];
    }
    std::sort(a.begin() + 1, a.end());

    std::vector<long long> s(m + 1);
    for(int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];

    std::vector<std::vector<long long>> f(p + 1, std::vector<long long>(m + 1));
    for(int i = 1; i <= m; i++) f[1][i] = a[i] * i - s[i];

    for(int i = 2; i <= p; i++) {
        int l = 0, r = 0;
        std::vector<long long> q(m + 1);
        std::vector<long long> c(m + 1);
        for(int j = i - 1; j <= m; j++) c[j] = s[j] + f[i - 1][j];
        q[r++] = i - 1;
        for(int j = i; j <= m; j++) {
            while(l + 1 < r && -q[l] * a[j] + c[q[l]] >= -q[l + 1] * a[j] + c[q[l + 1]]) l++;
            f[i][j] = f[i - 1][q[l]] + a[j] * (j - q[l]) - (s[j] - s[q[l]]);
            while(r > l + 1 && (c[q[r - 1]] - c[q[r - 2]]) * (j - q[r - 1]) >= (c[j] - c[q[r - 1]]) * (q[r - 1] - q[r - 2])) r--;
            q[r++] = j;
        }
    }

    printf("%lld\n", f[p][m]);

    return 0;
}