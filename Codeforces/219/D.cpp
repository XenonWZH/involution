#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 200000, INF = 0x3f3f3f3f;

int n;
std::vector<int> e[MAXN + 1], eRev[MAXN + 1];
int f[MAXN + 1], ch[MAXN + 1];
bool vis[MAXN + 1];

int dp(int p) {
    if (vis[p]) return f[p];
    vis[p] = true;

    for (int nodes : e[p]) {
        if (!vis[nodes]) {
            f[p] += dp(nodes);
        }
    }

    for (int nodes : eRev[p]) {
        if (!vis[nodes]) {
            f[p] += dp(nodes) + 1;
        }
    }

    // printf("f[%d]: %d\n", p, f[p]);
    return f[p];
}

void dfs(int p) {
    vis[p] = true;

    for (int nodes : e[p]) {
        if (!vis[nodes]) {
            ch[nodes] = ch[p] + 1;
            dfs(nodes);
        }
    }

    for (int nodes : eRev[p]) {
        if (!vis[nodes]) {
            ch[nodes] = ch[p] - 1;
            dfs(nodes);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        eRev[b].push_back(a);
    }

    memset(f, 0, sizeof(f));
    memset(vis, false, sizeof(vis));
    dp(1);

    memset(ch, 0, sizeof(ch));
    memset(vis, false, sizeof(vis));
    ch[1] = f[1];
    dfs(1);

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = std::min(ans, ch[i]);
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)  {
        if (ch[i] == ans) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}