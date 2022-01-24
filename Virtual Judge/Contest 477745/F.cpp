#include <cstdio>

const int MAXN = 20;

bool isPrime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    for (int i = 2; i * i<= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    int n, k, ans = 0;
    static int x[20];

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);

    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                cnt++;
        if (cnt != k) continue;

        int sum = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                sum += x[j];
        if (isPrime(sum)) ans++;
    }

    printf("%d\n", ans);

    return 0;
}