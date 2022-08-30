#include <cstdio>
#include <cstring>

const int MAXN = 50;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m;
        static char str[MAXN + 10][MAXN + 10];
        static bool s[MAXN + 10][MAXN + 10];
        memset(s, false, sizeof(s));

        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str[i][j] == '*') s[i][j] = true;
                else s[i][j] = false;
            }
        }

        bool flag = true;

        for (int i = 1; i <= n - 1; i++) {
            if (!flag) break;
            for (int j = 1; j <= m - 1; j++) {
                int cnt = 0;
                for (int k = 0; k <= 1; k++) {
                    for (int l = 0; l <= 1; l++) {
                        if (s[i + k][j + l]) {
                            cnt++;
                        }
                    }
                }

                if (cnt == 3) {
                    if (!s[i][j]) {
                        if (s[i - 1][j] |
                            s[i - 1][j + 1] |
                            s[i - 1][j + 2] |
                            s[i][j - 1] |
                            s[i][j + 2] |
                            s[i + 1][j - 1] |
                            s[i + 1][j + 2] |
                            s[i + 2][j - 1] |
                            s[i + 2][j] |
                            s[i + 2][j + 1] |
                            s[i + 2][j + 2]) {
                                flag = false;
                        }
                    } else if (!s[i + 1][j]) {
                        if (s[i - 1][j - 1] |
                            s[i - 1][j] |
                            s[i - 1][j + 1] |
                            s[i - 1][j + 2] |
                            s[i][j - 1] |
                            s[i][j + 2] |
                            s[i + 1][j - 1] |
                            s[i + 1][j + 2] |
                            s[i + 2][j] |
                            s[i + 2][j + 1] |
                            s[i + 2][j + 2]) {
                                flag = false;
                        }
                    } else if (!s[i][j + 1]){
                        if (s[i - 1][j - 1] |
                            s[i - 1][j] |
                            s[i - 1][j + 1] |
                            s[i][j - 1] |
                            s[i][j + 2] |
                            s[i + 1][j - 1] |
                            s[i + 1][j + 2] |
                            s[i + 2][j - 1] |
                            s[i + 2][j] |
                            s[i + 2][j + 1] |
                            s[i + 2][j + 2]) {
                                flag = false;
                        }
                    } else if (!s[i + 1][j + 1]) {
                        if (s[i - 1][j - 1] |
                            s[i - 1][j] |
                            s[i - 1][j + 1] |
                            s[i - 1][j + 2] |
                            s[i][j - 1] |
                            s[i][j + 2] |
                            s[i + 1][j - 1] |
                            s[i + 1][j + 2] |
                            s[i + 2][j - 1] |
                            s[i + 2][j] |
                            s[i + 2][j + 1]) {
                                flag = false;
                        }
                    }

                    if (flag) s[i][j] = s[i + 1][j] = s[i][j + 1] = s[i + 1][j + 1] = false;
                    else break;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                flag &= (!s[i][j]);
            }
        }

        if (flag) puts("YES");
        else puts("NO");
    }

    return 0;
}