#include <cstring>
#include <iostream>

const int MAXN = 9;

int n, k;
long long f[MAXN + 1][MAXN * MAXN + 1][1 << MAXN];

inline int counts(int x) {
    int ans = 0;
    for (int i = 0; (1 << i) <= x; i++) {
        if ((x >> i) & 1) {
            ans++;
        }
    }
    return ans;
}

inline void init() {
    memset(f, 0, sizeof(f));

    for (int i = 0; i < (1 << n); i++) {
        bool con = true;
        for (int each = 1; each < n - 1; each++) {
            if (((i >> each) & 1) && (((i >> (each - 1)) & 1) || ((i >> (each + 1)) & 1))) {
                con = false;
                break;
            }
        }

        int cnt = counts(i);
        if (con && cnt <= k) f[1][cnt][i] = 1;
    }
}

inline void dp() {
    init();

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            bool con = true;
            for (int each = 1; each < n - 1; each++) {
                if (((j >> each) & 1) & (((j >> (each - 1)) & 1) || ((j >> (each + 1)) & 1))) {
                    con = false;
                    break;
                }
            }

            int cntJ = counts(j);
            if (con && cntJ <= k) {
                for (int l = 0; l < (1 << n); l++) {
                    con = true;
                    if ((j & 1) && ((l & 1) || ((l >> 1) & 1))) continue;
                    if (((j >> (n - 1)) & 1) && (((l >> (n - 1)) & 1) || ((l >> (n - 2)) & 1))) continue;
                    for (int each = 1; each < n - 1; each++) {
                        if (((j >> each) & 1) && (((l >> each) & 1) || ((l >> (each - 1)) & 1) || ((l >> (each + 1)) & 1))) {
                            con = false;
                            break;
                        }
                    }

                    int cntL = counts(l);
                    if (con && cntJ + cntL <= k) {
                        for (int m = cntL; m <= k - cntJ; m++) {
                            f[i][m + cntJ][j] += f[i - 1][m][l];
                        }
                    }
                }
            }
        }
    }
}

inline long long getAns() {
    long long ans = 0;

    for (int i = 0; i < (1 << n); i++) {
        ans += f[n][k][i];
    }

    return ans;
}

int main() {

    std::cin >> n >> k;

    dp();

    std::cout << getAns() << std::endl;
    return 0;
}