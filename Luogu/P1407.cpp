#include <cstdio>
#include <iostream>
#include <stack>
#include <map>

const int MAXN = 4000;

struct Node {
    struct Edge *edges;
    int dfn, low;
    bool visited;
    struct Connected *connected;
} N[2 * MAXN];

struct Edge {
    Node *from, *to;
    Edge *next;

    Edge(Node *from, Node *to) : from(from), to(to), next(from->edges) {}
};

struct Connected {
    int size;
} connecteds[2 * MAXN];


int n, m;
std::string girl[MAXN], boy[MAXN];
std::map<std::string, int> mp;

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
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        std::cin >> girl[i] >> boy[i];
        mp[girl[i]] = 2 * i;
        mp[boy[i]] = 2 * i + 1;
        addEdge(mp[girl[i]], mp[boy[i]]);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        std::string g, b;
        std::cin >> g >> b;
        addEdge(mp[b], mp[g]);
    }

    for (int i = 0; i < 2 * n; i++) {
        if (!N[i].dfn) {
            tarjan(&N[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (N[mp[girl[i]]].connected == N[mp[boy[i]]].connected) puts("Unsafe");
        else puts("Safe");
    }

    return 0;
}