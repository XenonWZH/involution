#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 50, MAXL = 50;

int n, a[MAXN], len[MAXN];
char word[MAXN][MAXL];
int con[MAXN][MAXN];
int ans;

int check(int i, int j) {
    if (i == j) return 0;
    if (i == n) {
        if (word[i][0] == word[j][0]) {
            ans = 1;
            return 1;
        } else
            return 0;
    }
    if (j == n) return 0;

    for (int c = 1; c < len[j] && c < len[i]; ++c) {
        int pi = len[i] - c, pj = 0;
        bool match = true;
        for (int k = 0; k < c; ++k)
            if (word[i][pi + k] != word[j][pj + k]) {
                match = false;
                break;
            }
        if (match) return c;
    }
    return 0;
}

void dfs(int i, int tot) {
    ans = std::max(tot, ans);
    for (int j = 0; j < n; ++j) {
        if (con[i][j] > 0 && a[j] > 0) {
            --a[j];
            dfs(j, tot + len[j] - con[i][j]);
            ++a[j];
        }
    }
}

int main() {
    scanf("%d", &n);
    n *= 2;
    for (int i = 0; i < n / 2; ++i) a[2 * i] = a[2 * i + 1] = 1;
    for (int i = 0; i < n / 2; ++i) {
        scanf("%s", word[2 * i]);
        strcpy(word[2 * i + 1], word[2 * i]);
        len[2 * i] = len[2 * i + 1] = strlen(word[2 * i]);
    }
    scanf("%s", word[n]);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            con[i][j] = check(i, j);
        }
    }

    dfs(n, ans);
    printf("%d\n", ans);

    return 0;
}