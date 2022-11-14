#include <cstdio>
#include <vector>

struct Node {
    std::vector<struct Edge> e;
    int sg;

    Node() : sg(-1) {}
};

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

inline void addEdge(Node *s, Node *t) {
    s->e.emplace_back(s, t);
}

int SG(Node *u, int n) {
    if (u->sg != -1) return u->sg;

    bool flag = false;
    std::vector<int> vis(n + 1, 0);
    int max = 0;
    for (auto &[u, v] : u->e) {
        flag = true;
        max = std::max(max, SG(v, n));
        vis[SG(v, n)] = true;
    }

    if (flag){
        u->sg = 0;
        while (u->sg <= max && vis[u->sg]) u->sg++;
    } else u->sg = 0;

    return u->sg;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(&nodes[x], &nodes[y]);
    }

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        ans ^= SG(&nodes[x], n);
    }

    puts(ans ? "win" : "lose");

    return 0;
}