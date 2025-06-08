#include <bits/stdc++.h>

namespace XenonWZH {
typedef long long ll;

const int MAXN = 1e5;
const int MOD = 1e9 + 7;

struct Node {
    std::vector<Node *> adj;
    int dep;

    Node() : dep(0) {}
};

void addEdge(Node *u, Node *v) {
    u->adj.push_back(v);
    v->adj.push_back(u);
}

ll pow(ll a, ll b) {
    if (b <= 0) return 1;
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
    return ans;
}

std::vector<Node *> leaves;

void dfs1(Node *u, Node *fa = nullptr) {
    u->dep = (fa ? fa->dep + 1 : 1);
    bool end = true;
    int cnt = 0;
    for (Node *v : u->adj) {
        if (v == fa) continue;
        end = false;
        dfs1(v, u);
    }
    if (end) leaves.push_back(u);
}

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
    }

    leaves.clear();
    dfs1(&nodes[1]);

    if (leaves.size() == 1) printf("%lld\n", pow(2, n));
    else if (leaves.size() == 2) {
        Node *r = nullptr;
        for (int i = 1; i <= n; i++) if (nodes[i].adj.size() == 3) r = &nodes[i];
        if (r == nullptr) r = &nodes[1];

        ll ans = pow(2, r->dep);
        int delta = std::max(leaves[0]->dep - r->dep, leaves[1]->dep - r->dep) - std::min(leaves[0]->dep - r->dep, leaves[1]->dep - r->dep);

        ans = ans * ((pow(2, delta) + pow(2, delta - 1)) % MOD) % MOD;
        printf("%lld\n", ans);
    } else puts("0");
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