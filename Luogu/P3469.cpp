#include <cstdio>
#include <vector>
#include <algorithm>

struct Node {
    std::vector<struct Edge> e;
    int dfn, low, size;
    bool cut;
    long long ans;
};

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

int n, m;

inline void addEdge(Node *u, Node *v) {
    u->e.emplace_back(u, v);
    v->e.emplace_back(v, u);
}

void tarjan(Node *u, Node *fa) {
    static int ts = 0;
    u->dfn = u->low = ++ts;
    u->size = 1;

    int flag = 0, s = 0;
    for (auto &[u, v] : u->e) {
        if (!v->dfn) {
            tarjan(v, fa);
            u->size += v->size;
            u->low = std::min(u->low, v->low);
            if (v->low >= u->dfn) {
                flag++;
                u->ans += 1ll * v->size * (n - v->size);
                s += v->size;
                if (u != fa || flag > 1) u->cut = true;
            }
        } else u->low = std::min(u->low, v->dfn);
    }

    if (u->cut) u->ans += 1ll * (n - s - 1) * (s + 1) + (n - 1);
    else u->ans = 2 * (n - 1);
}

int main() {
    scanf("%d %d", &n, &m);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == v) continue;
        addEdge(&nodes[u], &nodes[v]);
    }

    tarjan(&nodes[1], &nodes[1]);

    for (int i = 1; i <= n; i++) printf("%lld\n", nodes[i].ans);

    return 0;
}