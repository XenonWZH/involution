#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

struct Node {
    std::vector<struct Edge> e;
    ll d;
    bool v;
};

struct Edge {
    Node *s, *t;
    ll w;

    Edge(Node *s, Node *t, ll w) : s(s), t(t), w(w) {}
};

void addEdge(Node *u, Node *v, int w) { v->e.emplace_back(v, u, w); }

auto calc = [](int x, int op, int i, int j) -> int {
    if (x == 15) return x;
    int a[2][2];
    a[0][0] = (x >> 3) & 1, a[0][1] = (x >> 2) & 1, a[1][0] = (x >> 1) & 1, a[1][1] = x & 1;
    if (op == 0) a[i][j] ^= 1;
    else if (op == 1) a[i][0] ^= 1, a[i][1] ^= 1;
    else if (op == 2) a[0][i] ^= 1, a[1][i] ^= 1;
    else a[0][0] ^= 1, a[0][1] ^= 1, a[1][0] ^= 1, a[1][1] ^= 1;
    int ans = (a[0][0] << 3) + (a[0][1] << 2) + (a[1][0] << 1) + a[1][1];
    return ans;
};

auto calcx = [](int x, int op, int i, int j) -> int {
    int a[2][2];
    a[0][0] = (x >> 3) & 1, a[0][1] = (x >> 2) & 1, a[1][0] = (x >> 1) & 1, a[1][1] = x & 1;
    if (op == 0) a[i][j] ^= 1;
    else if (op == 1) a[i][0] ^= 1, a[i][1] ^= 1;
    else if (op == 2) a[0][i] ^= 1, a[1][i] ^= 1;
    else a[0][0] ^= 1, a[0][1] ^= 1, a[1][0] ^= 1, a[1][1] ^= 1;
    int ans = (a[0][0] << 3) + (a[0][1] << 2) + (a[1][0] << 1) + a[1][1];
    return ans;
};

std::vector<Node> nodes(1 << 16);

void solve(ll a0, ll a1, ll a2, ll a3) {
    int m;
    scanf("%d", &m);

    int s = 0;
    for (int i = 1; i <= m; i++) {
        char str[10];
        scanf("%s", str);
        int t = 0;
        for (int i = 0; i < 2; i++) t = (t << 1) + str[i] - '0';
        scanf("%s", str);
        for (int i = 0; i < 2; i++) t = (t << 1) + str[i] - '0';
        s |= (1 << t);
    }

    ll ans = LLONG_MAX;
    int res[4] = {0, 0, 0, 0};
    for (int j = 0; j < 16; j++) {
        if ((s >> j) & 1) {
            res[0] |= (1 << calcx(j, 0, 0, 0));
            res[1] |= (1 << calcx(j, 0, 0, 1));
            res[2] |= (1 << calcx(j, 0, 1, 0));
            res[3] |= (1 << calcx(j, 0, 1, 1));
        }
    }
    ans = std::min(ans, nodes[res[0]].d + a0);
    ans = std::min(ans, nodes[res[1]].d + a0);
    ans = std::min(ans, nodes[res[2]].d + a0);
    ans = std::min(ans, nodes[res[3]].d + a0);

    res[0] = res[1] = res[2] = res[3] = 0;
    for (int j = 0; j < 16; j++) {
        if ((s >> j) & 1) {
            res[0] |= (1 << calcx(j, 1, 0, 0));
            res[1] |= (1 << calcx(j, 1, 1, 0));
        }
    }
    ans = std::min(ans, nodes[res[0]].d + a1);
    ans = std::min(ans, nodes[res[1]].d + a1);

    res[0] = res[1] = res[2] = res[3] = 0;
    for (int j = 0; j < 16; j++) {
        if ((s >> j) & 1) {
            res[0] |= (1 << calcx(j, 2, 0, 0));
            res[1] |= (1 << calcx(j, 2, 1, 0));
        }
    }
    ans = std::min(ans, nodes[res[0]].d + a2);
    ans = std::min(ans, nodes[res[1]].d + a2);

    res[0] = res[1] = res[2] = res[3] = 0;
    for (int j = 0; j < 16; j++) {
        if ((s >> j) & 1) {
            res[0] |= (1 << calcx(j, 3, 0, 0));
        }
    }
    ans = std::min(ans, nodes[res[0]].d + a3);

    printf("%lld\n", ans);
}

int main() {
    int t;
    ll a0, a1, a2, a3;
    scanf("%d %lld %lld %lld %lld", &t, &a0, &a1, &a2, &a3);

    for (int i = 0; i < (1 << 16); i++) {
        int res[4] = {0, 0, 0, 0};
        for (int j = 0; j < 16; j++) {
            if ((i >> j) & 1) {
                res[0] |= (1 << calc(j, 0, 0, 0));
                res[1] |= (1 << calc(j, 0, 0, 1));
                res[2] |= (1 << calc(j, 0, 1, 0));
                res[3] |= (1 << calc(j, 0, 1, 1));
            }
        }
        addEdge(&nodes[i], &nodes[res[0]], a0);
        addEdge(&nodes[i], &nodes[res[1]], a0);
        addEdge(&nodes[i], &nodes[res[2]], a0);
        addEdge(&nodes[i], &nodes[res[3]], a0);

        res[0] = res[1] = res[2] = res[3] = 0;
        for (int j = 0; j < 16; j++) {
            if ((i >> j) & 1) {
                res[0] |= (1 << calc(j, 1, 0, 0));
                res[1] |= (1 << calc(j, 1, 1, 0));
            }
        }
        addEdge(&nodes[i], &nodes[res[0]], a1);
        addEdge(&nodes[i], &nodes[res[1]], a1);

        res[0] = res[1] = res[2] = res[3] = 0;
        for (int j = 0; j < 16; j++) {
            if ((i >> j) & 1) {
                res[0] |= (1 << calc(j, 2, 0, 0));
                res[1] |= (1 << calc(j, 2, 1, 0));
            }
        }
        addEdge(&nodes[i], &nodes[res[0]], a2);
        addEdge(&nodes[i], &nodes[res[1]], a2);

        res[0] = res[1] = res[2] = res[3] = 0;
        for (int j = 0; j < 16; j++) {
            if ((i >> j) & 1) {
                res[0] |= (1 << calc(j, 3, 0, 0));
            }
        }
        addEdge(&nodes[i], &nodes[res[0]], a3);
    }

    auto dijkstra = [&](int s) {
        for (int i = 0; i < (1 << 16); i++) nodes[i].d = LLONG_MAX, nodes[i].v = false;

        std::priority_queue<std::pair<ll, Node *>, std::vector<std::pair<ll, Node *>>, std::greater<std::pair<int, Node *>>> q;
        q.emplace(0, &nodes[s]);
        nodes[s].d = 0;

        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (u->v) continue;
            u->v = true;

            for (auto &[u, v, w] : u->e) {
                if (v->d > u->d + w) {
                    v->d = u->d + w;
                    q.emplace(v->d, v);
                }
            }
        }
    };

    dijkstra(1 << 15);

    while (t--) solve(a0, a1, a2, a3);

    return 0;
}
};

int main() { return XenonWZH::main(); }