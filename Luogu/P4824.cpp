#include <cstdio>
#include <cstring>
#include <queue>

const int MAXN = 1e6;

int main() {
    static char a[MAXN + 2], b[MAXN + 2];
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);

    static int nxt[MAXN + 1];
    nxt[0] = nxt[1] = 0;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && b[i] != b[j + 1]) j = nxt[j];
        if (b[i] == b[j + 1]) j++;
        nxt[i] = j;
    }

    std::deque<int> f;
    std::deque<char> ch;
    for (int i = 1, j = 0; i <= n; i++) {
        ch.push_back(a[i]);
        while (j && a[i] != b[j + 1]) j = nxt[j];
        if (a[i] == b[j + 1]) j++;
        f.push_back(j);
        if (f.back() == m) {
            for (int k = 1; k <= m; k++) {
                f.pop_back();
                ch.pop_back();
            }
            j = f.empty() ? 0 : f.back();
        }
    }

    while (!ch.empty()) {
        putchar(ch.front());
        ch.pop_front();
    }
    puts("");

    return 0;
}