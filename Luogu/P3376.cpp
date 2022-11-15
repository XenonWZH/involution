#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

struct Node {
    std::vector<struct Edge> e;
    std::vector<struct Edge>::iterator c;
    long long l;
};

struct Edge {
    Node *s, *t;
    long long c, f, r;

    Edge(Node *s, Node *t, long long c, long long r) : s(s), t(t), c(c), f(0), r(r) {}
};

inline void addEdge(Node *s, Node *t, long long c) {
    s->e.emplace_back(s, t, c, t->e.size());
    t->e.emplace_back(t, s, 0, s->e.size() - 1);
}

struct Dinic {
    std::vector<Node> &nodes;

    Dinic(std::vector<Node> &nodes) : nodes(nodes) {}

    bool level(Node *s, Node *t, int n) {
        for (int i = 1; i <= n; i++) {
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

    int find(Node *s, Node *t, long long limit = INT_MAX) {
        if (s == t) return limit;

        for (auto &e = s->c; e != s->e.end(); e++) {
            auto &[u, v, c, f, r] = *e;
            if (f < e->c && v->l == s->l + 1) {
                long long flow = find(v, t, std::min(limit, c - f));
                if (flow) {
                    f += flow;
                    v->e[r].f -= flow;
                    return flow;
                }
            }
        }

        return 0;
    }

    long long operator()(Node *s, Node *t, int n) {
        long long res = 0;
        while (level(s, t, n)) {
            long long f;
            while ((f = find(s, t)) > 0) res += f;
        }
        return res;
    }
};

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);

    std::vector<Node> nodes(n + 1);
    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        addEdge(&nodes[u], &nodes[v], c);
    }

    Dinic dinic(nodes);

    printf("%lld\n", dinic(&nodes[s], &nodes[t], n));

    return 0;
}