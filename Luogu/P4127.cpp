#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int MAXN = 20;

inline long long solve(long long k) {
    int n = 0;
    std::vector<int> bit = { 0 };
    for (; k; k /= 10, n++) bit.push_back(k % 10);
    std::reverse(bit.begin() + 1, bit.end());

    static long long f[MAXN][9 * MAXN][9 * MAXN][2];
    long long ans = 0;

    for (int sum = 1; sum <= n * 9; sum++) {
        memset(f, 0, sizeof(f));
        f[0][0][0][1] = 1;

        for (int i = 0; i < n; i++) {
            for (int s = 0; s <= sum; s++) {
                for (int m = 0; m < sum; m++) {
                    for (int c = 0; c <= 1; c++) {
                        long long res = f[i][s][m][c];
                        if (res) {
                            for (int k = 0; k <= (c ? bit[i + 1] : 9); k++) {
                                if (s + k > sum) break;
                                f[i + 1][s + k][(m * 10 + k) % sum][c & (k == bit[i + 1])] += res;
                            }
                        }
                    }
                }
            }
        }

        ans += f[n][sum][0][0] + f[n][sum][0][1];
    }

    return ans;
}

int main() {
    long long l, r;

    scanf("%lld %lld", &l, &r);

    printf("%lld\n", solve(r) - solve(l - 1));

    return 0;
}