// P3912 素数个数
// WzhDnwzWzh

#include <cstring>
#include <cstdio>

const int MAXN = 100000000;

int main() {
    int n;

    scanf("%d", &n);

    static bool a[MAXN + 1];
    memset(a, true, sizeof(a));

    for (int i = 2; i * i <= n; i++) {
        if (a[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (a[j]) a[j] = false;
            } 
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i]) ans++;
    }

    printf("%d\n", ans);

    return 0;
}