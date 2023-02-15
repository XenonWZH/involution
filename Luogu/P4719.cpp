#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int MAXN = 1e5;
const int INF = 0x3f3f3f3f;

int n, m;
std::vector<int> G[MAXN + 1];
int dfn[MAXN + 1], fa[MAXN + 1], son[MAXN + 1], dep[MAXN + 1], size[MAXN + 1], ts;
int top[MAXN + 1], end[MAXN + 1], dfnRev[MAXN + 1];
int f[MAXN + 1][2], a[MAXN + 1];

struct Matrix {
    int a[2][2];
    Matrix() { memset(a, 0, sizeof(a)); }
    int &operator()(int i, int j) { return a[i][j]; }
    const int &operator()(int i, int j) const { return a[i][j]; }

    friend Matrix operator*(Matrix a, Matrix b) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res(i, j) = std::max(res(i, j), a(i, k) + b(k, j));
                }
            }
        }
        return res;
    }
} g[MAXN + 1];

struct SegT {
    int l, r;
    Matrix dat;
} t[4 * MAXN];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].dat = g[dfnRev[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    t[p].dat = t[2 * p].dat * t[2 * p + 1].dat;
}

void change(int p, int pos) {
    if (t[p].l == t[p].r) {
        t[p].dat = g[dfnRev[pos]];
        return;
    }
    int mid = (t[p].l + t[p].r) / 2;
    if (pos <= mid) change(2 * p, pos);
    else change(2 * p + 1, pos);
    t[p].dat = t[2 * p].dat * t[2 * p + 1].dat;
}

Matrix ask(int p, int l, int r) {
    if (l <= t[p].l && r >= t[p].r) return t[p].dat;
    int mid = (t[p].l + t[p].r) / 2;
    if (r <= mid) return ask(p * 2, l, r);
    if (l > mid) return ask(p * 2 + 1, l, r);
    return ask(p * 2, l, r) * ask(p * 2 + 1, l, r);
}

void dfs1(int u) {
    size[u] = 1, f[u][0] = 0, f[u][1] = a[u];
    for (int v : G[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        size[u] += size[v];
        if (size[v] > size[son[u]]) son[u] = v;
        f[u][0] += std::max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

void dfs2(int u) {
    dfn[u] = ++ts, dfnRev[ts] = u;
    if (!fa[u] || son[fa[u]] != u) top[u] = u;
    else top[u] = top[fa[u]];
    end[top[u]] = std::max(end[top[u]], ts);

    g[u](0, 0) = g[u](0, 1) = 0;
    g[u](1, 0) = a[u], g[u](1, 1) = -INF;

    if (son[u]) dfs2(son[u]);
    for (int v : G[u]) {
        if (fa[v] == u && v != son[u]) {
            dfs2(v);
            g[u](0, 0) += std::max(f[v][0], f[v][1]);
            g[u](0, 1) = g[u](0, 0);
            g[u](1, 0) += f[v][0];
        }
    }
}

void split(int u) {
    dep[u] = 1;
    dfs1(u);
    dfs2(u);
}

void update(int u, int w) {
    g[u](1, 0) += w - a[u];
    a[u] = w;

    Matrix bef, aft;
    while (u) {
        bef = ask(1, dfn[top[u]], end[top[u]]);
        change(1, dfn[u]);
        aft = ask(1, dfn[top[u]], end[top[u]]);
        u = fa[top[u]];

        g[u](0, 0) += std::max(aft(0, 0), aft(1, 0)) - std::max(bef(0, 0), bef(1, 0));
        g[u](0, 1) = g[u](0, 0);
        g[u](1, 0) += aft(0, 0) - bef(0, 0);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    split(1);
    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        update(u, w);
        Matrix ans = ask(1, dfn[1], end[1]);
        printf("%d\n", std::max(ans(0, 0), ans(1, 0)));
    }

    return 0;
}