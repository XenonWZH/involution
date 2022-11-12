#include <cstdio>
#include <vector>
#include <map>
#include <stack>

const int MAXN = 1e5;
 
struct Node {
    std::vector<struct Edge> e;
    int dfn, low;
    bool visited;
    struct Connected *connected;
};
 
struct Edge {
    Node *s, *t;
 
    Edge(Node *s, Node *t) : s(s), t(t) {}
};
 
struct Connected {
    int id;
} connecteds[2 * MAXN + 1];
 
inline void addEdge(Node *s, Node *t) {
    s->e.push_back(Edge(s, t));
}
 
void tarjan(Node *u) {
    static int num = 0, cnt = 0;
    static std::stack<Node *> stk;
    u->dfn = u->low = ++num;
    stk.push(u);
    u->visited = true;

    for (Edge &e : u->e) {
        if (!e.t->dfn) {
            tarjan(e.t);
            u->low = std::min(u->low, e.t->low);
        } else if (e.t->visited) {
            u->low = std::min(u->low, e.t->dfn);
        }
    }

    if (u->dfn == u->low) {
        cnt++;
        connecteds[cnt].id = cnt;
        Node *v;
        do {
            v = stk.top();
            stk.pop();
            v->visited = false;
            v->connected = &connecteds[cnt];
        } while (u != v);
    }
}
 
int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
 
    std::vector<int> p(n + 1);
    std::map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        mp[p[i]] = i;
    }
 
    std::vector<Node> nodes(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        if (!mp[a - p[i]] && !mp[b - p[i]]) {
            puts("NO");
            return 0;
        } else if (mp[a - p[i]] && !mp[b - p[i]]) {
            addEdge(&nodes[i + n], &nodes[i]);
            addEdge(&nodes[mp[a - p[i]] + n], &nodes[mp[a - p[i]]]);
        } else if (!mp[a - p[i]] && mp[b - p[i]]) {
            addEdge(&nodes[i], &nodes[i + n]);
            addEdge(&nodes[mp[b - p[i]]], &nodes[mp[b - p[i]] + n]);
        } else {
            addEdge(&nodes[i], &nodes[mp[a - p[i]]]);
            addEdge(&nodes[i], &nodes[mp[b - p[i]]]);
            addEdge(&nodes[i + n], &nodes[mp[a - p[i]] + n]);
            addEdge(&nodes[i + n], &nodes[mp[b - p[i]] + n]);
        }
    }
 
    for (int i = 1; i <= 2 * n; i++) {
        if (!nodes[i].dfn) {
            tarjan(&nodes[i]);
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (nodes[i].connected == nodes[i + n].connected) {
            puts("NO");
            return 0;
        }
    }
 
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", nodes[i].connected->id > nodes[i + n].connected->id);
    putchar('\n');
 
    return 0;
}