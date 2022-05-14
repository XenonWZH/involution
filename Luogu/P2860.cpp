#include <cstdio>
#include <algorithm>

const int MAXN = 5000;
const int MAXM = 10000;

struct Node {
    struct Edge *firstEdge, *inEdge;
    int dfn, low, deg;
    bool vis;
    Node *fa;
} N[MAXN + 1];

struct Edge {
    Node *from, *to;
    bool isCut;
    Edge *next, *revEdge;

    Edge(Node *from, Node *to)
        : from(from), to(to), isCut(false), next(from->firstEdge) {}
} * E[MAXM + 1];

inline Edge *addEdge(int from, int to) {
    N[from].firstEdge = new Edge(&N[from], &N[to]);
    N[to].firstEdge = new Edge(&N[to], &N[from]);

    N[from].firstEdge->revEdge = N[to].firstEdge;
    N[to].firstEdge->revEdge = N[from].firstEdge;

    return N[from].firstEdge;
}

int n, cnt;

inline void tarjan(Node *v) {
    static int ts;
    v->dfn = v->low = ++ts;
    v->vis = true;

    for (Edge *e = v->firstEdge; e; e = e->next) {
        if (e->revEdge == v->inEdge) continue;

        if (!e->to->vis) {
            e->to->fa = v;
            e->to->inEdge = e;
            tarjan(e->to);

            v->low = std::min(v->low, e->to->low);

            if (e->to->low > v->dfn) {
                e->isCut = e->revEdge->isCut = true;
            }
        } else {
            v->low = std::min(v->low, e->to->dfn);
        }
    }
}

struct UFS {
    int fa[MAXN + 1];

    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }

    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

    void merge(int x, int y) { fa[find(x)] = find(y); }
} ufs;

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        E[i] = addEdge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!N[i].vis) {
            tarjan(&N[i]);
        }
    }

    ufs.init(n);

    for (int i = 1; i <= m; i++) {
        if (!E[i]->isCut) ufs.merge(E[i]->from - N, E[i]->to - N);
    }

    for (int i = 1; i <= m; i++) {
        if (E[i]->isCut) {
            N[ufs.find(E[i]->from - N)].deg++;
            N[ufs.find(E[i]->to - N)].deg++;
        }
    }

    int leaves = 0;
    for (int i = 1; i <= n; i++) {
        if (ufs.find(i) == i) {
            if (N[i].deg == 1) {
                leaves++;
            }
        }
    }

    printf("%d\n", (leaves + 1) / 2);

    return 0;
}