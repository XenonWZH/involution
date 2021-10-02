// 1 F
// WzhDnwzWzh

#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
    int n;
    static int a[2000], b[2000];

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    static int ans[2000];
    int len = 0;
    for (int i = 0; i < n; i++) {
        int x = a[0] ^ b[i];
        bool con = true;
        static bool mark[2000];
        memset(mark, false, sizeof(mark));
        for (int j = 0; j < n; j++) {
            bool sin = false;
            for (int k = 0; k < n; k++) {
                if ((a[j] ^ b[k]) == x && !mark[k]) {
                    sin = true;
                    mark[k] = true;
                }
            }
            if (!sin) con = false;
        }
        if (con) ans[len++] = x;
    }

    std::cout << len << std::endl;
    for (int i = 0; i < len; i++) std::cout << ans[i] << std::endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}