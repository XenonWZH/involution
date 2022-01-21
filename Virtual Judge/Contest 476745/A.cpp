#include <cstdio>
#include <cmath>

typedef unsigned long long ull;

int main() {
    ull n, m;

    while (scanf("%llu%llu", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;

        ull left = n, right = n, depth = 1;

        while (left * 2 <= m) {
            left *= 2;
            right = right * 2 + 1;
            depth++;
        }

        printf("%llu\n", (1 << depth) - 1 - (right > m ? (right - m) : 0));
    }

    return 0;
}