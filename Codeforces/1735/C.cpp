#include <cstdio>
#include <iostream>
#include <map>
#include <set>

const int MAXN = 2e5;

struct UnionFindSet {
    int fa[100], size[100];

    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
    }

    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

    void merge(int x, int y) { fa[find(x)] = find(y); }
} ufs;

void solve() {
    int n;
    static char s[MAXN + 2];

    scanf("%d", &n);
    scanf("%s", s + 1);

    std::map<char, char> mp;
    std::set<char> ss;
    for (int i = 'a'; i <= 'z'; i++) ss.insert(i);
    ufs.init(26);

    for (int i = 1; i <= n; i++) {
        if (mp[s[i]]) {
            putchar(mp[s[i]]);
            continue;
        }
        auto it = ss.begin();
        while (*it == s[i] || (ufs.find(*it - 'a' + 1) == ufs.find(s[i] - 'a' + 1) && ufs.size[ufs.find(*it - 'a' + 1)] != 26)) {
            it++;
        }
        putchar(*it);
        int s1 = ufs.find(*it - 'a' + 1), s2 = ufs.find(s[i] - 'a' + 1);
        ufs.merge(*it - 'a' + 1, s[i] - 'a' + 1);
        ufs.size[ufs.find(s[i] - 'a' + 1)] = ufs.size[s1] + ufs.size[s2];
        mp[s[i]] = *it;
        ss.erase(it);
    }
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}