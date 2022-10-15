#include <cstdio>
#include <vector>

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += a[i];

    if (cnt == 0 || k > n) puts("NO");
    else puts("YES");
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}