#include <climits>
#include <iostream>
#include <string>
#include <sstream>
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::cin.ignore();

    std::vector<Node> nodes(n + m + 2);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        std::string s;
        std::getline(std::cin, s);
        std::stringstream ss(s);
        int t;
        ss >> t;
        sum += t;
        addEdge(&nodes[0], &nodes[i], t);
        while (ss >> t) addEdge(&nodes[i], &nodes[m + t], INT_MAX);
    }
    for (int i = 1; i <= n; i++) {
        int t;
        std::cin >> t;
        addEdge(&nodes[m + i], &nodes[n + m + 1], t);
    }

    Dinic dinic(nodes);
    int ans = sum - dinic(0, n + m + 1, n + m + 1);

    for (int i = 1; i <= m; i++) {
        if (nodes[i].l) {
            printf("%d ", i);
        }
    }
    putchar('\n');
    for (int i = 1; i <= n; i++) {
        if (nodes[m + i].l) {
            printf("%d ", i);
        }
    }
    putchar('\n');
    printf("%d\n", ans);

    return 0;
}