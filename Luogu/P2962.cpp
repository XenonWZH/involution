#include <cstdio>
#include <climits>
#include <vector>
#include <map>

const int MAXN = 35;

int n, m, ans = INT_MAX;
std::vector<int> e[MAXN];
std::map<long long, int> mp;

void dfs1(long long s, int p, int mx, int cnt) {
    mp[s] = mp[s] == 0 ? cnt : std::min(mp[s], cnt);
    if (s == (1ll << n) - 1) ans = std::min(ans, cnt);
    if (p >= mx) return;

    dfs1(s, p + 1, mx, cnt);

    long long res = s ^ (1ll << p);
    for (int adj : e[p]) res ^= (1ll << adj);
    dfs1(res, p + 1, mx, cnt + 1);
}

void dfs2(long long s, int p, int mx, int cnt) {
    if (mp[s]) ans = std::min(ans, mp[s] + cnt);
    if (s == 0) ans = std::min(ans, cnt);
    if (p >= mx) return;

    dfs2(s, p + 1, mx, cnt);

    long long res = s ^ (1ll << p);
    for (int adj : e[p]) res ^= (1ll << adj);
    dfs2(res, p + 1, mx, cnt + 1);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
    }

    dfs1(0, 0, n / 2, 0);
    dfs2((1ll << n) - 1, n / 2, n, 0);

    printf("%d\n", ans);

    return 0;
}