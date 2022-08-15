#include <cstdio>
#include <cstring>
#include <deque>

const int MAXN = 4000;

template <typename T>
struct MonotoneQueue {
    std::deque<T> q, m;

    void push(const T &x) {
        q.push_back(x);
        while (!m.empty() && m.back() < x) m.pop_back();
        m.push_back(x);
    }

    void pop() {
        T x = q.front();
        q.pop_front();
        if (x == m.front()) m.pop_front();
    }

    size_t size() {
        return q.size();
    }

    T top() {
        return m.front();
    }
};

int main() {
    int n, m, k, t;
    static int board[MAXN + 1][MAXN + 1];

    scanf("%d %d %d %d", &n, &m, &k, &t);

    memset(board, 0, sizeof(board));
    for (int i = 1; i <= k; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        board[x][y] = v;
    }

    static int f[MAXN + 1][MAXN + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++) f[1][i] = board[1][i];

    for (int i = 2; i <= n; i++) {
        MonotoneQueue<std::pair<int, int>> q;
        for (int j = 1; j <= std::min(1 + t, m) - 1; j++) q.push(std::make_pair(f[i - 1][j], j));

        for (int j = 1; j <= m; j++) {
            if (j + t <= m) q.push(std::make_pair(f[i - 1][j + t], j + t));
            while (q.top().second < j - t) q.pop();

            f[i][j] = q.top().first + board[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) ans = std::max(ans, f[n][i]);
    printf("%d\n", ans);

    return 0;
}