#include <bits/stdc++.h>

const int MAXN = 100;

void solve() {
    int n;
    scanf("%d", &n);
 
    static int a[MAXN + 1], cnt[MAXN + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    auto check = [&](int limit) {
        if (limit == 0) return true;

        static int tmp[MAXN + 1];
        for (int i = 1; i <= n; i++) tmp[i] = cnt[i];

        int l = 1, r = limit;
        while (l <= n && r >= 1) {
            bool flag = false;
            while (r > limit) r--;
            while (!tmp[r] && r >= 1) r--;
            if (tmp[r]) tmp[r]--, flag = true;
            while (!tmp[l] && l <= n) l++;
            if (tmp[l]) tmp[l]--;
            limit--;
            if (limit == 0 && flag) return true;
        }

        return false;
    };

    int l = 0, r = n, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }

    printf("%d\n", ans);
}
 
int main() {
    int t;
 
    scanf("%d", &t);
 
    while (t--) solve();
 
    return 0;
}