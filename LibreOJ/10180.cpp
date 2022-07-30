#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>

const int MAXN = 2e5;

template <typename T>
struct MonotoneQueue {
    std::deque<T> q, m;

    void push(const T &x) {
        q.push_back(x);
        while (!m.empty() && m.back() > x) m.pop_back();
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
    int n, m;
    static int a[MAXN];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    static int f[MAXN];
    static MonotoneQueue< std::pair<int, int> > mq;
    for (int i = 0; i < m; i++) {
        f[i] = a[i];
        mq.push( std::make_pair(f[i], i) );
    }

    for (int i = m; i < n; i++) {
        f[i] = INT_MAX;
        while (mq.size() > 0 && mq.top().second < i - m) mq.pop();
        f[i] = mq.top().first + a[i];
        mq.push( std::make_pair(f[i], i) );
    }

    int ans = INT_MAX;
    for (int i = std::max(0, n - m); i < n; i++) {
        ans = std::min(ans, f[i]);
    }

    printf("%d\n", ans);

    return 0;
}