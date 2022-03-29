#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

typedef long long ll;

const int MAXN = 150000 + 10;
const int MAXM = 300 + 10;

ll f[2][MAXN];
ll a[MAXM], b[MAXM], t[MAXM];
int n, m, d;

int q[MAXN];

int fl = 1;

void init() {
    memset(f, 0x3f, sizeof(f));
    memset(q, 0, sizeof(q));
    for (int i = 1; i <= n; i++) f[0][i] = 0;
    fl = 1;
}

void dp() {
    init();

    for (int i = 1; i <= m; i++) {
      int l = 1, r = 0, k = 1;
      for (int j = 1; j <= n; j++) {
            for (; k <= std::min(1ll * n, j + d * (t[i] - t[i - 1])); k++) {
                while (l <= r && f[fl ^ 1][q[r]] <= f[fl ^ 1][k]) r--;
                q[++r] = k;
            }

            while (l <= r && q[l] < std::max(1ll, j - d * (t[i] - t[i - 1]))) l++;
            f[fl][j] = f[fl ^ 1][q[l]] - abs(a[i] - j) + b[i];
      }

      fl ^= 1;
    }
}

int main() {
    std::cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) scanf("%lld%lld%lld", &a[i], &b[i], &t[i]);

    dp();

    ll ans = -1e18;
    for (int i = 1; i <= n; i++) ans = std::max(ans, f[fl ^ 1][i]);
    std::cout << ans << std::endl;

    return 0;
}