#include <bits/stdc++.h>

const int MAXN = 360;

int main() {
    int n;

    std::cin >> n;

    static std::set<int> cuts;
    int deg = 0;
    for (int i = 0, a; i < n; i++) {
        std::cin >> a;
        deg += a;
        if (deg >= 360) deg -= 360;
        cuts.insert(deg);
    }

    int first = 0, ans = 0;
    for (int each : cuts) {
        if (each - first > ans) ans = each - first;
        first = each;
    }
    if (360 - first > ans) ans = 360 - first;

    std::cout << ans << std::endl;

    return 0;
}