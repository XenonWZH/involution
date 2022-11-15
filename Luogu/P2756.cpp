#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

struct Node {
    std::vector<struct Edge> e;
    std::vector<struct Edge>::iterator c;
    int id, l;
};

struct Edge {
    Node *s, *t;
    int c, f, r;

    Edge(Node *s, Node *t, int c, int r) : s(s), t(t), c(c), f(0), r(r) {}
};

inline void addEdge(Node *s, Node *t, int c) {
    s->e.emplace_back(s, t, c, t->e.size());
    t->e.emplace_back(t, s, 0, s->e.size() - 1);
}

struct Dinic {
    std::vector<Node> &nodes;

    Dinic(std::vector<Node> &nodes) : nodes(nodes) {}

    bool level(Node *s, Node *t, int n) {
        for (int i = 0; i <= n; i++) {
            nodes[i].c = nodes[i].e.begin();
            nodes[i].l = 0;
        }

        std::queue<Node *> q;
        q.push(s);

        s->l = 1;

        while (!q.empty()) {
            Node *u = q.front();
            q.pop();

            for (auto &[u, v, c, f, r] : u->e) {
                if (f < c && !v->l) {
                    v->l = u->l + 1;
                    if (v == t) return true;
                    else q.push(v);
                }
            }
        }

        return false;
    }

    int find(Node *s, Node *t, int limit = INT_MAX) {
        if (s == t) return limit;

        for (auto &e = s->c; e != s->e.end(); e++) {
            auto &[u, v, c, f, r] = *e;
            if (f < c && v->l == s->l + 1) {
                int flow = find(v, t, std::min(limit, c - f));
                if (flow) {
                    f += flow;
                    v->e[r].f -= flow;
                    return flow;
                }
            }
        }

        return 0;
    }

    int operator()(int s, int t, int n) {
        int res = 0;
        while (level(&nodes[s], &nodes[t], n)) {
            int f;
            while ((f = find(&nodes[s], &nodes[t])) > 0) res += f;
        }
        return res;
    }
};

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    std::vector<Node> nodes(n + 2);
    for (int i = 1; i <= n; i++) nodes[i].id = i;

    int u, v;
    while (scanf("%d %d", &u, &v) != EOF && u != -1 && v != -1) {
        addEdge(&nodes[u], &nodes[v], INT_MAX);
    }

    for (int i = 1; i <= m; i++) addEdge(&nodes[0], &nodes[i], 1);
    for (int i = m + 1; i <= n; i++) addEdge(&nodes[i], &nodes[n + 1], 1);

    Dinic dinic(nodes);

    printf("%d\n", dinic(0, n + 1, n + 1));
    for (int i = 1; i <= m; i++) {
        for (auto &[u, v, c, f, r] : nodes[i].e) {
            if (u != &nodes[0] && v != &nodes[0] && u != &nodes[n + 1] && v != &nodes[n + 1] && f) {
                    printf("%d %d\n", u->id, v->id);
            }
        }
    }

    return 0;
}