#include <cstdio>
#include <set>

const int MAXN = 2e5;

void solve() {
    int n;
    static int a[MAXN + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    static int f[MAXN + 1], g[MAXN + 1];
    g[1] = f[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] < a[i + 1]) f[i] = f[i + 1] + 1;
        else f[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] < a[i]) g[i] = g[i - 1] + 1;
        else g[i] = 1;
    }

    int ans = 1;
    static std::set< std::pair<int, int> > s;
    s.clear();
    s.insert(std::make_pair(a[1], g[1]));
    for (int i = 2; i <= n; i++) {
        std::set< std::pair<int, int> >::iterator it = s.lower_bound(std::make_pair(a[i], 0));
        bool flag = true;

        if (it != s.begin()) {
            it--;
            ans = std::max(ans, (*it).second + f[i]);
            if (g[i] <= (*it).second) flag = false;
        }

        if (flag) {
            std::set< std::pair<int, int> >::iterator p = it;
            p++;
            while (p != s.end() && (*p).first > a[i] && (*p).second < g[i]) {
                it = p;
                p++;
                s.erase(it);
            }
            s.insert(std::make_pair(a[i], g[i]));
        }
    }

    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}