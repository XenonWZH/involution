#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int MAXN = 10000;
const int MAXM = 1500;
const int P0 = 131;
const int P1 = 13331;

int val(char c) {
    if (c >= '0' && c <= '9') return c - '0' + 1;
    else if (c >= 'A' && c <= 'Z') return c - 'A' + 11;
    else return c - 'a' + 37;
}

std::pair<unsigned long long, unsigned long long> calc(char *str, int len) {
    unsigned long long v0 = 0, v1 = 0;
    unsigned long long p0 = 1, p1 = 1;
    for (int i = 0; i < len; i++) {
        v0 += p0 * val(str[i]);
        v1 += p1 * val(str[i]);
        p0 *= P0;
        p1 *= P1;
    }
    return std::make_pair(v0, v1);
}

int main() {
    int n;
    static char str[MAXN][MAXM + 1];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", str[i]);

    static std::pair<unsigned long long, unsigned long long> a[MAXN];
    for (int i = 0; i < n; i++) a[i] = calc(str[i], strlen(str[i]));
    std::sort(a, a + n);

    printf("%ld\n", std::unique(a, a + n) - a);

    return 0;
}