#include <cstdio>
#include <stack>

const int MAXN = 10000;

struct Node {
    struct Edge *edges;
    int dfn, low;
    bool visited;
    struct Connected *connected;
} N[MAXN + 1];

struct Edge {
    Node *from, *to;
    Edge *next;

    Edge(Node *from, Node *to) : from(from), to(to), next(from->edges) {}
};

struct Connected {
    int size;
} connecteds[MAXN + 1];

int n, m;

inline void addEdge(int from, int to) {
    N[from].edges = new Edge(&N[from], &N[to]);
}

int tarjan(Node *x) {
    static int num = 0, counts = 0;
    static std::stack<Node *> stk;
    x->dfn = x->low = ++num;
    stk.push(x);
    x->visited = true;

    for (Edge *edges = x->edges; edges; edges = edges->next) {
        if (!edges->to->dfn) {
            tarjan(edges->to);
            x->low = std::min(x->low, edges->to->low);
        } else if (edges->to->visited) {
            x->low = std::min(x->low, edges->to->dfn);
        }
    }

    if (x->dfn == x->low) {
        counts++;
        Node *y;
        do {
            y = stk.top();
            stk.pop();
            y->visited = false;
            y->connected = &connecteds[counts];
            connecteds[counts].size++;
        } while (x != y);
    }

    return counts;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }

    int counts;
    for (int i = 1; i <= n; i++) {
        if (!N[i].dfn) {
            counts = tarjan(&N[i]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= counts; i++) {
        if (connecteds[i].size > 1) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}