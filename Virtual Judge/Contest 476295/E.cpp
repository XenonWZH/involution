// E - 瑞士轮
// XenonWZH

#include <iostream>
#include <algorithm>

const int MAXN = 200000;

struct Node {
    int score, id;
} s[MAXN + 1], win[MAXN + 1], lose[MAXN + 1];

bool cmp(Node a, Node b) {
    if (a.score == b.score)
        return a.id < b.id;
    return a.score > b.score;
}

int main() {
    int n, r, q, w[MAXN + 1], lenWin, lenLose;

    std::cin >> n >> r >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[2 * i - 1].score >> s[2 * i].score;
        s[2 * i - 1].id = 2 * i - 1;
        s[2 * i].id = 2 * i;
    }
    for (int i = 1; i <= n; i++)
        std::cin >> w[2 * i - 1] >> w[2 * i];

    std::sort(s + 1, s + 2 * n + 1, cmp);
    for (int i = 0; i < r; i++) {
        lenWin = lenLose = 0;
        for (int j = 1; j <= n; j++) {
            if (w[ s[2 * j - 1].id ] > w[ s[2 * j].id ]) {
                s[2 * j - 1].score++;
                win[lenWin++] = s[2 * j - 1];
                lose[lenLose++] = s[2 * j];
            }
            else {
                s[2 * j].score++;
                win[lenWin++] = s[2 * j];
                lose[lenLose++] = s[2 * j - 1];
            }
        }
        std::merge(win, win + lenWin, lose, lose + lenLose, s + 1, cmp);
    }

    std::cout << s[q].id << std::endl;
    return 0;
}