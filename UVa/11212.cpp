#include <cstdio>
#include <cstring>

const int MAXN = 9;

int n;
int a[MAXN];

bool check() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            return false;
        }
    }
    return true;
}

int calc() {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + 1 != a[i + 1]) {
            cnt++;
        }
    }
    if (a[n - 1] != n) cnt++;
    return cnt;
}

bool dfs(int cur, int depth) {
    if (cur * 3 + calc() > depth * 3) return false;
    if (check()) return true;

    int b[MAXN], olda[MAXN];
    memcpy(olda, a, sizeof(a));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (k < i || k > j) {
                    b[cnt++] = a[k];
                }
            }

            for (int k = 0; k <= cnt; k++) {
                int cnt2 = 0;
                for (int p = 0; p < k; p++) a[cnt2++] = b[p];
                for (int p = i; p <= j; p++) a[cnt2++] = olda[p];
                for (int p = k; p < cnt; p++) a[cnt2++] = b[p];

                if (dfs(cur + 1, depth)) return true;
                memcpy(a, olda, sizeof(a));
            }
        }
    }

    return false;
}

void solve() {
    static int counts = 0;

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    if (check()) {
        printf("Case %d: 0\n", ++counts);
        return;
    }

    int maxAns = 5;
    for (int depth = 1; depth < maxAns; depth++) {
        if (dfs(0, depth)) {
            printf("Case %d: %d\n", ++counts, depth);
            return;
        }
    }

    printf("Case %d: %d\n", ++counts, maxAns);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        solve();
    }

    return 0;
}