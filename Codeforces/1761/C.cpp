#include <bits/stdc++.h>

namespace XenonWZH {
    struct Node {
        int id;
        std::vector<struct Edge> e;
        bool v;
    };

    struct Edge {
        Node *s, *t;

        Edge(Node *s, Node *t) : s(s), t(t) {}
    };

    inline void addEdge(Node *s, Node *t) {
        s->e.emplace_back(s, t);
    }

    void dfs(Node *u, std::vector<int> &ans) {
        u->v = true;
        ans.push_back(u->id);
        for (auto &[u, v] : u->e) {
            if (!v->v) {
                dfs(v, ans);
            }
        }
    }

    void solve() {
        int n;
        scanf("%d", &n);
        getchar();

        std::vector<Node> nodes(n + 1);
        for (int i = 1; i <= n; i++) nodes[i].id = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int b = getchar() - '0';
                if (b) addEdge(&nodes[j], &nodes[i]);
            }
            getchar();
        }

        for (int i = 1; i <= n; i++) {
            std::vector<int> ans;
            for (int i = 1; i <= n; i++) nodes[i].v = false;
            dfs(&nodes[i], ans);
            printf("%ld ", ans.size());
            for (int each : ans) printf("%d ", each);
            putchar('\n');
        }
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