#include<iostream>

typedef long long ll;

const int MAXN = 4300;

int main() {
    int n,p;
    std::cin >> n >> p;

    static ll f[MAXN + 1][MAXN + 1];
    f[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= i; j++) {
            f[i][j] = (f[i][j - 1] + f[i - 1][i - j + 1]) % p;
        }
    }

    ll ans = 0;
    for(int i = 2; i <= n; i++) {
        ans = (ans + f[n][i]) % p;
    }

    std::cout << 2 * ans % p << std::endl;

    return 0;
}