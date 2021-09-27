// 998. 起床困难综合症
// WzhDnwzWzh

#include <iostream>

int n, m;
std::pair<std::string, int> a[100005];

int calc(int bit, int now) {
    for (int i = 0; i < n; i++) {
        int x = a[i].second >> bit & 1;
        if (a[i].first == "AND") now &= x;
        else if (a[i].first == "OR") now |= x;
        else if (a[i].first == "XOR") now ^= x;
    }
    return now;
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::string str; int x;
        std::cin >> str >> x;
        a[i] = std::make_pair(str, x);
    }

    int val = 0, ans = 0;
    for (int i = 29; i >= 0; i--) {
        int res0 = calc(i, 0), res1 = calc(i, 1);
        if (val + (1 << i) <= m && res0 < res1) {
            val += 1 << i;
            ans += res1 << i;
        } else ans += res0 << i;
    }

    std::cout << ans << std::endl;
    return 0;
}