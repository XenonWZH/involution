// 196. 质数距离
// WzhDnwzWzh

#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 1000000;
typedef unsigned long long ull;

int main() {
    int l, r;

    while (std::cin >> l >> r) {
        if (l < 2) l = 2;
        if (r < 2) {
            std::cout << "There are no adjacent primes." << std::endl;
            continue;
        }

        static bool v[1 << 16];
        memset(v, true, sizeof(v));

        for (int i = 2; i <= sqrt(r); i++) {
            if (!v[i]) continue;
            for (int j = 2; j <= sqrt(r) / i; j++) v[i * j] = false;
        }

        int n = -1, m = -1;
        int minn = MAXN + 1, nMin[2], maxn = 0, nMax[2];
        bool ansV[MAXN];
        memset(ansV, true, sizeof(ansV));

        for (int i = 2; i <= sqrt(r); i++)
            if (v[i])
                for (int j = std::max(l / i, 2); j <= r / i; j++)
                    if (i * j >= l) ansV[i * j - l] = false;
        for (ull i = l; i <= r; i++) {
            if (ansV[i - l]) {
                n = m;
                m = i;
                if (n != -1 && m - n < minn) {
                    minn = m - n;
                    nMin[0] = n, nMin[1] = m;
                }
                if (n != -1 && m - n > maxn) {
                    maxn = m - n;
                    nMax[0] = n, nMax[1] = m;
                }
            }
        }

        if (n == -1) std::cout << "There are no adjacent primes." << std::endl;
        else std::cout << nMin[0] << "," << nMin[1] << " are closest, "
                       << nMax[0] << "," << nMax[1] << " are most distant." << std::endl;
    }

    return 0;
}