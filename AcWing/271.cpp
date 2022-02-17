#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 30;

int main() {
    int k;

    while (std::cin >> k) {
        if (k == 0) break;

        int n[6];
        memset(n, 0, sizeof(n));
        for (int i = 1; i <= k; i++) std::cin >> n[i];

        static long long f[MAXN + 1][MAXN + 1][MAXN + 1][MAXN + 1][MAXN + 1];
        memset(f, 0, sizeof(f));
        f[0][0][0][0][0] = 1;

        for (int i1 = 0; i1 <= n[1]; i1++) {
            for (int i2 = 0; i2 <= n[2]; i2++) {
                for (int i3 = 0; i3 <= n[3]; i3++) {
                    for (int i4 = 0; i4 <= n[4]; i4++) {
                        for (int i5 = 0; i5 <= n[5]; i5++) {
                            if (i1 < n[1]) f[i1 + 1][i2][i3][i4][i5] += f[i1][i2][i3][i4][i5];
                            if (i2 < n[2] && i2 < i1) f[i1][i2 + 1][i3][i4][i5] += f[i1][i2][i3][i4][i5];
                            if (i3 < n[3] && i3 < i2) f[i1][i2][i3 + 1][i4][i5] += f[i1][i2][i3][i4][i5];
                            if (i4 < n[4] && i4 < i3) f[i1][i2][i3][i4 + 1][i5] += f[i1][i2][i3][i4][i5];
                            if (i5 < n[5] && i5 < i4) f[i1][i2][i3][i4][i5 + 1] += f[i1][i2][i3][i4][i5];
                        }
                    }
                }
            }
        }

        std::cout << f[ n[1] ][ n[2] ][ n[3] ][ n[4] ][ n[5] ] << std::endl;
    }

    return 0;
}