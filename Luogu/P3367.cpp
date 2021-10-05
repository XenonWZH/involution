// P3367 【模板】并查集
// WzhDnwzWzh

#include <iostream>

int fa[10001];

void make_set(int size) {
    for (int i = 0; i < size; i++) fa[i] = i;
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

int main() {
    int n, m, t, x, y;

    std::cin >> n >> m;
    make_set(n);
    for (int i = 0; i < m; i++) {
        std::cin >> t >> x >> y;

        if (t == 1) union_set(x, y);
        if (t == 2) std::cout << ((find(x) == find(y)) ? "Y" : "N") << std::endl;
    }

    return 0;
}