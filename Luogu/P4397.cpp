#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MAXS = 100000;

std::vector<int> primes;
std::vector<long long> ans;

inline void getPrimes() {
    static bool isPrime[MAXS + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i <= MAXS; i++) {
        if (!isPrime[i]) continue;
        primes.push_back(i);

        for (int j = i; j <= MAXS / i; j++) isPrime[i * j] = false;
    }
}

inline bool check(long long x) {
    if (x == 1) return 0;

    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(long long remain, int pos, long long s) {
    if (remain == 1) {
        ans.push_back(s);
        return;
    }

    if (check(remain - 1) && remain > primes[pos]) ans.push_back((remain - 1) * s);

    for (int i = pos; (long long)primes[i] *primes[i] <= remain; i++) {
        long long power = primes[i];

        for (long long sum = primes[i] + 1; sum <= remain; power *= primes[i], sum += power) {
            if (remain % sum == 0) {
                dfs(remain / sum, i + 1, s * power);
            }
        }
    }
}

int main() {
    getPrimes();

    long long s;

    while (scanf("%lld", &s) != EOF) {
        ans.clear();

        dfs(s, 0, 1);

        std::sort(ans.begin(), ans.end());

        printf("%d\n", (int)ans.size());

        if (!ans.empty()) {
            for (long long each : ans) {
                printf("%lld ", each);
            }
            putchar('\n');
        }
    }

    return 0;
}