#include <bits/stdc++.h>

namespace XenonWZH {
    void solve() {
        int l, r;
        scanf("%d %d", &l, &r);

        int t = 0, rr = r;
        for (;; t++) {
            if (rr & (1 << t)) rr -= (1 << t);
            if (rr == 0) break;
        }
        t++;

        int n = 1;
        bool diff = false;
        std::vector<std::vector<std::pair<int, int>>> G(110);
        int lp = 0, mp = 0, rp = 0;
        for (int i = t - 1; i >= 0; i--) {
            if (!diff) {
                if (((l >> i) & 1) == ((r >> i) & 1)) {
                    G[n].emplace_back(n + 1, ((l >> i) & 1));
                    n++;
                } else {
                    diff = true;
                    if (i == 0) {
                        G[n].emplace_back(n + 1, 0);
                        G[n].emplace_back(n + 1, 1);
                        n++;
                    } else {
                        G[n].emplace_back(n + 1, 1);
                        rp = n + 1;
                        if (n == 1) {
                            lp = 1, n++;
                        } else {
                            G[n].emplace_back(n + 2, 0);
                            lp = n + 2, n += 2;
                        }
                    }
                }
            } else {
                if (i == 0) {
                    if (mp) {
                        G[mp].emplace_back(n + 1, 0);
                        G[mp].emplace_back(n + 1, 1);
                    }
                    G[lp].emplace_back(n + 1, ((l >> i) & 1));
                    if (((l >> i) & 1) == 0) G[lp].emplace_back(n + 1, 1);
                    G[rp].emplace_back(n + 1, ((r >> i) & 1));
                    if (((r >> i) & 1) == 1) G[rp].emplace_back(n + 1, 0);
                    n++;
                } else {
                    if (mp) {
                        G[mp].emplace_back(n + 1, 0);
                        G[mp].emplace_back(n + 1, 1);
                        mp = n + 1;
                        n++;
                    }
                    if (lp == 1) {
                        if (((l >> i) & 1) == 1) {
                            G[lp].emplace_back(n + 1, 1);
                            lp = n + 1;
                            n++;
                        } else {
                            if (mp) {
                                G[lp].emplace_back(mp, 1);
                            } else {
                                mp = n + 1;
                                G[lp].emplace_back(mp, 1);
                                n++;
                            }
                        }
                    } else {
                        G[lp].emplace_back(n + 1, ((l >> i) & 1));
                        if (((l >> i) & 1) == 0) {
                            if (mp) {
                                G[lp].emplace_back(mp, 1);
                                lp = n + 1;
                            } else {
                                mp = n + 2;
                                G[lp].emplace_back(mp, 1);
                                lp = n + 1;
                                n++;
                            }
                        } else lp = n + 1;
                        n++;
                    }
                    G[rp].emplace_back(n + 1, ((r >> i) & 1));
                    if (((r >> i) & 1) == 1) {
                        if (mp) {
                            G[rp].emplace_back(mp, 0);
                            rp = n + 1;
                        } else {
                            mp = n + 2;
                            G[rp].emplace_back(mp, 0);
                            rp = n + 1;
                            n++;
                        }
                    } else rp = n + 1;
                    n++;
                }
            }
        }

        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
            printf("%zu ", G[i].size());
            for (auto [v, b] : G[i]) printf("%d %d ", v, b);
            puts("");
        }
    }

    int main() {
        int t = 1;

        while (t--) solve();

        return 0;
    }
};

int main() {
    return XenonWZH::main();
}