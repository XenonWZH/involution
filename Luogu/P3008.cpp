#include <cstdio>
#include <climits>
#include <vector>
#include <deque>

const int MAXN = 2.5e4;

struct Node {
    std::vector<struct Edge> e;
    int d;
    bool v;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;
    int w;

    Edge(Node *s, Node *t, int w) : s(s), t(t), w(w) {}
};

int t, r, p, s;

inline void addEdge(int s, int t, int w) {
    N[s].e.push_back(Edge(&N[s], &N[t], w));
    N[t].e.push_back(Edge(&N[t], &N[s], w));
}

inline void addAirline(int s, int t, int w) {
    N[s].e.push_back(Edge(&N[s], &N[t], w));
    N[t].d++;
}

inline void spfa(const int s) {
    for (int i = 1; i <= t; i++) N[i].d = INT_MAX;

    static std::deque<Node *> q;
    N[s].d = 0, N[s].v = true;
    q.push_back(&N[s]);

    while (!q.empty()) {
        Node *u = q.front();
        q.pop_front();
        u->v = false;
        for (Edge *e = &u->e.front(); e && e <= &u->e.back(); e++) {
            if (e->t->d > u->d + e->w) {
                e->t->d = u->d + e->w;
                if (!e->t->v) {
                    if (!q.empty() && e->t->d >= q.front()->d) q.push_back(e->t);
                    else q.push_front(e->t);
                    e->t->v = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &t, &r, &p, &s);
    for (int i = 1; i <= r; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        addEdge(a, b, c);
    }

    for (int i = 1; i <= p; i++) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        addAirline(a, b, d);
    }

    spfa(s);

    for (int i = 1; i <= t; i++) {
        if (N[i].d == INT_MAX)
            puts("NO PATH");
        else
            printf("%d\n", N[i].d);
    }

    return 0;
}