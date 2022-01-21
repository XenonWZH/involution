#include <cstdio>
#include <algorithm>
#include <map>

const int MAXN = 2e5;

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        static int p[MAXN];
        static char str[MAXN + 1];

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        scanf("%s", str);

        static int like[MAXN], dislike[MAXN];
        int likeLen = 0, disLen = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') dislike[disLen++] = p[i];
            else like[likeLen++] = p[i];
        }

        std::sort(like, like + likeLen);
        std::sort(dislike, dislike + disLen);

        static std::map<int, int> maps;
        maps.clear();
        for (int i = 0; i < likeLen; i++) maps[like[i]] = i + 1 + disLen;
        for (int i = 0; i < disLen; i++) maps[dislike[i]] = i + 1;

        for (int i = 0; i < n; i++) {
            printf("%d ", maps[p[i]]);
        }
        puts("");
    }

    return 0;
}