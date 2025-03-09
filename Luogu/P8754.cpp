#include <bits/stdc++.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n <= 1) {
        printf("%lld\n", n);
        return 0;
    }

    long long ans = 1, t = n;
    for (int i = 2; i <= std::min((long long)sqrt(n), t); i++) {
        if (t % i == 0) {
            int cnt = 0;
            while (t % i == 0) t /= i, cnt++;
            if (cnt & 1) ans *= i;
        }
    }

    printf("%lld\n", ans * t);

    return 0;
}