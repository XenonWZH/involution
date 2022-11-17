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
    int s, t;
    int c, f, r;

    Edge(int s, int t, int c, int r) : s(s), t(t), c(c), f(0), r(r) {}
};

struct Dinic {
    std::vector<Node> &nodes;

    Dinic(std::vector<Node> &nodes) : nodes(nodes) {}

    inline void addEdge(int s, int t, int c) {
        nodes[s].e.emplace_back(s, t, c, nodes[t].e.size());
        nodes[t].e.emplace_back(t, s, c, nodes[s].e.size() - 1);
    }

    bool level(int s, int t, int n) {
        for (int i = 0; i < n; i++) {
            nodes[i].c = nodes[i].e.begin();
            nodes[i].l = 0;
        }

        std::queue<int> q;
        q.push(s);

        nodes[s].l = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &[u, v, c, f, r] : nodes[u].e) {
                if (f < c && !nodes[v].l) {
                    nodes[v].l = nodes[u].l + 1;
                    if (v == t) return true;
                    else q.push(v);
                }
            }
        }

        return false;
    }

    int find(int s, int t, int limit = INT_MAX) {
        if (s == t) return limit;

        for (auto &e = nodes[s].c; e != nodes[s].e.end(); e++) {
            auto &[u, v, c, f, r] = *e;
            if (f < c && nodes[v].l == nodes[s].l + 1) {
                int flow = find(v, t, std::min(limit, c - f));
                if (flow) {
                    f += flow;
                    nodes[v].e[r].f -= flow;
                    return flow;
                }
            }
        }

        return 0;
    }

    int operator()(int s, int t, int n) {
        int res = 0;
        while (level(s, t, n)) {
            int f;
            while ((f = find(s, t)) > 0) res += f;
        }
        return res;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<Node> nodes(n * m + 2);
    Dinic dinic(nodes);

    int s = 0, t = n * m + 1;
    auto id = [&](int i, int j) { return (i - 1) * m + j; };

    dinic.addEdge(s, id(1, 1), INT_MAX);
    dinic.addEdge(id(n, m), t, INT_MAX);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) {
            int c;
            scanf("%d", &c);
            dinic.addEdge(id(i, j), id(i, j + 1), c);
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            int c;
            scanf("%d", &c);
            dinic.addEdge(id(i, j), id(i + 1, j), c);
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            int c;
            scanf("%d", &c);
            dinic.addEdge(id(i, j), id(i + 1, j + 1), c);
        }
    }

    printf("%d\n", dinic(s, t, n * m + 2));

    return 0;
}