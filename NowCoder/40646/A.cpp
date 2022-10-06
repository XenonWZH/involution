#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 1e5;

struct BigInt {
    static const int MAXM = 1000;

    std::vector<int> v;

    BigInt(const int n = 0) { *this = n; }

    BigInt &operator=(int x) {
        v.clear();
        do v.push_back(x % 10); while (x /= 10);
        return *this;
    }

    BigInt &read() {
        char s[MAXN + 1];
        scanf("%s", s);
        int len = strlen(s);
        v.resize(len);
        for (size_t i = 0; i < len; i++) v[i] = s[i] - '0';
        return *this;
    }

    void print() {
        for (int i = v.size() - 1; i >= 0; i--) printf("%d", v[i]);
        putchar('\n');
    }
};

BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt res;
    res.v.clear();
    bool flag = false;
    for (size_t i = 0; i < std::max(a.v.size(), b.v.size()); i++) {
        int t = 0;
        if (i < a.v.size()) t += a.v[i];
        if (i < b.v.size()) t += b.v[i];
        if (flag) t++, flag = false;
        if (t >= 10) t -= 10, flag = true;
        res.v.push_back(t);
    }
    if (flag) res.v.push_back(1);
    return res;
}

BigInt &operator+=(BigInt &a, const BigInt &b) {
    return a = a + b;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt res;
    res.v.resize(a.v.size() + b.v.size() + 1);
    for (size_t i = 0; i < a.v.size(); i++) {
        for (size_t j = 0; j < b.v.size(); j++) {
            res.v[i + j] += a.v[i] * b.v[j];
            res.v[i + j + 1] += res.v[i + j] / 10;
            res.v[i + j] %= 10;
        }
    }
    while (res.v.size() > 1 && res.v.back() == 0) res.v.pop_back();
    return res;
}

struct Node {
    std::vector<struct Edge> adj;
    int cnt;
} N[MAXN + 1];

struct Edge {
    Node *s, *t;
    BigInt w;

    Edge(Node *s, Node *t, BigInt w) : s(s), t(t), w(w) {}
};

inline void addEdge(int u, int v, BigInt w) {
    N[u].adj.push_back(Edge(&N[u], &N[v], w));
    N[v].adj.push_back(Edge(&N[v], &N[u], w));
}

std::pair<BigInt, int> dfs(Node *u, Node *fa = nullptr) {
    BigInt val = 0;
    int cnt = u->cnt;

    for (Edge e : u->adj) {
        if (e.t == fa) continue;
        std::pair<BigInt, int> res = dfs(e.t, u);
        res.first += std::abs(res.second) * e.w;
        val += res.first, cnt += res.second;
    }

    return std::make_pair(val, cnt);
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int s;
        scanf("%d", &s);
        N[s].cnt++;
    }
    for (int i = 1; i <= m; i++) {
        int t;
        scanf("%d", &t);
        N[t].cnt--;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        BigInt w;
        scanf("%d %d", &u, &v);
        w.read();
        addEdge(u, v, w);
    }

    dfs(&N[1]).first.print();

    return 0;
}