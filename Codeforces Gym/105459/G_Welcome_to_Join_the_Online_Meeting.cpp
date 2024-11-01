#include <bits/stdc++.h>

namespace XenonWZH {
    struct Node {
        std::vector<Node *> adj;
        Node *fa = nullptr;
        int dfn, low, id;
        bool v, dir;
        struct Connected *connected;
        std::vector<Node *> ans;
    };

    struct Connected {
        int size, id;
    };

    int n;
    std::vector<Node *> ans;

    void addEdge(Node *u, Node *v) {
        u->adj.push_back(v);
        v->fa = u;
    }

    int tarjan(Node *u, std::vector<Connected> &connecteds) {
        static int num = 0, counts = 0;
        static std::stack<Node *> stk;
        u->dfn = u->low = ++num;
        stk.push(u);
        u->v = true;

        for (Node *v : u->adj) {
            if (!v->dfn) {
                tarjan(v, connecteds);
                u->low = std::min(u->low, v->low);
            } else if (v->v) {
                u->low = std::min(u->low, v->dfn);
            }
        }

        if (u->dfn == u->low) {
            counts++;
            connecteds.push_back({0, 0});
            connecteds[counts].id = counts;
            Node *y;
            do {
                y = stk.top();
                stk.pop();
                y->v = false;
                y->connected = &connecteds[counts];
                connecteds[counts].size++;
            } while (u != y);
        }

        return counts;
    }

    void dfs(Node *u) {
        u->v = true;
        for (Node *v : u->adj) {
            if (v->v || v->dir) continue;
            u->ans.push_back(v);
            dfs(v);
        }
        if (u->ans.size()) ans.push_back(u);
    }

    void solve() {
        int m, k;
        scanf("%d %d %d", &n, &m, &k);

        std::vector<Node> G(n + 1);
        for (int i = 1; i <= n; i++) G[i].id = i;

        std::vector<Connected> connecteds(1);
        for (int i = 1; i <= k; i++) {
            int x;
            scanf("%d", &x);
            G[x].dir = true;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (!G[u].dir) addEdge(&G[u], &G[v]);
            if (!G[v].dir) addEdge(&G[v], &G[u]);
        }

        int counts = 0;
        for (int i = 1; i <= n; i++) if (!G[i].dfn) counts = tarjan(&G[i], connecteds);

        if (counts != k + 1) {
            puts("No");
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (G[i].dir && G[i].fa == nullptr) {
                puts("No");
                return;
            }
        }

        puts("Yes");
        for (int i = 1; i <= n; i++) G[i].v = false;

        for (int i = 1; i <= n; i++) if (G[i].dir) G[i].fa->ans.push_back(&G[i]);
        for (int i = 1; i <= n; i++) if (!G[i].v && !G[i].dir) dfs(&G[i]);

        printf("%zu\n", ans.size());
        for (auto it = ans.rbegin(); it != ans.rend(); it++) {
            auto u = (*it);
            printf("%d %zu ", u->id, u->ans.size());
            for (auto v : u->ans) printf("%d ", v->id);
            puts("");
        }
    }

    int main() {
        int t = 1;

        while (t--) solve();

        return 0;
    }
};

int main() {
    return XenonWZH::main();
}