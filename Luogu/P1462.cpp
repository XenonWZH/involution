#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

struct Node {
    std::vector<struct Edge> e;
    int f;
    long long d;
};

struct Edge {
    Node *s, *t;
    int w;

    Edge(Node *s, Node *t, int w) : s(s), t(t), w(w) {}
};

inline void addEdge(Node *u, Node *v, int w) {
    u->e.push_back(Edge(u, v, w));
    v->e.push_back(Edge(v, u, w));
}

int main() {
    int n, m, b;
    scanf("%d %d %d", &n, &m, &b);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &nodes[i].f);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&nodes[u], &nodes[v], w);
    }

    auto check = [&](int limit) {
        for (int i = 1; i <= n; i++) nodes[i].d = INT_MAX;

        std::priority_queue<std::pair<long long, Node *>, std::vector<std::pair<long long, Node *>>, std::greater<std::pair<long long, Node *>>> q;
        nodes[1].d = 0;
        q.push(std::make_pair(0, &nodes[1]));

        while (!q.empty()) {
            const std::pair<int, Node *> p = q.top();
            q.pop();

            Node *u = p.second;

            if (u->d != p.first) continue;
            if (u->d > nodes[n].d) break;

            for (Edge &e : u->e) {
                if (e.t->f > limit) continue;
                if (e.t->d > u->d + e.w) {
                    e.t->d = u->d + e.w;
                    q.push(std::make_pair(e.t->d, e.t));
                }
            }
        }

        return nodes[n].d <= b;
    };

    int l = nodes[1].f, r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r) / 2;

        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    if (l == 1e9 + 1) puts("AFK");
    else printf("%d\n", l);

    return 0;
}