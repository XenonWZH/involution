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

inline void addEdge(Node *u, Node *v, int w) {
    u->e.push_back(Edge(u, v, w));
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) addEdge(&nodes[0], &nodes[i], 0);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&nodes[v], &nodes[u], w);
    }

    auto spfa = [&]() {
        for (int i = 0; i <= n; i++) nodes[i].d = INT_MAX;

        std::queue<Node *> q;
        nodes[0].d = 0, nodes[0].v = true;
        q.push(&nodes[0]);

        while (!q.empty()) {
            Node *u = q.front();
            q.pop();
            u->v = false;
            for (Edge &e : u->e) {
                if (e.t->d > u->d + e.w) {
                    e.t->d = u->d + e.w;
                    e.t->cnt = u->cnt + 1;
                    if (e.t->cnt >= n + 1) return false;
                    if (!e.t->v) {
                        q.push(e.t);
                        e.t->v = true;
                    }
                }
            }
        }

        return true;
    };

    if (!spfa()) {
        puts("NO");
        return 0;
    }

    for (int i = 1; i <= n; i++) printf("%d ", nodes[i].d);
    putchar('\n');

    return 0;
}