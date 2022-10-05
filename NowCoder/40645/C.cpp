#include <cstdio>
#include <iostream>

void solve() {
    int n, m, a, b, c;

    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);

    int ans = 0;
    for (int i = 0; i <= std::min(n, m / c); i++) {
        int res = 1;
        if (i == 0) res = (n - 1) / a + (m - 1) / b + 2;
        else {
            res++;
            res += (i - 1) * 2;
            if (n - i >= 1) {
                res++;
                int x = n - i - 1;
                res += x / a;
            }

            if (c > b) {
                res += (c - 1) / b * i;
            }

            if (m - c * i >= 1) {
                res++;

                int x = m - i * c - 1;
                int mod = (((c - 1) / b + 1) * b) - (c - 1);
                if (x / mod >= i)
                    res += i, x -= mod * i;
                else {
                    res += x / mod;
                    x -= x / mod * mod;
                }
                res += x / b;
            }
        }

        ans = std::max(ans, res);
    }
    
    printf("%d\n", ans);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}