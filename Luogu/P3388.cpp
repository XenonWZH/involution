#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 2e4;

struct Node {
    std::vector<struct Edge> e;
    int dfn, low;
    bool cut;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
    N[t].e.push_back(Edge(&N[t], &N[s]));
}

void tarjan(Node *v, Node *root) {
    static int counts = 0;
    v->dfn = v->low = ++counts;
    int flag = 0;
    for (Edge *e = &v->e.front(); e  && e <= &v->e.back(); e++) {
        Node *u = e->t;
        if (!u->dfn) {
            tarjan(u, root);
            v->low = std::min(v->low, u->low);
            if (u->low >= v->dfn) {
                flag++;
                if (v != root || flag > 1) v->cut = true;
            }
        } else v->low = std::min(v->low, u->dfn);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(x, y);
    }

    for (int i = 1; i <= n; i++) {
        Node *v = &N[i];
        if (!v->dfn) tarjan(v, v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        Node *v = &N[i];
        if (v->cut) ans++;
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        Node *v = &N[i];
        if (v->cut) printf("%d ", i);
    }
    putchar('\n');

    return 0;
}