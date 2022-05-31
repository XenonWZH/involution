#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
    char ch[8][4];

    scanf("%c%c%c%c:%c%c%c%c:%c%c%c%c:%c%c%c%c:\
%c%c%c%c:%c%c%c%c:%c%c%c%c:%c%c%c%c", &ch[0][0], &ch[0][1], &ch[0][2], &ch[0][3],
                                      &ch[1][0], &ch[1][1], &ch[1][2], &ch[1][3],
                                      &ch[2][0], &ch[2][1], &ch[2][2], &ch[2][3],
                                      &ch[3][0], &ch[3][1], &ch[3][2], &ch[3][3],
                                      &ch[4][0], &ch[4][1], &ch[4][2], &ch[4][3],
                                      &ch[5][0], &ch[5][1], &ch[5][2], &ch[5][3],
                                      &ch[6][0], &ch[6][1], &ch[6][2], &ch[6][3],
                                      &ch[7][0], &ch[7][1], &ch[7][2], &ch[7][3]);

    int begin[8];
    memset(begin, 0, sizeof(begin));
    bool flag = true;

    for (int i = 0; i < 8; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (ch[i][j] != '0') break;
            cnt++;
        }
        begin[i] = cnt;
        if (cnt == 4) flag = false;
    }

    if (flag) {
        for (int i = 0; i < 8; i++) {
            for (int j = begin[i]; j < 4; j++) {
                putchar(ch[i][j]);
            }
            if (i != 7) putchar(':');
        }
        putchar('\n');
        return 0;
    }

    int maxPos = 0, maxn = 0;
    for (int i = 0; i < 8; i++) {
        if (begin[i] != 4) continue;
        int cnt = 0;
        for (int j = i; j < 8; j++) {
            if (begin[j] != 4) break;
            cnt++;
        }
        if (cnt > maxn) maxn = cnt, maxPos = i;
    }

    int pos = 0;
    while (pos < 8) {
        if (pos == maxPos) {
            pos += maxn;
            printf("::");
        } else {
            for (int i = std::min(3, begin[pos]); i < 4; i++) {
                putchar(ch[pos][i]);
            }
            if (pos != 7 && pos + 1 != maxPos) putchar(':');
            pos++;
        }
    }
    putchar('\n');

    return 0;
}