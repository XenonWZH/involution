#include <cstdio>
#include <stack>

const int MAXN = 1000000;

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
} connecteds[2 * MAXN];

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
        int i, a, j, b;
        scanf("%d %d %d %d", &i, &a, &j, &b);
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

    if (flag) {
        puts("POSSIBLE");
        for (int i = 1; i <= n; i++) {
            printf("%d ", (int)(N[i].connected->id < N[i + n].connected->id));
        }
        putchar('\n');
    } else puts("IMPOSSIBLE");

    return 0;
}