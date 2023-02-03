#include <bits/stdc++.h>

namespace XenonWZH {
    const int MAXN = 5e5;

    struct Node {
        std::vector<struct Edge> e;
        int a;
        bool bar;
        int dfn, low;
        bool vis;
        struct Connected *scc;
    } N[MAXN + 1];

    struct Edge {
        Node *s, *t;

        Edge(Node *s, Node *t) : s(s), t(t) {}
    };

    inline void addEdge(int s, int t) {
        N[s].e.push_back(Edge(&N[s], &N[t]));
    }

    struct Connected {
        int a;
        bool bar;
        Node v;
        long long dis;
        bool vis;
    } sccs[MAXN + 1];

    int tarjan(Node *v) {
        static int ts = 0, counts = 0;
        static std::stack<Node *> stk;
        v->dfn = v->low = ++ts;
        stk.push(v);
        v->vis = true;

        for (Edge *e = &v->e.front(); e && e <= &v->e.back(); e++) {
            if (!e->t->dfn) {
                tarjan(e->t);
                v->low = std::min(v->low, e->t->low);
            } else if (e->t->vis) v->low = std::min(v->low, e->t->dfn);
        }

        if (v->dfn == v->low) {
            counts++;
            Node *u;
            do {
                u = stk.top();
                stk.pop();
                u->vis = false;
                u->scc = &sccs[counts];
                sccs[counts].a -= u->a;
                sccs[counts].bar |= u->bar;
            } while (u != v);
        }

        return counts;
    }

    void contract(int n, int counts) {
        for (int i = 1; i <= n; i++) {
            for (Edge *e = &N[i].e.front(); e && e <= &N[i].e.back(); e++) {
                if (e->s->scc != e->t->scc) {
                    e->s->scc->v.e.push_back(Edge(&e->s->scc->v, &e->t->scc->v));
                }
            }
        }

        for (int i = 1; i <= counts; i++) sccs[i].v.scc = &sccs[i];
    }

    void spfa(Connected *s, int n) {
        for (int i = 1; i <= n; i++) sccs[i].dis = INT_MAX;
        for (int i = 1; i <= n; i++) sccs[i].vis = false;

        std::queue<Connected *> q;
        s->dis = 0, s->vis = true;
        q.push(s);

        while (!q.empty()) {
            Connected *v = q.front();
            q.pop();
            v->vis = false;

            for (Edge *e = &v->v.e.front(); e && e <= &v->v.e.back(); e++) {
                if (e->t->scc->dis > e->s->scc->dis + e->t->scc->a) {
                    e->t->scc->dis = e->s->scc->dis + e->t->scc->a;
                    if (!e->t->scc->vis) {
                        q.push(e->t->scc);
                        e->t->vis = true;
                    }
                }
            }
        }
    }

    int main() {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(u, v);
        }
        for (int i = 1; i <= n; i++) scanf("%d", &N[i].a);

        int s, p;
        scanf("%d %d", &s, &p);
        for (int i = 1; i <= p; i++) {
            int bar;
            scanf("%d", &bar);
            N[bar].bar = true;
        }

        int counts;
        for (int i = 1; i <= n; i++) {
            if (!N[i].dfn) {
                counts = tarjan(&N[i]);
            }
        }
        contract(n, counts);
        spfa(N[s].scc, counts);

        long long ans = 0;
        for (int i = 1; i <= counts; i++) {
            if (sccs[i].bar) {
                ans = std::min(ans, sccs[i].dis);
            }
        }

        printf("%lld\n", -ans - N[s].scc->a);

        return 0;
    }
};

int main() {
    return XenonWZH::main();
}