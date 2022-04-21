#include <cstdio>
#include <iostream>
#include <vector>

const int MAXN = 10000;

std::vector<int> son[MAXN + 1];
int f[MAXN + 1][2], v[MAXN + 1], h[MAXN + 1], n;

void dp(int x) {
    f[x][0] = 0;
    f[x][1] = h[x];

    for (int y : son[x]) {
        dp(y);
        f[x][0] += std::max(f[y][0], f[y][1]);
        f[x][1] += f[y][0];
    }
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x] = 1;
        son[y].push_back(x);
    }

    int root;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            root = i;
            break;
        }
    }

    dp(root);

    std::cout << std::max(f[root][0], f[root][1]) << std::endl;

    return 0;
}