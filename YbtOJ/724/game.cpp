#include <cstdio>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    std::vector<long long> row(n + 1, 1), col(m + 1, 1);
    while (k--) {
        char op[5];
        long long x, y;
        scanf("%s %lld %lld", op, &x, &y);
        if (op[0] == 'R') row[x] = row[x] * y % MOD;
        else if (op[0] == 'S') col[x] = col[x] * y % MOD;
    }

    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) sum = (sum + (i - 1) * row[i] % MOD) % MOD;
    for (int i = 1; i <= m; i++) ans = (ans + m * col[i] % MOD * sum % MOD) % MOD;

    sum = 0;
    for (int i = 1; i <= m; i++) sum = (sum + i * col[i] % MOD) % MOD;
    for (int i = 1; i <= n; i++) ans = (ans + row[i] * sum % MOD) % MOD;

    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}