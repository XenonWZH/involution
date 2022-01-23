#include <iostream>

int fa[4000000];

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
    long long ans = 0;

    n = read();
    m = read();
    make_set(n);
    for (int i = 0; i < m; i++) {
        t = read();
        x = read();
        y = read();

        if (t == 0) union_set(x, y);
        if (t == 1) ans = ((ans << 1) + (find(x) == find(y))) % 998244353;
    }

    std::cout << ans << std::endl;

    return 0;
}