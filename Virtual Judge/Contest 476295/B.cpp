// B - 明明的随机数
// XenonWZH

#include <cstring>
#include <iostream>

const int MAXN = 1000;

int main() {
    int n;
    static bool num[MAXN + 1];
    memset(num, false, sizeof(num));

    std::cin >> n;

    int ans = 0;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;

        if (!num[x]) {
            num[x] = true;
            ans++;
        }
    }

    std::cout << ans << std::endl;
    for (int i = 1; i <= MAXN; i++) {
        if (num[i]) std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}