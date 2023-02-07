#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

const int MAXN = 5e5;
const int LOG_MAXN = 19;

int n, k, l, r;
int a[MAXN + 1], s[MAXN + 1];
int f[MAXN + 1][LOG_MAXN + 1];

void prepare() {
    for (int i = 1; i <= n; i++) f[i][0] = i;
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            if (s[f[i][j - 1]] > s[f[i + (1 << (j - 1))][j - 1]]) f[i][j] = f[i][j - 1];
            else f[i][j] = f[i + (1 << (j - 1))][j - 1];
        }
    }
}

int query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    if (s[f[l][k]] > s[f[r - (1 << k) + 1][k]]) return f[l][k];
    else return f[r - (1 << k) + 1][k];
}

struct Node {
    int i, l, r, t;
    Node(int i, int l, int r) : i(i), l(l), r(r), t(query(l, r)) {}
    bool operator<(const Node &o) const { return s[t] - s[i - 1] < s[o.t] - s[o.i - 1]; }
};

int main() {
    scanf("%d %d %d %d", &n, &k, &l, &r);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    prepare();

    std::priority_queue<Node> q;
    for (int i = 1; i <= n - l + 1; i++) q.push(Node(i, i + l - 1, std::min(n, i + r - 1)));

    long long ans = 0;
    while (k--) {
        Node u = q.top();
        q.pop();
        ans += s[u.t] - s[u.i - 1];
        if (u.l <= u.t - 1) q.push(Node(u.i, u.l, u.t - 1));
        if (u.t + 1 <= std::min(n, u.r)) q.push(Node(u.i, u.t + 1, std::min(n, u.r)));
    }

    printf("%lld\n", ans);

    return 0;
}