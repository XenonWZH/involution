#include <bits/stdc++.h>

const int MAXN = 1000;

int n;
char res[MAXN + 1][MAXN + 2], up[MAXN + 1][MAXN + 2];
int vis[MAXN + 1][MAXN + 2];
int bef, aft;
bool vism[MAXN + 1], visp[MAXN + 1][MAXN + 2];

void calcBef(int x, int y, int marked) {
    if (vis[x][y] >= 0) return;
    vis[x][y] = 0;
    if (res[x][y] == '.') return;
    if (!marked) marked = ++bef;
    vis[x][y] = marked;

    if (x > 1) calcBef(x - 1, y, marked);
    if (x < n) calcBef(x + 1, y, marked);
    if (y > 1) calcBef(x, y - 1, marked);
    if (y < n) calcBef(x, y + 1, marked);
}

void calcAft(int x, int y) {
    if (visp[x][y]) return;
    visp[x][y] = true;
    if (up[x][y] == '.') return;
    vism[vis[x][y]] = true;

    if (x > 1) calcAft(x - 1, y);
    if (x < n) calcAft(x + 1, y);
    if (y > 1) calcAft(x, y - 1);
    if (y < n) calcAft(x, y + 1);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%s", res[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (res[i][j] == '.') up[i][j] = '.';
            else {
                up[i][j] = '#';
                if (i > 1 && res[i - 1][j] == '.') up[i][j] = '.';
                if (i < n && res[i + 1][j] == '.') up[i][j] = '.';
                if (j > 1 && res[i][j - 1] == '.') up[i][j] = '.';
                if (j < n && res[i][j + 1] == '.') up[i][j] = '.';
            }
        }
    }

    
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            calcBef(i, j, 0);
        }
    }

    memset(visp, false, sizeof(visp));
    memset(vism, false, sizeof(vism));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            calcAft(i, j);
        }
    }

    for (int i = 1; i <= bef; i++) aft += vism[i];
    printf("%d\n", bef - aft);

    return 0;
}