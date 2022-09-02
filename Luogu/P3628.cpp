#include <cstdio>
#include <iostream>

const int MAXN = 1000000;

int n, a, b, c, q[MAXN + 1];
long long s[MAXN + 1], f[MAXN + 1];

double calc(int x, int y) {
    return (f[y] - f[x] + a * s[y] * s[y] - a * s[x] * s[x] - b * s[y] + b * s[x]) * 1.0 / (2 * a * (s[y] - s[x]));
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }

    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        while (l < r && calc(q[l], q[l + 1]) < s[i]) l++;
        f[i] = f[q[l]] + a * (s[i] - s[q[l]]) * (s[i] - s[q[l]]) + b * (s[i] - s[q[l]]) + c;
        while (l < r && calc(q[r - 1], q[r]) > calc(q[r], i)) r--;
        q[++r] = i;
    }

    printf("%lld\n", f[n]);

    return 0;
}
