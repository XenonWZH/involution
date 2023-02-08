#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int MAXN = 50000;
const int MAXM = 500000;

int n, t;
int head[MAXN + 1], ver[MAXM + 1], edge[MAXM + 1], nxt[MAXM + 1], tot;
int dis[MAXN + 1], vis[MAXN + 1];

void add(int u, int v, int w) {
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}

void spfa(int s) {
    memset(dis, 0xcf, sizeof(dis));
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
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void solve() {
    memset(head, 0, sizeof(head));
    tot = 0;

    scanf("%d", &n);

    int max = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b + 1, c);
        max = std::max(max, b + 1);
    }

    for (int i = 1; i <= max; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }

    spfa(0);

    printf("%d\n", dis[max]);
    if (t) puts("");
}

int main() {
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}