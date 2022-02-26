#include <cstring>
#include <iostream>

long long n;
int p[10], pAns[10], m[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

long long power(long long a, int b) {
    long long ans = 1;
    while (b > 0) {
        if ((b & 1) == 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

long long calcP(int end) {
    long long ans = 1;
    for (int i = 0; i < end; i++) ans *= power(m[i], p[i]);
    return ans;
}

long long sumP() {
    long long ans = 1;
    for (int i = 0; i < 10; i++) ans *= p[i] + 1;
    return ans;
}

long long calcAns(int end) {
    long long ans = 1;
    for (int i = 0; i < end; i++) ans *= power(m[i], pAns[i]);
    return ans;
}

long long sumAns() {
    long long ans = 1;
    for (int i = 0; i < 10; i++) ans *= pAns[i] + 1;
    return ans;
}

void dfs(int step) {
    if (step >= 10) {
        if (sumP() >= sumAns()) {
            if (sumP() > sumAns()) memcpy(pAns, p, sizeof(p));
            else if (calcP(10) < calcAns(10)) memcpy(pAns, p, sizeof(p));
        }
        return;
    }

    long long maxn = calcP(step), before = step == 0 ? (long long) 2e9 : p[step - 1];

    for (long long i = 0; power(m[step], i) * maxn <= n && i <= before; i++) {
        p[step] = i;
        dfs(step + 1);
    }
}

int main() {
    std::cin >> n;

    memset(p, 0, sizeof(p));
    memset(pAns, 0, sizeof(pAns));
    dfs(0);

    std::cout << calcAns(10) << std::endl;

    return 0;
}