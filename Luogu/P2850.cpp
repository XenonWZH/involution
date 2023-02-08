#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int MAXN = 500;
const int MAXM = 10000;

int n, m, w;
int head[MAXN + 1], ver[MAXM + MAXN + 1], nxt[MAXM + MAXN + 1], edge[MAXM + MAXN + 1], tot;
int dis[MAXN + 1], vis[MAXN + 1], cnt[MAXN + 1];

void add(int u, int v, int w) {
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}

bool spfa(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
    std::queue<int> q;
    q.push(s);
    dis[s] = 0, vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (int i = head[u]; i; i = nxt[i]) {
            int v = ver[i], w = edge[i];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n) return false;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return true;
}

void init() {
    memset(head, 0, sizeof(head));
    memset(ver, 0, sizeof(ver));
    memset(nxt, 0, sizeof(nxt));
    memset(edge, 0, sizeof(edge));
}

void solve() {
    init();
    tot = 0;
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d\n", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= w; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, -w);
    }

    for (int i = 1; i <= n; i++) add(0, i, 0);
    puts(spfa(0) ? "NO" : "YES");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}