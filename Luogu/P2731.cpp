#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

struct Node {
    std::vector<struct Edge *> e;
    int id, deg;
};

struct Edge {
    Node *s, *t;
    Edge *rev;
    bool v;

    Edge(Node *s, Node *t) : s(s), t(t), v(false) {}
};

inline void addEdge(Node *u, Node *v) {
    u->e.push_back(new Edge(u, v));
    v->e.push_back(new Edge(v, u));
    u->e.back()->rev = v->e[v->e.size() - 1];
    v->e.back()->rev = u->e[u->e.size() - 1];
    u->deg++, v->deg++;
}

std::stack<Node *> ans;

void dfs(Node *v) {
    for (Edge *&e : v->e) {
        if (!e->v) {
            e->v = e->rev->v = true;
            dfs(e->t);
            ans.push(e->t);
        }
    }
}

int main() {
    int m;
    scanf("%d", &m);

    std::vector<Node> nodes(501);
    for (int i = 1; i <= 500; i++) nodes[i].id = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
    }
    for (int i = 1; i <= 500; i++) std::sort(nodes[i].e.begin(), nodes[i].e.end(), [](Edge *a, Edge *b){ return a->t->id < b->t->id; });

    bool flag = true;
    for (int i = 1; i <= 500; i++) {
        if (nodes[i].deg & 1){
            flag = false;
            dfs(&nodes[i]);
            printf("%d\n", i);
            break;
        }
    }

    if (flag) {
        for (int i = 1; i <= 500; i++) {
            if (!nodes[i].e.empty()){
                flag = false;
                dfs(&nodes[i]);
                printf("%d\n", i);
                break;
            }
        }
    }

    while (!ans.empty()) {
        printf("%d\n", ans.top()->id);
        ans.pop();
    }

    return 0;
}