#include <iostream>

long long read(const std::string &s, long long p) {
    long long ans = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        ans = ans * 10 + s[i] - '0';
        ans %= p;
    }
    return ans;
}

long long phi(long long a) {
    long long ans = a;
    for (long long i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            ans = ans / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) ans = ans / a * (a - 1);
    return ans;
}

long long pow(long long a, long long k, long long p) {
    long long ans = 1;
    for (; k; k >>= 1, a = a * a % p) if (k & 1) ans = ans * a % p;
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string bIn, nIn;
    long long c;
    std::cin >> bIn >> nIn >> c;

    long long b = read(bIn, c), n = read(nIn, 1e9), p = phi(c);
    long long k;
    if (n > p || nIn.length() > 9) k = (read(nIn, p) - 1 + p) % p + p;
    else k = n - 1;
    long long ans = (b - 1 + c) % c * pow(b, k, c) % c;

    std::cout << (ans ? ans : c) << '\n';

    return 0;
}