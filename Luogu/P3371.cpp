// P3371 【模板】单源最短路径（弱化版）
// WzhDnwzWzh

#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 10000, MAXM = 500000;

struct Graph {
    int head[MAXN + 10], nxt[MAXM + MAXN + 10], to[MAXM + MAXN + 10], tail;
    unsigned long long va[MAXM + MAXN + 10];

    void init(int n) {
        memset(va, 0x3f, sizeof(va));
        memset(nxt, -1, sizeof(nxt));

        for (int i = 1; i <= n; i++) {
            head[i] = i;
        }
        tail = n + 1;
    }

    void add(int x, int y, int z) {
        int pos = head[x];
        while (nxt[pos] != -1) pos = nxt[pos];
        va[tail] = z;
        to[tail] = y;
        nxt[pos] = tail++;
    }
};

Graph a;
int n, m, s;
unsigned long long d[MAXN + 1];
bool v[MAXN + 1];

void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));

    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        int x = 0;

        for (int j = 1; j <= n; j++) {
            if (!v[j] && (x == 0 || d[j] < d[x])) x = j;
        }
        v[x] = 1;

        int pos = a.head[x];
        while (true) {
            d[a.to[pos]] = std::min(d[a.to[pos]], d[x] + a.va[pos]);
            pos = a.nxt[pos];
            if (pos == -1) break;
        }
    }
}

int main() {
    std::cin >> n >> m >> s;

    a.init(n);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        a.add(x, y, z);
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        std::cout << (d[i] == 4557430888798830399 ? 2147483647 : d[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}
