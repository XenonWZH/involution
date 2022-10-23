#include <bits/stdc++.h>
 
void solve() {
    int n;
    scanf("%d", &n);
 
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    std::vector<std::pair<int, int>> ans;
    bool flag = true;
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (res == -1) {
                flag = true;
                ans.push_back(std::make_pair(i, i));
            } else flag ^= true;
        } else {
            if (res == -1) {
                flag = true;
                res = i;
            } else {
                if (a[res] + (flag ? -a[i] : a[i]) == 0) {
                    ans.push_back(std::make_pair(res, i));
                    res = -1;
                } else {
                    ans.push_back(std::make_pair(res, res));
                    ans.push_back(std::make_pair(res + 1, i));
                    res = -1;
                }
            }
        }
    }
 
    if (res != -1) {
        puts("-1");
        return;
    }
 
    printf("%zu\n", ans.size());
    for (auto each : ans) {
        printf("%d %d\n", each.first + 1, each.second + 1);
    }
}
 
int main() {
    int t;
 
    scanf("%d", &t);
 
    while (t--) solve();
 
    return 0;
}