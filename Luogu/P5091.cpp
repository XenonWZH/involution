#include <cstdio>
#include <queue>

void read(std::queue<int> &a) {
    char ch = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        a.push(ch - '0');
        ch = getchar();
    }
}

int phi(int a) {
    int ans = a;
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            ans = ans / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) ans = ans / a * (a - 1);
    return ans;
}

long long pow(long long a, long long b, long long p) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % p) if (b & 1) ans = ans * a % p;
    return ans;
}

int main() {
    int a, m;
    std::queue<int> q;
    scanf("%d %d", &a, &m);
    read(q);

    if (q.size() > 8) {
        int p = phi(m);
        long long b = 0;
        while (!q.empty()) {
            b = (b * 10 + q.front()) % p;
            q.pop();
        }
        printf("%lld\n", pow(a, b + p, m));
    } else {
        long long b = 0;
        while (!q.empty()) {
            b = b * 10 + q.front();
            q.pop();
        }
        printf("%lld\n", pow(a, b, m));
    }

    return 0;
}