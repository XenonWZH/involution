#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

const int MAXN = 1e6;

struct Node {
    std::vector<struct Edge> e;
    int d;
    bool v;
} N[MAXN + 2];

struct Edge {
    int s, t;
    int w;

    Edge(int s, int t, int w) : s(s), t(t), w(w) {}
};

int n;

inline void addEdge(int s, int t, int w) {
    N[s].e.push_back(Edge(s, t, w));
}

inline int dijkstra(const int s, const int t) {
    for (int i = 0; i <= n + 1; i++) N[i].d = INT_MAX;

    static std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > q;
    N[s].d = 0;
    q.push(std::make_pair(0, s));

    while (!q.empty()) {
        std::pair<int, int> p = q.top();
        q.pop();

        int v = p.second;
        if (N[v].v) continue;
        N[v].v = true;

        for (Edge &e : N[v].e) {
            if (N[e.t].d > N[v].d + e.w) {
                N[e.t].d = N[v].d + e.w;
                q.push(std::make_pair(N[e.t].d, e.t));
            }
        }
    }

    return N[t].d;
}

struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
    IO() : p1(buf), p2(buf), pp(pbuf) {}

    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
    inline char gc() {
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }

    template <class T>
    inline void read(T &x) {
        double tmp = 1;
        bool sign = 0;
        x = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
    }

    inline void read(char *s) {
        char ch = gc();
        for (; blank(ch); ch = gc()) continue;
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }

    inline void read(char &c) {
        for (c = gc(); blank(c); c = gc()) continue;
    }

    inline void push(const char &c) {
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
    }

    template <class T>
    inline void write(T x) {
        if (x < 0) x = -x, push('-');
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }

    template <class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    }
} io;

int main() {
    io.read(n);

    for (int i = 1; i <= n; i++) {
        int a;
        io.read(a);
        if (i + a <= n) addEdge(i, i + a + 1, 0);
        else addEdge(i, n + 1, i + a - n);
        if (i > 1) {
            addEdge(i, i + 1, 1);
            addEdge(i, i - 1, 1);
        }
    }

    io.write(dijkstra(1, n + 1), '\n');

    return 0;
}