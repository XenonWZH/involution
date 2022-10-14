#include <cstdio>
#include <iostream>
#include <deque>

const int MAXN = 5e5;

void solve() {
    int n;
    static int a[2 * MAXN + 1];
    static char s[2 * MAXN + 1];

    scanf("%d", &n);
    n *= 2, s[n + 1] = '\0';
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int pos;
    for (int i = 2; i <= n; i++) {
        if (a[1] == a[i]) {
            pos = i;
            break;
        }
    }

    int bigL = 2, bigR = n;
    int smallL = pos - 1, smallR = pos + 1;
    int l = 1, r = n;
    s[l] = 'L';
    s[r] = 'L';
    while (true) {
        if (l == r - 1) {
            printf("%s\n", s + 1);
            return;
        }

        if (a[bigL] == a[smallL] && bigL < smallL) {
            s[++l] = 'L';
            s[--r] = 'L';
            bigL++;
            smallL--;
        } else if (a[bigL] == a[smallR]) {
            s[++l] = 'L';
            s[--r] = 'R';
            bigL++;
            smallR++;
        } else if (a[bigR] == a[smallL]) {
            s[++l] = 'R';
            s[--r] = 'L';
            bigR--;
            smallL--;
        } else if (a[bigR] == a[smallR] && bigR > smallR) {
            s[++l] = 'R';
            s[--r] = 'R';
            bigR--;
            smallR++;
        } else break;
    }

    for (int i = 1; i < n; i++) {
        if (a[n] == a[i]) {
            pos = i;
            break;
        }
    }
    bigL = 1;
    bigR = n - 1;
    smallL = pos - 1;
    smallR = pos + 1;
    l = 1, r = n;
    s[l] = 'R';
    s[r] = 'L';
    while (true) {
        if (l == r - 1) {
            printf("%s\n", s + 1);
            return;
        }

        if (a[bigL] == a[smallL] && bigL < smallL) {
            s[++l] = 'L';
            s[--r] = 'L';
            bigL++;
            smallL--;
        } else if (a[bigL] == a[smallR]) {
            s[++l] = 'L';
            s[--r] = 'R';
            bigL++;
            smallR++;
        } else if (a[bigR] == a[smallL]) {
            s[++l] = 'R';
            s[--r] = 'L';
            bigR--;
            smallL--;
        } else if (a[bigR] == a[smallR] && bigR > smallR) {
            s[++l] = 'R';
            s[--r] = 'R';
            bigR--;
            smallR++;
        } else {
            puts("-1");
            return;
        }
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}