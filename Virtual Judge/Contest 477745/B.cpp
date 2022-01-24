#include <cstdio>
#include <cstring>

const int MAXN = 40;

bool board[MAXN + 2][MAXN + 2], mark[MAXN + 2][MAXN + 2];
int ans = MAXN * MAXN + 1, r, c;

void dfs(int x, int y, int step) {
    if (x == r && y == c && step < ans) {
        ans = step;
        return;
    }
    mark[x][y] = false;
    if (board[x + 1][y] && mark[x + 1][y]) dfs(x + 1, y, step + 1);
    if (board[x - 1][y] && mark[x - 1][y]) dfs(x - 1, y, step + 1);
    if (board[x][y + 1] && mark[x][y + 1]) dfs(x, y + 1, step + 1);
    if (board[x][y - 1] && mark[x][y - 1]) dfs(x, y - 1, step + 1);
    mark[x][y] = true;
}

int main() {
    memset(board, false, sizeof(board));
    memset(mark, true, sizeof(mark));

    scanf("%d%d", &r, &c);
    getchar();
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char c = getchar();
            if (c == '.') board[i][j] = true;
        }
        getchar();
    }

    dfs(1, 1, 1);

    printf("%d\n", ans);

    return 0;
}