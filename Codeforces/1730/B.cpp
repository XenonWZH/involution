#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 1e5;

struct People {
    int x, t, p;

    const bool operator<(const People &other) const {
        return x < other.x;
    }
} a[MAXN + 1];

void solve() {
    int n, maxp = 1;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].t);
        if (a[maxp].t < a[i].t) maxp = i;
    }

    for (int i = 1; i <= n; i++) {
        if (std::abs(a[i].x - a[maxp].x) <= std::abs(a[i].t - a[maxp].t)) a[i].x = a[maxp].x;
        else {
            if (a[i].x < a[maxp].x) a[i].x += a[maxp].t - a[i].t;
            else a[i].x -= a[maxp].t - a[i].t;
        }
    }

    int min = 1e8 + 1, max = 0;
    for (int i = 1; i <= n; i++) {
        min = std::min(min, a[i].x);
        max = std::max(max, a[i].x);
    }

    printf("%.7f\n", (max + min) * 1.0 / 2);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}