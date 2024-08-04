#include <bits/stdc++.h>

namespace XenonWZH {
int cnt = 1;
std::vector<int> ans1, ans2, ans3;

void build(int p, int a, int b) {
    if (a == 0 && b % 2 == 0) {
        puts("-1");
        exit(0);
    }

    if (a == 1 && b == 0) {
        ans1[p] = 1, ans2[p] = ans3[p] = 0;
        return;
    }
    if (a == 0 && b == 1) {
        ans1[p] = 2, ans2[p] = ans3[p] = 0;
        return;
    }

    int lc, rc;

    if (b) {
        if (a == 0) {
            ans1[p] = 2;
            lc = ++cnt;
            rc = ++cnt;
            ans2[p] = lc, ans3[p] = rc;
            build(lc, a, (b - 1) / 2);
            build(rc, a, (b - 1) / 2);
        } else {
            ans1[p] = 2;
            b--;
            if (b) {
                lc = ++cnt;
                rc = ++cnt;
                ans2[p] = lc, ans3[p] = rc;
                if (b % 2 == 0) {
                    build(lc, a / 2, b / 2);
                    build(rc, a - a / 2, b / 2);
                } else {
                    if (a % 2 == 0) {
                        build(lc, a / 2 - 1, b / 2 + 1);
                        build(rc, a / 2 + 1, b / 2);
                    } else {
                        build(lc, a / 2, b / 2 + 1);
                        build(rc, a / 2 + 1, b / 2);
                    }
                }
            } else {
                if (a == 1) {
                    lc = ++cnt;
                    ans2[p] = lc, ans3[p] = 0;
                    build(lc, a, b);
                } else {
                    lc = ++cnt;
                    rc = ++cnt;
                    ans2[p] = lc, ans3[p] = rc;
                    build(lc, a / 2, b);
                    build(rc, a - a / 2, b);
                }
            }
        }
    } else {
        if (a == 2) {
            lc = ++cnt;
            ans1[p] = 1, ans2[p] = lc, ans3[p] = 0;
            build(lc, a - 1, b);
        } else {
            lc = ++cnt;
            rc = ++cnt;
            ans1[p] = 1, ans2[p] = lc, ans3[p] = rc;
            build(lc, (a - 1) / 2, b);
            build(rc, a - 1 - (a - 1) / 2, b);
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    ans1.resize(a + b + 1);
    ans2.resize(a + b + 1);
    ans3.resize(a + b + 1);
    build(1, a, b);

    for (int i = 1; i <= a + b; i++) printf("%d %d %d\n", ans1[i], ans2[i], ans3[i]);

    return 0;
}
}

int main() {
    return XenonWZH::main();
}