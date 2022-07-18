#include <cstdio>
#include <cstring>

const int MAXN = 20;

long long ans[MAXN + 1][2];

inline long long fact(int x) {
    long long ans = 1;
    for (int i = 1; i <= x; i++) ans *= i;
    return ans;
}

long long solve(int x, int is) {
    if (ans[x][is] != -1) return ans[x][is];

    ans[x][is] = is ? fact(x - 1) : solve(x - 1, 1);
    ans[x][is] += (x - 1) * solve(x - 1, 0);

    return ans[x][is];
}

int main() {
    int n;

    scanf("%d", &n);

    memset(ans, -1, sizeof(ans));
    ans[1][1] = 1;
    ans[1][0] = 0;

    printf("%lld\n", fact(n) - solve(n, 1));

    return 0;
}