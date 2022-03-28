#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 1000;

int main() {
    int n, m;
    static int will[MAXN + 1];
    memset(will, 0, sizeof(will));

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1, x; j <= n; j++) {
            scanf("%d", &x);
            if (x == 1) will[j]++;
        }
    }

    int cnt = 0;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        if ((x == 1 && will[i] > m - will[i]) || (x == 0 && will[i] < m - will[i])) cnt++;
    }

    std::cout << cnt << std::endl;

    return 0;
}