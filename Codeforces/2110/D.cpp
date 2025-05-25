#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 998244353;

struct Node {
    std::vector<struct Edge> e;
    ll b, val;
    int d, nd;
};

struct Edge {
    Node *s, *t;
    ll w;

    Edge(Node *s, Node *t, ll w) : s(s), t(t), w(w) {}
};

void addEdge(Node *u, Node *v, ll w) {
    u->e.emplace_back(u, v, w);
    v->d++;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &nodes[i].b);
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        addEdge(&nodes[u], &nodes[v], w);
    }

    auto calc = [&](ll mid) -> bool {
        for (int i = 1; i <= n; i++) nodes[i].val = -1, nodes[i].nd = nodes[i].d;

        nodes[1].val = std::min(mid, nodes[1].b);

        for (int i = 1; i <= n; i++) {
            if (nodes[i].val == -1) continue;

            for (auto [u, v, w] : nodes[i].e) {
                if (u->val >= w) {
                    v->val = std::max(v->val, std::min(mid, u->val + v->b));
                }
            }
        }

        return nodes[n].val > -1;
    };

    ll l = 0, r = 1e9 + 10;
    while (l < r) {
        int mid = (l + r) / 2;
        if (calc(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld\n", l == 1e9 + 10 ? -1 : l);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}
};

int main() { return XenonWZH::main(); }