#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int MAXN = 2000, INF = 0x3f3f3f3f;

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

    bool empty() {
        return m.empty();
    }

    T top() {
        return m.front();
    }
};

int main() {
    int t, maxp, w;
    static int ap[MAXN + 1], bp[MAXN + 1], as[MAXN + 1], bs[MAXN + 1];

    scanf("%d %d %d", &t, &maxp, &w);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d %d", &ap[i], &bp[i], &as[i], &bs[i]);
    }

    static int f[MAXN + 1][MAXN + 1];
    memset(f, 0xcf, sizeof(f));

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= as[i]; j++) f[i][j] = -ap[i] * j;
        for (int j = 0; j <= maxp; j++) f[i][j] = std::max(f[i][j], f[i - 1][j]);

        MonotoneQueue< std::pair<int, int> > buy, sell;
        while (!buy.empty()) buy.pop();
        while (!sell.empty()) sell.pop();

        if (i - w - 1 >= 0) {
            for (int j = 0; j <= maxp; j++) {
                while (!buy.empty() && buy.top().second < j - as[i]) buy.pop();
                buy.push( std::make_pair(f[i - w - 1][j] + j * ap[i], j) );
                f[i][j] = std::max(f[i][j], buy.top().first - j * ap[i]);
            }

            for (int j = maxp; j >= 0; j--) {
                while (!sell.empty() && sell.top().second > j + bs[i]) sell.pop();
                sell.push( std::make_pair(f[i - w - 1][j] + j * bp[i], j) );
                f[i][j] = std::max(f[i][j], sell.top().first - j * bp[i]);
            }
        }
    }

    int ans = -INF;
    for (int i = 0; i <= maxp; i++) ans = std::max(ans, f[t][i]);

    printf("%d\n", ans);

    return 0;
}