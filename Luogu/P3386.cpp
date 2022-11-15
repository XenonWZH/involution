#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

struct Node {
    std::vector<struct Edge> e;
    std::vector<struct Edge>::iterator c;
    int l;
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
    int n, m, e;
    scanf("%d %d %d", &n, &m, &e);

    std::vector<Node> nodes(n + m + 2);
    while (e--) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[n + v], INT_MAX);
    }

    for (int i = 1; i <= n; i++) addEdge(&nodes[0], &nodes[i], 1);
    for (int i = n + 1; i <= n + m; i++) addEdge(&nodes[i], &nodes[n + m + 1], 1);

    Dinic dinic(nodes);

    printf("%d\n", dinic(0, n + m + 1, n + m + 1));

    return 0;
}