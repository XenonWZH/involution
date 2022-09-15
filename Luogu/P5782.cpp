#include <cstdio>
#include <stack>

const int MAXN = 80000;

struct Node {
    struct Edge *edges;
    int dfn, low;
    bool visited;
    struct Connected *connected;
} N[2 * MAXN + 1];

struct Edge {
    Node *from, *to;
    Edge *next;

    Edge(Node *from, Node *to) : from(from), to(to), next(from->edges) {}
};

struct Connected {
    int size, id;
} connecteds[2 * MAXN + 1];

inline void addEdge(int from, int to) {
    N[from].edges = new Edge(&N[from], &N[to]);
}

void tarjan(Node *x) {
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
        connecteds[counts].id = counts;
        Node *y;
        do {
            y = stk.top();
            stk.pop();
            y->visited = false;
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