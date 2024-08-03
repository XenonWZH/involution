#include <bits/stdc++.h>

namespace XenonWZH {
int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    std::sort(a.begin() + 1, a.end());

    long long ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        ans += a[i];
        cnt++;
        if (cnt >= n / 3) break;
    }

    printf("%lld\n", ans);

    return 0;
}
}

int main() {
    return XenonWZH::main();
}