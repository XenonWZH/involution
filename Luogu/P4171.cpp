#include <cstdio>
#include <cctype>
#include <vector>
#include <stack>

const int MAXN = 1000;

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
} connecteds[2 * MAXN];

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

void prepare(int n) {
    for (int i = 1; i <= 2 * MAXN; i++) {
        N[i].e.clear();
        N[i].dfn = N[i].low = 0;
        N[i].v = false;
        N[i].connected = NULL;
    }
    for (int i = 0; i < 2 * MAXN; i++) {
        connecteds[i].size = connecteds[i].id = 0;
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        prepare(n);

        while (m--) {
            int i, j;
            char a = ' ', b = ' ';
            while (isspace(a)) a = getchar();
            scanf("%d", &i);
            while (isspace(b)) b = getchar();
            scanf("%d", &j);
            a = a == 'h' ? 1 : 0;
            b = b == 'h' ? 1 : 0;
            if (a && b) {
                addEdge(i + n, j);
                addEdge(j + n, i);
            } else if(!a && b) {
                addEdge(i, j);
                addEdge(j + n, i + n);
            } else if (a && !b) {
                addEdge(i + n, j + n);
                addEdge(j, i);
            } else if (!a && !b) {
                addEdge(i, j + n);
                addEdge(j, i + n);
            }
        }

        for (int i = 1; i <= 2 * n; i++) {
            if (!N[i].dfn) {
                tarjan(&N[i]);
            }
        }

        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (N[i].connected == N[n + i].connected) {
                flag = false;
                break;
            }
        }

        if (flag) puts("GOOD");
        else puts("BAD");
    }

    return 0;
}