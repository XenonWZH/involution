#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

const int MAXN = 500;

struct Node {
    int id;
    std::vector<struct Edge> adj;
    int deg;
    double p;
};

struct Edge {
    Node *s, *t;
    double p;

    Edge() {}
    Edge(Node *s, Node *t) : s(s), t(t) {}

    bool operator<(const Edge &other) {
        return p > other.p;
    }
};

inline void addEdge(Node *u, Node *v) {
    u->adj.push_back(Edge(u, v));
    v->adj.push_back(Edge(v, u));
    u->deg++, v->deg++;
}

void gauses(std::vector<std::array<double, MAXN + 2>> &matrix, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n + 1; j++) matrix[i][j] /= matrix[i][i];
        matrix[i][i] = 1;
        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k <= n + 1; k++) {
                matrix[j][k] -= matrix[i][k] * matrix[j][i] / matrix[i][i];
            }
            matrix[j][i] = 0;
        }
    }

    for (int i = n; i > 1; i--) {
        for (int j = 1; j < i; j++) {
            matrix[j][n + 1] -= matrix[i][n + 1] * matrix[j][i] / matrix[i][i];
            matrix[j][i] = 0;
        }
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    std::vector<Node> nodes(n + 1);
    std::vector<Edge> edges(m);
    for (int i = 1; i <= n; i++) nodes[i].id = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&nodes[u], &nodes[v]);
        edges[i] = Edge(&nodes[u], &nodes[v]);
    }

    std::vector<std::array<double, MAXN + 2>> matrix(MAXN + 1);
    for (int i = 1; i < n; i++) {
        Node *u = &nodes[i];
        matrix[i][i] = 1, matrix[i][n + 1] = 0;
        for (Edge &e : u->adj) {
            if (e.t->id != n) {
                matrix[i][e.t->id] = -1.0 / e.t->deg;
            }
        }
    }
    matrix[1][n + 1] = matrix[n][n] = 1;

    gauses(matrix, n);
    for (int i = 1; i <= n; i++) nodes[i].p = matrix[i][n + 1];

    for (Edge &e : edges) {
        Node *u = e.s, *v = e.t;
        e.p = u->p / u->deg + v->p / v->deg;
    }
    std::sort(edges.begin(), edges.end());

    double ans = 0;
    for (int i = 0; i < m; i++) ans += edges[i].p * (i + 1);
    printf("%.3f\n", ans);

    return 0;
}