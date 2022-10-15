#include <cstdio>
#include <vector>
#include <queue>

struct Node {
    std::vector<Node *> adj;
    int deg, remain;
    long long s;
    std::priority_queue<long long> q;
};

long long ans = 0;

inline void addEdge(Node *u, Node *v) {
    u->adj.push_back(v);
    u->deg++;
}

void dfs1(Node *u, long long k) {
    if (!u->adj.empty()) {
        int size = u->adj.size();
        ans += k / size * size * u->s;
        for (Node *v : u->adj) dfs1(v, k / size);
        u->remain = k % size;
    } else ans += k * u->s;
}

void dfs2(Node *u) {
    if (u->deg == 0) u->q.push(u->s);
    for (Node *v : u->adj) {
        dfs2(v);
        if (!v->q.empty()) u->q.push(v->q.top() + u->s);
        while (!v->q.empty()) v->q.pop();
    }
    while (u->remain--) {
        ans += u->q.top();
        u->q.pop();
    }
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    std::vector<Node> nodes(n);
    for (int i = 1; i < n; i++) {
        int p;
        scanf("%d", &p);
        addEdge(&nodes[--p], &nodes[i]);
    }
    for (int i = 0; i < n; i++) scanf("%lld", &nodes[i].s);

    ans = 0;
    dfs1(&nodes[0], k);
    dfs2(&nodes[0]);

    printf("%lld\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}