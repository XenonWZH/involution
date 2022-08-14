#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
#include <queue>

const int MAXN = 10;
const int MAXM = 100;

struct Node {
    std::vector<struct Edge> e;
    int d;
    bool v;
} N[1 << MAXN];

struct Edge {
    Node *s, *t;

    Edge(Node *s, Node *t) : s(s), t(t) {}
};

int n, m;

inline void addEdge(int s, int t) {
    N[s].e.push_back(Edge(&N[s], &N[t]));
}

inline int bfs(const int s, const int t) {
    std::queue<Node *> q;
    q.push(&N[s]);
    N[s].d = 0;
    N[s].v = true;

    while (!q.empty()) {
        Node *p = q.front();
        q.pop();

        for (Edge &e : p->e) {
            if (!e.t->v) {
                e.t->d = p->d + 1;
                q.push(e.t);
                e.t->v = true;
            }
        }
    }

    return N[t].d;
}

int main() {
    static int a[MAXM][MAXN];

    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < m; j++) {
            std::bitset<MAXN> target = i;
            for (int k = 0; k < n; k++) {
                if (a[j][k] == 1 && target[k]) target[k] = false;
                else if (a[j][k] == -1 && !target[k]) target[k] = true;
            }
            addEdge(i, target.to_ulong());
        }
    }

    int ans = bfs((1 << n) - 1, 0);
    printf("%d\n", N[0].v ? ans : -1);

    return 0;
}