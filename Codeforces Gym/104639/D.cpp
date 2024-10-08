#include <bits/stdc++.h>

struct UnionFindSet {
    std::vector<int> a;

    void init(int n) {
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) a[i] = i;
    }

    int find(int x) {
        return x == a[x] ? x : (a[x] = find(a[x]));
    }

    void merge(int x, int y) {
        a[find(x)] = find(y);
    }
} ufs;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    ufs.init(n);
    std::vector<int> cntv(n + 1, 0), cntd(n + 1, 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int t1 = cntv[ufs.find(u)], t2 = cntv[ufs.find(v)];
        int t3 = cntd[ufs.find(u)], t4 = cntd[ufs.find(v)];
        if (ufs.find(u) != ufs.find(v)) {
            ufs.merge(u, v);
            cntv[ufs.find(u)] = t1 + t2;
            cntd[ufs.find(u)] = t3 + t4;
        }
        cntv[ufs.find(u)]++;
    }

    std::vector<bool> vis(n + 1, false);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[ufs.find(i)]) {
            vis[ufs.find(i)] = true;
            ans += 1ll * cntd[ufs.find(i)] * (cntd[ufs.find(i)] - 1) / 2 - cntv[ufs.find(i)];
        }
    }

    if (ans == 0) {
        std::vector<int> mx;
        for (int i = 1; i <= n; i++) vis[i] = false;
        for (int i = 1; i <= n; i++) {
            if (!vis[ufs.find(i)]) {
                vis[ufs.find(i)] = true;
                mx.push_back(cntd[ufs.find(i)]);
            }
        }
        std::sort(mx.begin(), mx.end());
        ans += 1ll * mx[0] * mx[1];
    }

    printf("%lld\n", ans);

    return 0;
}