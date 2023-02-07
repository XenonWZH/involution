#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int MAXN = 1000;

struct Node {
    int a, b;
    bool operator<(const Node &o) const { return a * b < o.a * o.b; }
} N[MAXN + 1];

struct BigInt {
    static const int BASE = 10;
    static const int WIDTH = 5000;

    std::vector<int> s;

    BigInt(long long num = 0) { *this = num; }

    BigInt operator=(long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }

    bool operator<(const BigInt &o) const {
        if (s.size() != o.s.size()) return s.size() < o.s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != o.s[i]) {
                return s[i] < o.s[i];
            }
        }
        return false;
    }
};

std::ostream& operator<<(std::ostream &out, const BigInt &x) {
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--) {
        out << x.s[i];
    }
    return out;
}

BigInt operator*(BigInt a, int b) {
    BigInt c;
    int m = a.s.size();
    c.s.resize(m + 10);
    for (int i = 0; i < m + 10; i++) {
        if (i < m) c.s[i] += a.s[i] * b;
        if (c.s[i] > BigInt::BASE) {
            c.s[i + 1] += c.s[i] / BigInt::BASE;
            c.s[i] %= BigInt::BASE;
        }
    }
    while (!c.s.empty() && c.s.back() == 0) c.s.pop_back();
    return c;
}

BigInt operator/(BigInt a, int b) {
    BigInt c;
    int m = a.s.size();
    c.s.resize(m);
    int remain = 0;
    for (int i = m - 1; i >= 0; i--) {
        remain = remain * BigInt::BASE + a.s[i];
        c.s[i] = remain / b;
        remain %= b;
    }
    while (!c.s.empty() && c.s.back() == 0) c.s.pop_back();
    return c;
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; i++) scanf("%d %d", &N[i].a, &N[i].b);

    std::sort(N + 1, N + n + 1);

    BigInt ans = 0, mul = a;
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, mul / N[i].b);
        mul = mul * N[i].a;
    }

    std::cout << ans << '\n';

    return 0;
}