#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

const int MAXN = 1000;
const int INF = 1000001;

struct Node {
    std::vector<struct Edge> e;
    int d;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;
    int w;

    Edge(Node *s, Node *t, int w) : s(s), t(t), w(w) {}
};

inline void addEdge(int s, int t, int w) {
    N[s].e.push_back(Edge(&N[s], &N[t], w));
    N[t].e.push_back(Edge(&N[t], &N[s], w));
}

int n, p, k;

bool check(int limit) {
    std::deque<Node *> q;
    for (int i = 1; i <= n; i++) N[i].d = INT_MAX;
    q.push_front(&N[1]);
    N[1].d = 0;

    while (!q.empty()) {
        Node *v = q.front();
        q.pop_front();

        for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
            if (e->t->d > e->s->d + (e->w > limit)) {
                e->t->d = e->s->d + (e->w > limit);
                if (e->w > limit) q.push_back(e->t);
                else q.push_front(e->t);
            }
        }
    }

    return N[n].d <= k;
}

int main() {
    scanf("%d %d %d", &n, &p, &k);
    for (int i = 1; i <= p; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int l = 0, r = INF;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l == INF ? -1 : l);

    return 0;
}