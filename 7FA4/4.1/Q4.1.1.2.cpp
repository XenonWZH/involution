#include <cstdio>

const int MAXN = 1000000;

int phi[MAXN + 1];

void euler(int n) {
    for (int i = 2; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j++) {
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

        int ans = 0;
        for (int i = 2; i <= n; i++) ans += phi[i];

        printf("%d\n", 3 + 2 * ans);
    }

    return 0;
}