#include <cstdio>
#include <vector>
#include <algorithm>

struct Node {
    int id;
    std::vector<struct Edge> e;
    struct Edge *cur;
    int inDeg, outDeg;
};

struct Edge {
    Node *s, *t;
    bool vis;

    Edge(Node *s, Node *t) : s(s), t(t), vis(false) {}
};

inline void addEdge(Node *s, Node *t) {
    s->e.push_back(Edge(s, t));
    s->cur = &s->e.front();
    s->outDeg++;
    t->inDeg++;
}

std::vector<Edge *> path;

inline void dfs(Node *v) {
    while (v->cur && v->cur <= &v->e.back()) {
        Edge *e = v->cur;
        v->cur++;

        dfs(e->t);

        path.push_back(e);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) nodes[i].id = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
    }
    for (int i = 1; i <= n; i++) std::sort(nodes[i].e.begin(), nodes[i].e.end(), [](Edge a, Edge b){ return a.t->id < b.t->id; });

    bool haveAns = true;
    int cnt0 = 0, cnt1 = 0;
    Node *s = &nodes[1];
    for (int i = 1; i <= n; i++) {
        if (nodes[i].inDeg != nodes[i].outDeg) haveAns = false;
        if (nodes[i].inDeg - nodes[i].outDeg == 1) cnt1++;
        if (nodes[i].outDeg - nodes[i].inDeg == 1) cnt0++, s = &nodes[i];
    }
    if (!haveAns && !(cnt0 == 1 && cnt1 == 1)) {
        puts("No");
        return 0;
    }

    dfs(s);

    printf("%d ", path.back()->s->id);
    for (int i = path.size() - 1; i >= 0; i--) printf("%d ", path[i]->t->id);
    putchar('\n');

    return 0;
}