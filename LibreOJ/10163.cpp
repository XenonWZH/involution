#include <cstdio>
#include <vector>

const int MAXN = 31;

int k, b;
int f[MAXN + 1][MAXN + 1];

inline void prepare() {
    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i- 1][j - 1];
        }
    }
}

int dp(int n) {
    if (n == 0) return 0;

    std::vector<int> nums;
    while (n) {
        nums.push_back(n % b);
        n /= b;
    }

    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        if (x) {
            res += f[i][k - last];
            if (x > 1) {
                if (k - last - 1 > 0) res += f[i][k - last - 1];
                break;
            } else {
                last++;
                if (last > k) break;
            }
        }
        if (i == 0 && last == k) res++;
    }

    return res;
}

int main() {
    prepare();

    int l, r;

    scanf("%d %d", &l, &r);
    scanf("%d", &k);
    scanf("%d", &b);

    printf("%d\n", dp(r) - dp(l - 1));

    return 0;
}