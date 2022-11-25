#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

struct Node {
    std::vector<struct Edge> e;
    int d, cnt;
    bool v;
};

struct Edge {
    Node *s, *t;
    int w;

    Edge(Node *s, Node *t, int w) : s(s), t(t), w(w) {}
};

inline void addEdge(Node *s, Node *t, int w) {
    s->e.emplace_back(s, t, w);
    if (w >= 0) t->e.emplace_back(t, s, w);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        std::vector<Node> nodes(n + 1);
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addEdge(&nodes[u], &nodes[v], w);
        }

        auto spfa = [&](const int s) {
            for (int i = 1; i <= n; i++) nodes[i].d = INT_MAX;

            std::queue<Node *> q;
            q.push(&nodes[s]);
            nodes[s].d = 0, nodes[s].v = true;

            while (!q.empty()) {
                Node *u = q.front();
                q.pop();
                u->v = false;
                for (auto &[u, v, w] : u->e) {
                    if (v->d > u->d + w) {
                        v->d = u->d + w;
                        v->cnt = u->cnt + 1;
                        if (v->cnt >= n) return false;
                        if (!v->v) {
                            q.push(v);
                            v->v = true;
                        }
                    }
                }
            }

            return true;
        };

        if (spfa(1)) puts("NO");
        else puts("YES");
    }

    return 0;
}