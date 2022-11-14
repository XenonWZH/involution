#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 200;

int w, h;
int sg[MAXN + 1][MAXN + 1];

int SG(int x, int y) {
    if (sg[x][y] != -1) return sg[x][y];

    std::vector<bool> f(std::max(w, h) + 1, false);
    for (int i = 2; i <= x - i; i++) f[SG(i, y) ^ SG(x - i, y)] = 1;
    for (int i = 2; i <= y- i; i++) f[SG(x, i) ^ SG(x, y - i)] = 1;

    int t = 0;
    while (f[t]) t++;
    sg[x][y] = t;

    return sg[x][y];
}

void prepare() {
    memset(sg, -1, sizeof(sg));
    sg[2][2] = sg[2][3] = sg[3][2] = 0;
}

int main() {
    prepare();

    while (scanf("%d %d", &w, &h) != EOF) {
        puts(SG(w, h) ? "WIN" : "LOSE");
    }

    return 0;
}