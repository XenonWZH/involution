#include <bits/stdc++.h>

namespace XenonWZH {
const int MAXN = 1e5;

struct Node {
    std::vector<struct Edge> e;
    int dfn, low, id, deg;
    bool vis, cir;
    struct Connected *scc;
};

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

struct Connected {
    std::vector<Node *> u;
    int id;
} sccs[2 * MAXN + 1];

void addEdge(Node *s, Node *t) {
    s->e.emplace_back(s, t);
    t->deg++;
}

int n, cnt = 0, ans = 0;

void tarjan(Node *u) {
    static int num = 0;
    static std::stack<Node *> stk;
    u->dfn = u->low = ++num;
    stk.push(u);
    u->vis = true;

    for (auto &[u, v] : u->e) {
        if (!v->dfn) {
            tarjan(v);
            u->low = std::min(u->low, v->low);
        } else if (v->vis) u->low = std::min(u->low, v->dfn);
    }

    if (u->dfn == u->low) {
        cnt++;
        sccs[cnt].id = cnt;
        Node *w;
        do {
            w = stk.top();
            stk.pop();
            w->vis = false;
            sccs[cnt].u.push_back(w);
            w->scc = &sccs[cnt];
        } while (u != w);
    }
}

int dfs(Node *u, Node *fa = nullptr) {
    int ans = 0;
    for (auto &[u, v] : u->e) {
        if (v == fa) continue;
        ans = std::max(ans, dfs(v, u));
    }
    return ans + (u->id <= n ? 1 : 0);
}

void solve() {
    scanf("%d", &n);

    std::vector<Node> nodes(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) nodes[i].id = i;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x == i) nodes[i].cir = true;
        addEdge(&nodes[x], &nodes[i]);
    }

    for (int i = 1; i <= 2 * n; i++) if (!nodes[i].dfn) tarjan(&nodes[i]);

    for (int i = 1; i <= cnt; i++) if (sccs[i].u.size() > 1 || (sccs[i].u.size() == 1 && sccs[i].u[0]->cir)) ans += sccs[i].u.size();
    for (int i = 1; i <= 2 * n; i++) if (nodes[i].deg == 0) ans += dfs(&nodes[i]);

    printf("%d\n", ans);
}

int main() {
    int t = 1;

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }