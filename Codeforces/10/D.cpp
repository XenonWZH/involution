#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

const int MAXN = 500;

int main() {
    int n, m;
    static int a[MAXN + 1], b[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);

    int f[MAXN + 1][MAXN + 1];
    int pre[MAXN + 1][MAXN + 1];
    memset(f, 0, sizeof(f));
    memset(pre, -1, sizeof(pre));

    for (int i = 1; i <= n; i++) {
        int val = 0, p = 0;
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (a[i] > b[j] && val < f[i - 1][j]) {
                val = f[i - 1][j];
                p = j;
            } else if (a[i] == b[j]) {
                f[i][j] = std::max(f[i][j], val + 1);
                pre[i][j] = p;
            }
        }
    }

    int pos = 1;
    for (int i = 2; i <= m; i++) {
        if (f[n][i] > f[n][pos]) {
            pos = i;
        }
    }

    printf("%d\n", f[n][pos]);
    if (f[n][pos] > 0) {
        static std::stack<int> ans;
        for (int i = n; i >= 1; i--) {
            if (pre[i][pos] != -1) {
                ans.push(a[i]);
                pos = pre[i][pos];
            }
        }
        while (!ans.empty()) {
            printf("%d ", ans.top());
            ans.pop();
        }
    }
    putchar('\n');

    return 0;
}