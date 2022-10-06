#include <cstdio>
#include <iostream>
#include <algorithm>

const int MAXN = 1e5;

struct Student {
    long long f, t, a, b, c, d;

    bool operator<(const Student &other) const {
        return t < other.t;
    }
} S[MAXN + 1];

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &S[i].f);
    for (int i = 1; i <= n; i++) scanf("%lld", &S[i].t);
    for (int i = 1; i <= n; i++) scanf("%lld %lld %lld %lld", &S[i].a, &S[i].b, &S[i].c, &S[i].d);

    std::sort(S + 1, S + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (S[i].a >= S[j].t && S[i].b <= S[j].t &&
                S[j].c >= S[i].t && S[j].d <= S[i].t) {
                S[j].f += S[i].f;
            }
        }
    }

    for (int i = 1; i <= n; i++) printf("%lld ", S[i].f);
    putchar('\n');

    return 0;
}