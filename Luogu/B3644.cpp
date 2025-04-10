#include <bits/stdc++.h>

struct Node {
    std::vector<Node *> adj;
    int id, d;
};

void addEdge(Node *u, Node *v) {
    u->adj.push_back(v);
    v->d++;
}

int main() {
    int n;
    scanf("%d", &n);

    std::vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) nodes[i].id = i;

    for (int i = 1; i <= n; i++) {
        int v;
        while (scanf("%d", &v) != EOF && v != 0) addEdge(&nodes[i], &nodes[v]);
    }

    std::queue<Node *> q;
    for (int i = 1; i <= n; i++) if (nodes[i].d == 0) q.push(&nodes[i]);

    while (!q.empty()) {
        Node *u = q.front();
        q.pop();
        printf("%d ", u->id);

        for (Node *v : u->adj) {
            v->d--;
            if (v->d == 0) q.push(v);
        }
    }

    puts("");

    return 0;
}