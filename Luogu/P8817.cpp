#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
    int id;
    std::vector<struct Edge> e;
    unsigned long long s;
    bool v;
};

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

inline void addEdge(Node *s, Node *t) {
    s->e.push_back(Edge(s, t));
    t->e.push_back(Edge(t, s));
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    k++;

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) nodes[i].id = i;
    for (int i = 2; i <= n; i++) scanf("%lld", &nodes[i].s);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(&nodes[x], &nodes[y]);
    }

    std::vector<std::vector<int>> steps(n + 1, std::vector<int>(n + 1, INT_MAX));

    auto bfs = [&](Node *u) {
        for (int i = 1; i <= n; i++) nodes[i].v = false;

        std::queue<std::pair<int, Node *>> q;
        u->v = true, steps[u->id][u->id] = 0;
        q.push(std::make_pair(0, u));

        while (!q.empty()) {
            const std::pair<int, Node *> p = q.front();
            q.pop();
            int step = p.first;
            Node *v = p.second;

            for (Edge &e : v->e) {
                if (!e.t->v) {
                    steps[u->id][e.t->id] = step + 1;
                    e.t->v = true;
                    q.push(std::make_pair(step + 1, e.t));
                }
            }
        }
    };

    for (int i = 1; i <= n; i++) bfs(&nodes[i]);

    std::vector<std::vector<Node *>> att(n + 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i == j) continue;
            if (steps[i][j] <= k && steps[j][1] <= k) {
                att[i].push_back(&nodes[j]);
            }
        }
    }
    for (int i = 2; i <= n; i++) std::sort(att[i].begin(), att[i].end(), [](Node *a, Node *b){ return a->s > b->s; });

    unsigned long long ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i == j || steps[i][j] > k || att[i].empty() || att[j].empty()) continue;
            std::vector<Node *>::iterator itB = att[i].begin(), itC = att[j].begin();
            if (*itB == &nodes[j]) itB++;
            if (*itC == &nodes[i]) itC++;
            if (itB == att[i].end() || itC == att[j].end()) continue;
            if (*itB == *itC) {
                if (itB + 1 != att[i].end() && *(itB + 1) != &nodes[j] && *(itB + 1) != *itC) ans = std::max(ans, nodes[i].s + nodes[j].s + (*(itB + 1))->s + (*itC)->s);
                if (itC + 1 != att[j].end() && *(itC + 1) != &nodes[i] && *(itC + 1) != *itB) ans = std::max(ans, nodes[i].s + nodes[j].s + (*itB)->s + (*(itC + 1))->s);
            } else ans = std::max(ans, nodes[i].s + nodes[j].s + (*itB)->s + (*itC)->s);
        }
    }

    printf("%lld\n", ans);

    return 0;
}