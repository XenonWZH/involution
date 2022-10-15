#include <cstdio>
#include <vector>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++) if (a[i] == 0) cnt++;

    int ans = 0;
    for (int i = 0; i < cnt; i++) if (a[i]) ans++;

    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}