#include <cstdio>
#include <algorithm>

const int MAXN = 200000;

int main() {
    int n, m;
    
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        
        static int head[MAXN], coin[MAXN];
        for (int i = 0; i < n; i++) scanf("%d", &head[i]);
        for (int i = 0; i < m; i++) scanf("%d", &coin[i]);
        
        std::sort(head, head + n);
        std::sort(coin, coin + m);
        
        int p = 0;
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            if (coin[i] >= head[p]) {
                ans += coin[i];
                p++;
                if (p == n) break;
            }
        }
        
        if (p < n) puts("Loowater is doomed!");
        else printf("%lld\n", ans);
    }

    return 0;
}