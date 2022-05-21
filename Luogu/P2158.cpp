#include <cstdio>

const int MAXN = 1000000;

int phi[MAXN + 2];

inline void euler(int n) {
    for (int i = 2; i < n; i++) phi[i] = i;
    for (int i = 2; i < n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main() {
    euler(MAXN + 1);

    int t;

    scanf("%d", &t);

    while (t--) {
        int n;

        scanf("%d", &n);
        n++;

        long long ans = 1;
        for (int i = 2; i < n; i++) ans += 2 * phi[i];

        printf("%lld\n", (n == 1 ? 0 : ans));
    }

    return 0;
}