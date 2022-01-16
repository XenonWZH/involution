// P1182 数列分段 Section II
// XenonWZH

#include <iostream>

const int MAXN = 100000, MAXA = 10000;

int main() {
    int n, m;
    static long long a[MAXN];

    std::cin >> n >> m;

    int l = 1, r = MAXN * MAXA;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] > l) l = a[i];
    }

    while (l < r) {
        int mid = (l + r) >> 1;

        int cnt = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > mid) {
                sum = a[i];
                cnt++;
            }
        }

        if (cnt <= m) r = mid;
        if (cnt > m) l = mid + 1;
    }

    std::cout << l << std::endl;

    return 0;
}