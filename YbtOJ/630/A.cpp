#include <cstdio>
#include <cstring>
#include <iostream>

const int MAXN = 100;

char s[MAXN + 1];
int f[MAXN + 1][MAXN + 1];
bool visited[MAXN + 1][MAXN + 1];

bool judge(int l, int r, int cl, int cr) {
    if ((r - l + 1) % (cr - cl + 1) != 0) return false;
    for (int i = l; i <= r; i++) {
        if (s[i] != s[(i - l) % (cr - cl + 1) + cl]) {
            return false;
        }
    }
    return true;
}

int length(int x) {
    int t = 0;
    while (x) {
        x /= 10;
        t++;
    }
    return t;
}

int dp(int l, int r) {
    if (l == r) return 1;
    if (visited[l][r]) return f[l][r];
    visited[l][r] = true;

    int t = r - l + 1;
    for (int i = l; i < r; i++) {
        t = std::min(t, dp(l, i) + dp(i + 1, r));
        if (judge(i + 1, r, l, i)) {
            t = std::min(t, dp(l, i) + 2 + length((r - i) / (i - l + 1) + 1));
        }
    }
    return f[l][r] = t;
}

int main() {
    scanf("%s", s);
    printf("%d", dp(0, strlen(s) - 1));
    return 0;
}