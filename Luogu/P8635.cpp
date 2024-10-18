#include <cstdio>
#include <cmath>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i * i * 4 <= n; i++) {
        for (int j = i; i * i + j * j * 3 <= n; j++) {
            for (int k = j; i * i + j * j + k * k * 2 <= n; k++) {
                int l = n - i * i - j * j - k * k;
                if ((int)sqrt(l) * (int)sqrt(l) == l) {
                    printf("%d %d %d %d\n", i, j, k, (int)sqrt(l));
                    return 0;
                }
            }
        }
    }

    return 0;
}