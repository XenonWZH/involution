// C - 跳石头
// XenonWZH

#include <iostream>

int l, n, m;
int d[50000];

int check(int mid) {
    int ans = 0, pos = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] - pos < mid) ans++;
        else pos = d[i];
    }

    return ans <= m;
}

int main() {
    std::cin >> l >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    int left = 0, right = l, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (check(mid)) left = mid + 1;
        else right = mid - 1;
    }

    if (!check(left)) left--;
    std::cout << left << std::endl;
    return 0;
}