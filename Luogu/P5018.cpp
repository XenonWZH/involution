#include <cstdio>
#include <iostream>

const int MAXN = 1000000;

int n, v[MAXN + 1];
int f[MAXN + 1][2], cnt[MAXN + 1];

bool isSym(int x, int y) {
    if (x == y && y == -1) return true;
    else if (x == -1 || y == -1) return false;
    else if (v[x] == v[y] && isSym(f[x][1], f[y][0]) && isSym(f[x][0], f[y][1])) return true;
    else return false;
}

void dfs(int fa) {
    cnt[fa] = 1;
    if (f[fa][0] != -1) {
        dfs(f[fa][0]);
        cnt[fa] += cnt[f[fa][0]];
    }
    if (f[fa][1] != -1) {
        dfs(f[fa][1]);
        cnt[fa] += cnt[f[fa][1]];
    }
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) scanf("%d%d", &f[i][0], &f[i][1]);

    dfs(1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isSym(f[i][0], f[i][1])) {
            ans = std::max(ans, cnt[i]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}