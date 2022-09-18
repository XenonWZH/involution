#include <cstdio>
#include <vector>
#include <stack>

const int MAXN = 80000;

struct Node {
    std::vector<struct Edge> e;
    int dfn, low;
    bool v;
    struct Connected *connected;
} N[2 * MAXN + 1];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

struct Connected {
    int size, id;
} connecteds[2 * MAXN + 1];

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
}

void tarjan(Node *x) {
    static int num = 0, counts = 0;
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
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b % 2 ? b + 1 : b - 1);
        addEdge(b, a % 2 ? a + 1 : a - 1);
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (!N[i].dfn) {
            tarjan(&N[i]);
        }
    }

    for (int i = 1; i <= 2 * n; i += 2) {
        if (N[i].connected == N[i + 1].connected) {
            puts("NIE");
            return 0;
        }
    }

    for (int i = 1; i <= 2 * n; i += 2) {
        printf("%d\n", N[i].connected->id < N[i + 1].connected->id ? i : i + 1);
    }

    return 0;
}