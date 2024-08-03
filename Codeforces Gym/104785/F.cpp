#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

typedef long long ll;

const int MAXN = 1e6;

int n;
std::vector<int> G[2 * MAXN + 1];
int ans[2 * MAXN + 1];
bool vis[2 * MAXN + 1];

std::vector<int> q;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;

    q.push_back(u);

    ans[u] = q.end() - std::upper_bound(q.begin(), q.end(), u + n, std::greater<int>()) - 1;

    for (int v : G[u]) dfs(v);

    q.pop_back();
}

int main() {
    ll c;
    scanf("%d %lld", &n, &c);

    std::vector<ll> d(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);

    std::vector<ll> a(2 * n + 1);
    for (int i = 1; i <= n; i++) a[i] = a[n + i] = d[i];

    std::vector<ll> s(2 * n + 1);
    s[0] = 0;
    for (int i = 1; i <= 2 * n; i++) s[i] = s[i - 1] + a[i];

    for (int i = 0; i <= 2 * n; i++) {
        auto x = std::lower_bound(s.begin(), s.end(), s[i] + c);
        if (x != s.end()) G[x - s.begin()].push_back(i);
    }

    for (int i = 2 * n; i >= 0; i--) dfs(i);

    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    puts("");

    return 0;
}