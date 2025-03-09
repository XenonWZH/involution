#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int MAXN = 6, MAXM = 100, MAXK = 20;

typedef long long ll;

int n, m, horse;
ll f[1 << MAXN][1 << MAXN][MAXM + 1][MAXK + 1];

int main() {
    scanf("%d %d %d", &n, &m, &horse);

    memset(f, 0, sizeof(f));
    f[0][0][0][0] = 1;
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < (1 << n); j++) {
                for (int l = 0; l <= horse; l++) {
                    if (f[i][j][k][l] == 0) continue;

                    for (int p = 0; p < (1 << n); p++) {
                        int cnt = 0;
                        for (int q = 0; q < n; q++) if ((p >> q) & 1) cnt++;
                        if (l + cnt > horse) continue;

                        bool vaild = true;
                        for (int q = 0; q < n; q++) {
                            if ((p >> q) & 1) {
                                if (q >= 1 && ((j >> (q - 1)) & 1)) vaild = false;
                                if (q >= 2 && ((i >> (q - 2)) & 1)) vaild = false;
                                if (q < n - 1 && ((j >> (q + 1)) & 1)) vaild = false;
                                if (q < n - 2 && ((i >> (q + 2)) & 1)) vaild = false;
                            }
                            if (!vaild) break;
                        }

                        if (vaild) f[p][i][k + 1][l + cnt] = (f[p][i][k + 1][l + cnt] + f[i][j][k][l]) % MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1 << n); i++) for (int j = 0; j < (1 << n); j++) ans = (ans + f[i][j][m][horse]) % MOD;
    printf("%lld\n", ans);

    return 0;
}