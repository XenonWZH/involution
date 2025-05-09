#include <bits/stdc++.h>

struct Node {
    int id;
    std::vector<struct Edge> e;
    int low, dfn;
    struct Connected *dcc;
};

struct Edge {
    Node *s, *t;
    bool bridge;
    int r;

    Edge(Node *s, Node *t, int r) : s(s), t(t), bridge(false), r(r) {}
};

struct Connected {
    std::vector<Node *> u;
};

inline void addEdge(Node *u, Node *v) {
    u->e.emplace_back(u, v, v->e.size());
    v->e.emplace_back(v, u, u->e.size() - 1);
}

void tarjan(Node *u, Edge *in = nullptr) {
    static int num = 0;
    u->low = u->dfn = ++num;

    for (Edge &e : u->e) {
        auto &[u, v, bridge, r] = e;
        if (!v->dfn) {
            tarjan(v, &e);
            u->low = std::min(u->low, v->low);
            if (v->low > u->dfn) bridge = v->e[r].bridge = true;
        } else if (in && &e != &in->t->e[in->r]) u->low = std::min(u->low, v->dfn);
    }
}

void dfs(Node *u, Connected *dcc) {
    u->dcc = dcc;
    dcc->u.push_back(u);
    for (auto &[u, v, bridge, r] : u->e) {
        if (v->dcc || bridge) continue;
        dfs(v, dcc);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) nodes[i].id = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
    }

    for (int i = 1; i <= n; i++) {
        if (!nodes[i].dfn) {
            tarjan(&nodes[i]);
        }
    }

    std::vector<Connected> dccs;
    for (int i = 1; i <= n; i++) {
        if (!nodes[i].dcc) {
            dccs.push_back(Connected());
            dfs(&nodes[i], &dccs[dccs.size() - 1]);
        }
    }

    printf("%zu\n", dccs.size());
    for (auto [nodes] : dccs) {
        printf("%zu ", nodes.size());
        for (Node *node : nodes) printf("%d ", node->id);
        putchar('\n');
    }

    return 0;
}