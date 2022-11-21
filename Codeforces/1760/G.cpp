#include <bits/stdc++.h>

namespace XenonWZH {
    struct Node {
        std::vector<struct Edge> e;
    };

    struct Edge {
        Node *s, *t;
        int w;

        Edge(Node *s, Node *t, int w) : s(s), t(t), w(w) {}
    };

    inline void addEdge(Node *u, Node *v, int w) {
        u->e.emplace_back(u, v, w);
        v->e.emplace_back(v, u, w);
    }

    void dfs(Node *u, int val, Node *in, std::map<int, bool> &mp, Node *fa = nullptr) {
        for (auto &[u, v, w] : u->e) {
            if (v == fa || v == in) continue;
            mp[val ^ w] = true;
            dfs(v, val ^ w, in, mp, u);
        }
    }

    void solve() {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        std::vector<Node> nodes(n + 1);
        for (int i = 1; i <= n - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addEdge(&nodes[u], &nodes[v], w);
        }

        std::map<int, bool> mpS, mpT;
        mpS[0] = 0;
        dfs(&nodes[a], 0, &nodes[b], mpS);
        dfs(&nodes[b], 0, nullptr, mpT);

        for (auto each : mpS) {
            if (mpT[each.first]) {
                puts("YES");
                return;
            }
        }

        puts("NO");
    }

    int main() {
        int t;

        scanf("%d", &t);

        while (t--) solve();

        return 0;
    }
}

int main() {
    return XenonWZH::main();
}