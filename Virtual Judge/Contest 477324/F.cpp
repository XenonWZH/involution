#include <iostream>
#include <algorithm>

int fa[1001];

struct Node {
    int x, y, t;
} way[100000];

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

void make_set(int size) {
    for (int i = 1; i <= size; i++) fa[i] = i;
    return;
}

int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

bool cmp(Node a, Node b) {
    return a.t < b.t;
}

int main() {
    int n, m;
    long long ans = 0;

    n = read();
    m = read();
    make_set(n);

    for (int i = 0; i < m; i++) {
        way[i].x = read();
        way[i].y = read();
        way[i].t = read();
    }

    std::sort(way, way + m, cmp);

    for (int i = 0; i < m; i++) {
        union_set(way[i].x, way[i].y);
        bool con = true;
        for (int j = 2; j <= n; j++) {
            if (fa[j] != fa[1]) con = false;
        }
        if (con) {
            std::cout << way[i].t << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}