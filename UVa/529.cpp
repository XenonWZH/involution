#include <cstdio>
#include <vector>

const int MAXN = 10005;

int n;
int ans[MAXN];

bool dfs(int depth, int limit) {
    if (depth == limit) return ans[depth] == n;
    if (depth > 1 && ans[depth - 1] * ((long long)1 << (limit - depth + 1)) < n) return false;
    std::vector<bool> vis(MAXN);

    for (int i = depth; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            int num = ans[i] + ans[j];
            if (num <= n && num > ans[depth] && !vis[num]) {
                ans[depth + 1] = num;
                if (dfs(depth + 1, limit)) return true;
                else vis[num] = 1;
            }
        }
    }

    return false;
}

int main() {
    ans[1] = 1;

    while (scanf("%d", &n) != EOF && n) {
        int limit = 1;
        while (!dfs(1, limit)) limit++;

        for (int i = 1; i <= limit; i++) printf("%d%c", ans[i], i == limit ? '\n' : ' ');
    }

    return 0;
}