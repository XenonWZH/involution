#include <cstdio>
#include <cctype>
#include <vector>
#include <stack>

const int MAXN = 100000;

struct Node {
    std::vector<struct Edge> e;
    int dfn, low, deg;
    bool v;
    struct Connected *connected;
} N[2 * MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

struct Connected {
    int size, id;
} connecteds[2 * MAXN];

int counts = 0;

inline void addEdge(int s, int t) {
    N[t].deg++;
    N[s].e.push_back(Edge(&N[s], &N[t]));
}

int tarjan(Node *x) {
    static int num = 0;
    static std::stack<Node *> stk;
    x->dfn = x->low = ++num;
    stk.push(x);
    x->v = true;

    for (Edge *e = &x->e.front(); e && e <= &x->e.back(); e++) {
        if (!e->t->dfn) {
            tarjan(e->t);
            x->low = std::min(x->low, e->t->low);
        } else if (e->t->v) {
            x->low = std::min(x->low, e->t->dfn);
        }
    }

    if (x->dfn == x->low) {
        counts++;
        connecteds[counts].id = counts;
        Node *y;
        do {
            y = stk.top();
            stk.pop();
            y->v = false;
            y->connected = &connecteds[counts];
            connecteds[counts].size++;
        } while (x != y);
    }

    return counts;
}

int dfs(Node *u) {
    int mx = 0;
    for (Edge *e = &u->e.front(); e && e <= &u->e.back(); e++) {
        int x = dfs(e->t);
        mx = std::max(mx, x);
    }
    return mx + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        addEdge(x, i);

        if (x == i) ans++;
    }

    for (int i = 1; i <= 2 * n; i++) if (!N[i].dfn) tarjan(&N[i]);

    for (int i = 0; i <= counts; i++) if (connecteds[i].size > 1) ans += connecteds[i].size;
    for (int i = n + 1; i <= 2 * n; i++) {
        if (N[i].deg == 0) {
            ans += dfs(&N[i]) - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
