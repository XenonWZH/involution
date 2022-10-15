#include <cstdio>
#include <string>

const int MAXN = 1e6;

long long s[MAXN + 1];

void prepare() {
    std::string str;
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= i; j++) {
            str += std::to_string(i);
            if (str.size() >= MAXN) break;
        }
        if (str.size() >= MAXN) break;
    }
    s[0] = 0;
    for (int i = 1; i <= MAXN; i++) s[i] = s[i - 1] + str[i - 1] - '0';
}

void solve() {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", s[r] - s[l - 1]);
}

int main() {
    prepare();

    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}