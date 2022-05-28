#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

const int MAXN = 1000;

int main() {
// #ifndef DBG
//     freopen("fly.in", "r", stdin);
//     freopen("fly.out", "w", stdout);
// #endif

    int n, k;
    static int c[MAXN];

    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
    }

    std::sort(c, c + k, std::greater<int>());

    // static bool vis[MAXN];
    // int ans = 0;
    // memset(vis, false, sizeof(vis));

    // for (int i = 0; i < n; i++) {
    //     if (vis[i]) {
    //         i++;
    //         continue;
    //     }

    //     int pos, maxc = 0;
    //     for (int j = 1; j <= n; j++) {
    //         bool flag = true;
    //         for (int k = 0; i + j * k < n; k++) {
    //             if(vis[i + j * k]) {
    //                 flag = false;
    //                 continue;
    //             }
    //         }
    //         if (flag) {
    //             if (maxc > ceil((n - i) * 1.0 / j - 1) * c[i] * j) break;
    //             maxc = ceil((n - i) * 1.0 / j - 1) * c[i] * j;
    //             pos = j;
    //         }
    //     }

    //     ans += maxc;
    //     if (maxc != 0) for (int j = 0; i + pos * j < n; j++) vis[i + pos * j] = true;
    // }

    int ans = 0;
    n--;

    for (int i = 0; i < k && n > 0; i++) {
        ans += n * c[i];
        n -= 2;
    }

    printf("%d\n", ans);

// #ifndef DBG
//     fclose(stdin);
//     fclose(stdout);
// #endif
    return 0;
}