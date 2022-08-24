#include <cstdio>
#include <bitset>

const int MAXN = 1000;
const int MAXS = 2000000;

int main() {
    int n;

    scanf("%d", &n);

    int sum = 0;
    static std::bitset<MAXS + 1> f;
    f[0] = 1;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        sum += a;
        f ^= (f << a);
    }

    int ans = 0;
    for (int i = 1; i <= sum; i++) {
        if (f[i]) {
            ans ^= i;
        }
    }

    printf("%d\n", ans);

    return 0;
}
