#include <cstring>
#include <iostream>

const int MAXN = 100, MAXM = 10;

int n, m;
char board[MAXN + 1][MAXM + 1];
int f[MAXN + 1][30 * MAXM + 1][30 * MAXM + 1];
int s[100 * MAXM + 1], len = 0;

void getSet() {
    s[0] = 0;

    for (int i = 0; i < (1 << m); i++) {
        if (i & (i << 1)) continue;
        if (i & (i << 2)) continue;
        s[++len] = i;
    }
}

inline int count(int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if ((s[x] >> i) & 1) {
            cnt++;
        }
    }
    return cnt;
}

inline bool check(int pos, int now) {
    for (int i = 0; i < m; i++) {
        if ((board[pos][i + 1] == 'H') && ((s[now] >> i) & 1)) {
            return false;
        }
    }
    return true;
}

inline void init() {
    getSet();

    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = 0;

    for (int i = 0; i <= len; i++) {
        if (check(1, i)) {
            f[1][i][0] = count(i);
        }
    }
}

inline void dp() {
    init();

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= len; j++) {
            if (check(i, j)) {
                for (int k = 0; k <= len; k++) {
                    if (check(i - 1, k) && (s[j] & s[k]) == 0) {
                        for (int l = 0; l <= len; l++) {
                            if (check(i - 2, l) && (s[j] & s[l]) == 0) {
                                f[i][j][k] = std::max(f[i][j][k], f[i - 1][k][l] + count(j));
                            }
                        }
                    }
                }
            }
        }
    }
}

inline int getAns() {
    int ans = 0;
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            ans = std::max(ans, f[n][i][j]);
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> board[i][j];
        }
    }

    dp();

    std::cout << getAns() << std::endl;

    return 0;
}