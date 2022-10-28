#include <cstdio>
#include <vector>

const int MAXN = 1e6;

bool isNotPrime[MAXN + 1];
int mu[MAXN + 1], phi[MAXN + 1], cnt;
std::vector<int> primes;
int ans[MAXN + 1];

inline void prepare() {
    isNotPrime[0] = isNotPrime[1] = true;
    mu[1] = phi[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (!isNotPrime[i]) {
            cnt++;
            primes.push_back(i);
            mu[i] = -1;
            phi[i] = i - 1;
        }

        for (int j = 0; j < cnt; j++) {
            int t = i * primes[j];
            if (t > MAXN) break;

            isNotPrime[t] = true;

            if (i % primes[j] == 0) {
                mu[t] = 0;
                phi[t] = phi[i] * primes[j];
                break;
            } else {
                mu[t] = -mu[i];
                phi[t] = phi[i] * (primes[j] - 1);
            }
        }
    }

    ans[0] = 0;
    for (int i = 1; i <= MAXN; i++) ans[i] = ans[i - 1] + !isNotPrime[i];
}

int main() {
    prepare();

    int n, m;
    scanf("%d %d", &n, &m);

    while (n--) {
        int l, r;
        scanf("%d %d", &l, &r);

        if (l < 1 || l > m || r < 1 || r > m) puts("Crossing the line");
        else if (l > r) puts("0");
        else printf("%d\n", ans[r] - ans[l - 1]);
    }

    return 0;
}