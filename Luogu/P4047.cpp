#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 1000, MAXX = 10000;
const double EPS = 1e-5;


struct Edge {
    int u, v;
    double val;
};

int n, k;
std::pair<int, int> people[MAXN + 1];
Edge e[MAXN * (MAXN - 1) + 1];
int fa[MAXN * (MAXN - 1) + 1];

inline void makeSet(int size) {
    for (int i = 0; i < size; i++) {
        fa[i] = i;
    }
}

int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

inline double dis(std::pair<int, int> a, std::pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

bool cmp(Edge a, Edge b) {
    return a.val < b.val;
}

void kruskal() {
    int tot = 0;
    std::sort(e + 1, e + n * (n - 1) + 1, cmp);
    makeSet(n);

    for (int i = 1; i <= n * (n - 1) + 1; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);
        if (a != b) {
            unionSet(e[i].u, e[i].v);
            tot++;
            if (tot == n - k + 1) {
                printf("%.2f\n", e[i].val);
                return;
            }
        }
    }
}

int main() {
    std::cin >> n >> k;
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y);
        people[i] = std::make_pair(x, y);
    }

    int cnt = 1;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            e[cnt].u = i;
            e[cnt].v = j;
            e[cnt++].val = dis(people[i], people[j]);
        }
    }

    kruskal();

    return 0;
}