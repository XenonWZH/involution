#include <cstdio>
#include <vector>

void solve() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 20; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) cnt += ((a[j] >> i) & 1);
        if (cnt == 1) {
            puts("1");
            return;
        } else if (cnt & 1) {
            puts(((n - cnt) & 1) ? "-1" : "1");
            return;
        }
    }

    puts("0");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) solve();

    return 0;
}