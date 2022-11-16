#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

struct Node {
    std::vector<struct Edge> e;
    struct Edge *in;
    int f, d;
    bool q;
};

struct Edge {
    Node *s, *t;
    int c, f, w, r;

    Edge(Node *s, Node *t, int c, int w, int r) : s(s), t(t), c(c), f(0), w(w), r(r) {}
};

inline void addEdge(Node *s, Node *t, int c, int w) {
    s->e.emplace_back(s, t, c, w, t->e.size());
    t->e.emplace_back(t, s, 0, -w, s->e.size() - 1);
}

inline void ek(std::vector<Node> &nodes, int s, int t, int n, int &flow, int &cost) {
    flow = cost = 0;
    while (true) {
        for (int i = 1; i <= n; i++) {
            nodes[i].q = false;
            nodes[i].f = 0;
            nodes[i].d = INT_MAX;
            nodes[i].in = nullptr;
        }

        std::queue<Node *> q;
        q.push(&nodes[s]);
        nodes[s].f = INT_MAX, nodes[s].d = 0;

        while (!q.empty()) {
            Node *u = q.front();
            q.pop();

            u->q = false;

            for (Edge &e : u->e) {
                auto &[u, v, c, f, w, r] = e;
                if (f < c && v->d > u->d + w) {
                    v->d = u->d + w;
                    v->in = &e;
                    v->f = std::min(u->f, c - f);
                    if (!v->q) {
                        v->q = true;
                        q.push(v);
                    }
                }
            }
        }

        if (nodes[t].d == INT_MAX) return;

        for (Edge *e = nodes[t].in; e; e = e->s->in) {
            e->f += nodes[t].f;
            e->t->e[e->r].f -= nodes[t].f;
        }

        flow += nodes[t].f;
        cost += nodes[t].f * nodes[t].d;
    }
}

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        addEdge(&nodes[u], &nodes[v], w, c);
    }

    int flow, cost;
    ek(nodes, s, t, n, flow, cost);

    printf("%d %d\n", flow, cost);

    return 0;
}