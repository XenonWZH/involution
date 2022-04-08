#include <cmath>
#include <cstring>
#include <iostream>

typedef long long ll;
const int MAXN = 50000, INF = 0x3f3f3f3f;

ll n, ans = INF;
int pri[MAXN], top = 0, vis[MAXN];

void getPri() {
    memset(vis, 0, sizeof(vis));

    for (int i = 2; i < MAXN; i++) {
        if (vis[i] == 0) {
            pri[++top] = i;
            vis[i] = i;
        }

        for (int j = 1; j <= top && pri[j] * i < MAXN; j++) {
            if (pri[j] > vis[i])
                break;
            vis[i * pri[j]] = pri[j];
        }
    }
}

bool check(int x) {
    for (int i = 1; pri[i] * pri[i] <= x && i <= top; i++) {
        if (x % pri[i] == 0)
            return false;
    }
    return true;
}

void dfs(int p, int num, ll x) {
    if (num == 1) {
        ans = std::min(ans, x);
        return;
    }
    if (num > sqrt(n) && check(num + 1)) {
        ans = std::min(ans, x * (num + 1));
        return;
    }

    for (int i = p; i <= top && pri[i] - 1 <= num; i++) {
        if (num % (pri[i] - 1) == 0) {
            int tmp = num / (pri[i] - 1);
            ll xx = x * pri[i];
            dfs(p + 1, tmp, xx);
            while (tmp % pri[i] == 0) {
                tmp /= pri[i];
                xx *= pri[i];
                dfs(p + 1, tmp, xx);
            }
        }
    }
}

int main() {
    std::cin >> n;

    getPri();
    dfs(1, n, 1);

    if (ans == INF) std::cout << "-1" << std::endl;
    else std::cout << ans << std::endl;

    return 0;
}