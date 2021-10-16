// #3380. 「CSP-S 2020」动物园
// WzhDnwzWzh

#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

typedef unsigned long long ull;

int main() {
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
    ull n, m, c, k;
    static ull animal[1000005];

    std::cin >> n >> m >> c >> k;
    bool animalBIN[70];
    memset(animalBIN, false, sizeof(animalBIN));
    for (ull i = 0; i < n; i++) {
        std::cin >> animal[i];
        for (ull j = 0; (1ull << j) <= animal[i]; j++) {
            if ((animal[i] >> j) & 1)
                animalBIN[j] = true;
        }
    }

    ull ans = (1ull << k) - n;
    ull cnt = 0;
    for (ull i = 0, x, y; i < m; i++) {
        std::cin >> x >> y;
        if (!animalBIN[x]) {
            cnt++;
            ans -= 1ull << (k - cnt);
            animalBIN[x] = true;
        }
    }

    if (k == 64 && n == 0)
        std::cout << "18446744073709551616" << std::endl;
    else std::cout << ans << std::endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}