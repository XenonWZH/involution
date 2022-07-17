#include <cstdio>

int x, y;
long long ans = 0;

// type = 0 为蓝，type = 1 为红
void solve(int type, int n, long long cnt) {
    if (n == 1 && type == 0) ans += cnt;
    if (n >= 2) {
        if (type == 1) {
            solve(1, n - 1, cnt);
            solve(0, n, cnt * x);
        } else {
            solve(1, n - 1, cnt);
            solve(0, n - 1, cnt * y);
        }
    }
}

int main() {
    int n;

    scanf("%d %d %d", &n, &x, &y);

    solve(1, n, 1);

    printf("%lld\n", ans);

    return 0;
}