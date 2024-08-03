#include <bits/stdc++.h>
#include <cmath>

namespace XenonWZH {
int main() {
    int h1, d1, t1;
    int h2, d2, t2;
    scanf("%d %d %d", &h1, &d1, &t1);
    scanf("%d %d %d", &h2, &d2, &t2);

    t1 *= 2, t2 *= 2;
    bool fire1 = false, fire2 = false;
    int r1 = 0, r2 = 0, t = 0;

    while (h1 > 0 && h2 > 0) {
        t++;

        if (t == 1) {
            r1 = r2 = 1;
            fire1 = fire2 = true;
        } else {
            if (fire1) {
                h2 -= d1;
                fire1 = false;
            }
            if (fire2) {
                h1 -= d2;
                fire2 = false;
            }

            if (h1 <= 0 || h2 <= 0) break;

            if (t - r1 >= t1) {
                r1 = t;
                fire1 = true;
            }
            if (t - r2 >= t2) {
                r2 = t;
                fire2 = true;
            }
        }
    }

    if (h1 <= 0 && h2 <= 0) puts("draw");
    else if (h1 <= 0) puts("player two");
    else puts("player one");

    return 0;
}
}

int main() {
    return XenonWZH::main();
}