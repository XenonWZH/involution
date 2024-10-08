#include <bits/stdc++.h>

typedef long long ll;

const int MAXN = 100000;
const int MOD = 998244353;
const int MC = 63;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;
    s = ' ' + s;

    auto cha = [](char x) -> int {
        if (x >= 'A' && x <= 'Z') return x - 'A' + 1;
        else if (x >= '0' && x <= '9') return 'Z' - 'A' + 1 + x - '0' + 1;
        else return 'Z' - 'A' + 1 + '9' - '0' + 1 + x - 'a' + 1;
    };

    // f[末尾字符][大写][数字][小写] 滚动数组
    static ll f[MC][2][2][2], g[MC][2][2][2];
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    f[0][0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            for (int j = 0; j < MC; j++) {
                if (cha(s[i]) == j) continue;
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        g[cha(s[i])][1][k][l] = ((g[cha(s[i])][1][k][l] + f[j][0][k][l]) % MOD + f[j][1][k][l]) % MOD;
                    }
                }
            }
        } else if (s[i] >= '0' && s[i] <= '9') {
            for (int j = 0; j < MC; j++) {
                if (cha(s[i]) == j) continue;
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        g[cha(s[i])][k][1][l] = ((g[cha(s[i])][k][1][l] + f[j][k][0][l]) % MOD + f[j][k][1][l]) % MOD;
                    }
                }
            }
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            for (int j = 0; j < MC; j++) {
                if (cha(s[i]) == j) continue;
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        g[cha(s[i])][k][l][1] = ((g[cha(s[i])][k][l][1] + f[j][k][l][0]) % MOD + f[j][k][l][1]) % MOD;
                    }
                }
            }
            char ss = s[i] - 'a' + 'A';
            for (int j = 0; j < MC; j++) {
                if (cha(ss) == j) continue;
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        g[cha(ss)][1][k][l] = ((g[cha(ss)][1][k][l] + f[j][0][k][l]) % MOD + f[j][1][k][l]) % MOD;
                    }
                }
            }
        } else {
            ll sum[2][2][2];
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        sum[j][k][l] = 0;
                    }
                }
            }
            for (int j = 0; j < MC; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            sum[k][l][m] = (sum[k][l][m] + f[j][k][l][m]) % MOD;
                        }
                    }
                }
            }
            for (int j = 1; j < MC; j++) {
                ll summ[2][2][2];
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            summ[k][l][m] = (sum[k][l][m] + MOD - f[j][k][l][m]) % MOD;
                        }
                    }
                }
                if (j >= cha('A') && j <= cha('Z')) {
                    g[j][1][0][0] = ((g[j][1][0][0] + summ[0][0][0]) % MOD + summ[1][0][0]) % MOD;
                    g[j][1][0][1] = ((g[j][1][0][1] + summ[0][0][1]) % MOD + summ[1][0][1]) % MOD;
                    g[j][1][1][0] = ((g[j][1][1][0] + summ[0][1][0]) % MOD + summ[1][1][0]) % MOD;
                    g[j][1][1][1] = ((g[j][1][1][1] + summ[0][1][1]) % MOD + summ[1][1][1]) % MOD;
                } else if (j >= cha('0') && j <= cha('9')) {
                    g[j][0][1][0] = ((g[j][0][1][0] + summ[0][0][0]) % MOD + summ[0][1][0]) % MOD;
                    g[j][0][1][1] = ((g[j][0][1][1] + summ[0][0][1]) % MOD + summ[0][1][1]) % MOD;
                    g[j][1][1][0] = ((g[j][1][1][0] + summ[1][0][0]) % MOD + summ[1][1][0]) % MOD;
                    g[j][1][1][1] = ((g[j][1][1][1] + summ[1][0][1]) % MOD + summ[1][1][1]) % MOD;
                } else {
                    g[j][0][0][1] = ((g[j][0][0][1] + summ[0][0][0]) % MOD + summ[0][0][1]) % MOD;
                    g[j][0][1][1] = ((g[j][0][1][1] + summ[0][1][0]) % MOD + summ[0][1][1]) % MOD;
                    g[j][1][0][1] = ((g[j][1][0][1] + summ[1][0][0]) % MOD + summ[1][0][1]) % MOD;
                    g[j][1][1][1] = ((g[j][1][1][1] + summ[1][1][0]) % MOD + summ[1][1][1]) % MOD;
                }
            }
        }
        for (int j = 0; j < MC; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    for (int m = 0; m < 2; m++) {
                        f[j][k][l][m] = g[j][k][l][m];
                        g[j][k][l][m] = 0;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i < MC; i++) ans = (ans + f[i][1][1][1]) % MOD;
    std::cout << ans << "\n";

    return 0;
}